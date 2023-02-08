/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:46:02 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/08 20:51:54 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdlib.h>
#include <string>
#include "ra_iterator.hpp"
#include <sstream>
namespace ft{
      
template<class T,class Allocator = std::allocator<T> > 
class vector 
{
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
        //don't forget to add const inside brackerts of T <const T>
        typedef ft::RandomAccessIterator<const T>  const_iterator;
            
            // deallocate like free
            // destroy like memeset
        // Member functions
        vector(){
            _size = 0;
            _data = NULL;
            _capacity = 0;
            _alloc = Allocator();
        };
        explicit vector( const Allocator& alloc ){
            _size = 0;
            _data = NULL;
            _capacity = 0;
            _alloc = alloc;
        };
        // _data = _alloc.allocate(    number of allocations );
        // vector(count nummber of times , value inserted value count times)
        explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()) :_size(0){
            _capacity = count;
            _alloc = alloc;
            _data = _alloc.allocate( count );
            for(size_type i = 0; i < count; i++){
                _data[i] = value;
                _size++;
            }
        }
        //inserted range of a nother vector  
        template< class InputIt > 
        vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ) : _size(0){
            _alloc = alloc;
            // for (InputIt i = first; i != last; ++i){
            //     _size ++;
            // }
            _size = std::distance(first, last);
            _capacity = _size;
            _data = _alloc.allocate(_size);   
            for(size_t i = 0; i < _size; ++i){
                _alloc.construct(_data + i, *first);
                ++first;
            }
        }
        ~vector() _NOEXCEPT{
            _alloc.deallocate(_data, _size);
            _data = NULL;
        }
        vector( const vector& other ){
            this  = other;
        }
        vector& operator=( const vector& other){
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
            _size = std::distance(first, last);
            _capacity = _size;
            _data = _alloc.allocate(_size);
            for(size_type i = 0; first !=  last; ++i){
                _alloc.construct(_data + i, *first);
                ++first;
            }
        }
        // convert unsigned int to string
        std::string to_str (unsigned int value){
            std::stringstream ss;
            ss << value;
            return ss.str();
        }
        // class 
        allocator_type get_allocator() const{
            return (_alloc);
        }
        // Element access
        reference at( size_type pos ){
            if ( pos >= _size){
                std::string index = to_str(pos);
                throw std::out_of_range( index + " is out of bounds" );
            }
            return (_data[pos]);
            
        }
        const_reference at( size_type pos ) const{
            if (pos >= _size){
                std::string index = to_str(pos);
                throw std::out_of_range( index + " is out of bounds");
            }
            return (_data[pos]);
        }
        reference operator[]( size_type pos ){
            if (pos >= _size){
                std::string index = to_str(pos);
                throw std::out_of_range( index + " is out of bounds");
            }
            return (_data[pos]);
        }
        const_reference operator[]( size_type pos ) const{
            if (pos >= _size){
                std::string index = to_str(pos);
                throw std::out_of_range( index + " is out of bounds");
            }
            return (_data[pos]);
        }
        reference front(){
            if (_size == 0)
                throw std::out_of_range("ft::vector::front: vector is empty");
            return (_data[0]);
        }
        const_reference front() const{
            if (_size == 0)
                throw std::out_of_range("ft::vector::front: vector is empty");
            return (_data[0]);
        }
        reference back(){
            if (_size == 0)
                throw std::out_of_range("ft::vector::back: vector is empty");
            return (_data[_size - 1]);
        }
        const_reference back() const{
            if (_size == 0)
                throw std::out_of_range("ft::vector::back: vector is empty");
            return (_data[_size - 1]);
        }
        T* data(){
            if (_size == 0)
                return NULL;
            return _data;
        }
        const T* data() const{
            if (_size == 0)
                return NULL;
            return _data;
        }
        iterator begin(){
            return (_data);
        }
        iterator end(){
            return (_data + _size);
        }
        const_iterator end() const{
            return (_data + _size);
        }
        // Capacity
        bool empty() const{
            return (_size == 0);
        }
        size_type size() const{
            return (_size);
        }
        size_type max_size() const{
            return _alloc.max_size();
        }
        void reserve( size_type new_cap ){
            if (new_cap <= _size)
                return;
            int free_size = _capacity;
            _capacity = new_cap;
            T* copy;
            copy = _alloc.allocate(_size);
            for(size_type i = 0; i < _size;i++){
                _alloc.construct(copy + i, _data[i]);
            }
            _alloc.deallocate(_data, free_size);
            _data = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; i++){
                _alloc.construct(_data  + i, copy[i]);
            }
            _alloc.deallocate(copy, _size);
        }
        size_type capacity() const{
            return (_capacity);
        }
        // Modifiers
        void clear(){
            _alloc.destroy(_data);
            _size = 0;
        }
        // when you finish inser don't forget to add const to iterator pos
        iterator insert( const_iterator pos, const T& value ){
            // _size++;
            difference_type size_free = _capacity;
            if (_size + 1 > static_cast<size_type> (_capacity))
                _capacity *= 2;    
            T* copy = _alloc.allocate(_capacity);
            int i = 0;
            for(const_iterator it = this->begin();it != pos; it++){
                _alloc.construct(copy + i, *it);
                i++;
            }
            _alloc.construct(copy + i++, value);
            for(; pos != this->end(); pos++){
                _alloc.construct(copy + i, *pos);
                i++;
            }
            _size++;
            _alloc.deallocate(_data, size_free);
            _data  = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; i++){
                _alloc.construct(_data  + i, copy[i]);
            }
            _alloc.deallocate(copy, _capacity);
            return _data;
        }
        iterator insert( const_iterator pos, size_type count, const T& value ){
            difference_type  size_free = _capacity;
            T* copy = _alloc.allocate(_capacity + count);
            int i = 0;
            for(const_iterator it = this->begin();it != pos; it++){
                _alloc.construct(copy + i, *it);
                i++;
            }
            iterator end = this->end();
            for(size_type j = 0; j < count; j++){
                if (_size + 1 > static_cast<size_type> (_capacity))
                    _capacity *= 2;
                _alloc.construct(copy + i, value);
                i++;
                _size++;
            }
            for(; pos != end; pos++){
                _alloc.construct(copy + i, *pos);
                i++;
            }
            _alloc.deallocate(_data, size_free);
            _data  = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; i++){
                _alloc.construct(_data  + i, copy[i]);
            }
            _alloc.deallocate(copy, _capacity);
            return _data;
        }
        // template< class InputIt >
        // iterator insert( const_iterator pos, InputIt first, InputIt last ){
        //     iterator calcul = first;
        //     std::cout << "insert" << std::endl;
        //     // std::cout << 
        //     difference_type count = 0;
        //     last--;
        //     std::cout << *last << std::endl;
        //     exit(0);
        //     for(; calcul != last; calcul++){
        //         count++;
        //         std::cout << count << std::endl;
        //     }
        //     // std::cout << "coutn " << count << std::endl;
        //     // // difference_type size_free = _capacity;
        //     // T* copy = _alloc.allocate(_capacity + count);
        //     // int i = 0;
        //     // for(iterator it = this->begin(); it != pos; it++){
        //     //     _alloc.construct(copy + i, *it);
        //     //     i++;
        //     // }
        //     (void)last;
        //     (void) pos;
        //     (void ) count;
        //     // std::cout << copy[0] << std::endl;
        //     return (_data);
        // }
        iterator erase( iterator pos ){
            T * copy = _alloc.allocate(_capacity);
            int i = 0;
            iterator it = this->begin();
            for(; it != pos; it++){
                _alloc.construct(copy + i, *it);
                i++;
            }
            it++;
            for(; it != this->end(); it++){
                _alloc.construct(copy + i, *it);
                i++;
            }
            
            _size--;
            _alloc.deallocate(_data, _capacity);
            _data  = _alloc.allocate(_capacity);
            for(size_type i = 0; i < _size; i++){
                _alloc.construct(_data  + i, copy[i]);
            }
            _alloc.deallocate(copy, _capacity);
            return (_data);
        }
        // iterator erase( iterator first, iterator last ){
        //     T * copy = _alloc.allocate(_capacity);
        //     int i = 0;
        //     iterator it = this->begin();
        //     for(; it != pos; it++){
        //         _alloc.construct(copy + i, *it);
        //         i++;
        //     }
            
        // }
        
        
        
};
};


#endif