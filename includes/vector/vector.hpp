/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:46:02 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/06 22:25:07 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
#include "ra_iterator.hpp"
namespace ft{
      
template<class T,class Allocator = std::allocator<T> > 
class Vector{
    private:
        size_t _size;
        T*  _data;
        std::ptrdiff_t _capacity;
        Allocator _alloc;
    public:
        typedef T value_type;
        typedef Allocator  allocator_type;
        typedef size_t size_type;
        typedef typename std::ptrdiff_t    difference_type;
        typedef value_type&     reference;
        typedef const value_type&    const_reference;
        typedef typename Allocator::pointer  pointer;
        typename Allocator::const_pointer    const_pointer;
        typedef ft::RandomAccessIterator<T> iterator;
        typedef typename ft::RandomAccessIterator<const T>  const_iterator;
            
            // deallocate like free
            // destroy like memeset

        Vector(){
            _size = 0;
            _data = NULL;
            _capacity = 0;
            _alloc = Allocator();
        };
        explicit Vector( const Allocator& alloc ){
            _size = 0;
            _data = NULL;
            _capacity = 0;
            _alloc = alloc;
        };
        // _data = _alloc.allocate(    number of allocations );
        // Vector(count nummber of times , value inserted value count times)
        explicit Vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :_size(0){
            _capacity = count;
            _alloc = alloc;
            _data = _alloc.allocate( count );
            for(size_type i = 0; i < count; i++){
                _data[i] = value;
                _size++;
            }
        }
        //inserted range of a nother Vector  
        template< class InputIt > 
        Vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ) : _size(0){
            _alloc = alloc;
            // for (InputIt i = first; i != last; ++i){
            //     _size ++;
            // }
            _size = std::distance(first, last);
            _capacity = _size;
            _data = _alloc.allocate(_size);
            std::cout << _size << std::endl;    
            for(size_t i = 0; i < _size; ++i){
                _alloc.construct(_data + i, *first);
                ++first;
            }
        }
        ~Vector(){
            _alloc.deallocate(_data, _size);
            _data = NULL;
        }
        Vector( const Vector& other ){
            this  = other;
        }
        Vector& operator=( const Vector& other){
            _size = other._size;
            _capacity = other._capacity;
            _alloc = other._alloc;
            _data = _alloc.allocate(_size);
            for(size_t i = 0; i < _size; ++i){
                _data[i] = other._data[i];
            }    
        }
        void assign( size_type count, const T& value ){
            if (_size == count){
                for(size_t i = 0; i < _size; ++i){
                    _data[i] = value;
                }
            }
            else{
                _alloc.deallocate(_data, _size);
                _size = count;
                _data = _alloc.allocate(_size);
                _capacity = count;
                for(size_t i = 0; i < _size; ++i){
                    _data[i] = value;
                }
            }
        }
        template< class InputIt >
        void assign( InputIt first, InputIt last ){
            
        }
    };
    
};

#endif