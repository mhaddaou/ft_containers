/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:03:56 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/04 17:25:11 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

namespace ft{
    
    template< class Iter >
    struct iterator_traits{
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };
    template< class T >
    struct iterator_traits<T*>{
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };
    template< class T >
    struct iterator_traits<const T*>{
        typedef ptrdiff_t difference_type;
        typedef T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <typename T>
    class randomAccessIterator{
        private:
            T* _ptr;
        public:
            
            randomAccessIterator();
            randomAccessIterator(T *ptr);
            randomAccessIterator(const randomAccessIterator &other);
            randomAccessIterator& operator=(const randomAccessIterator& other);
            ~randomAccessIterator();
            T& operator*();
            T& operator->();
              random_access_iterator& operator++(){
                _ptr++;
                return *this;
            }
            random_access_iterator operator++(int){
                random_access_iterator tmp(*this);
                operator++();
                return tmp;
            }
            random_access_iterator& operator--(){
                _ptr--;
                return *this;
            }
            random_access_iterator operator--(int){
                random_access_iterator tmp(*this);
                operator--();
                return tmp;
            }
            random_access_iterator operator+(int n){
                return random_access_iterator(_ptr + n);
            }
            random_access_iterator operator-(int n){
                return random_access_iterator(_ptr - n);
            }
            random_access_iterator& operator+=(int n){
                _ptr += n;
                return *this;
            }
            random_access_iterator& operator-=(int n){
                _ptr -= n;
                return *this;
            }
            bool operator==(const random_access_iterator& other){
                return _ptr == other._ptr;
            }
            bool operator!=(const random_access_iterator& other){
                return _ptr != other._ptr;
            }
            bool operator<(const random_access_iterator& other){
                return _ptr < other._ptr;
            }
            bool operator>(const random_access_iterator& other){
                return _ptr > other._ptr;
            }
            bool operator<=(const random_access_iterator& other){
                return _ptr <= other._ptr;
            }
            bool operator>=(const random_access_iterator& other){
                return _ptr >= other._ptr;
            }
            T& operator[](int n){
                return _ptr[n];
            }

            
            
    };
}