/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:03:56 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/05 12:06:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstddef>

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
            typedef std::ptrdiff_t difference_type ;
            typedef std::random_access_iterator_tag iterator_category ;
            
            randomAccessIterator();
            randomAccessIterator(T ptr);
            randomAccessIterator( randomAccessIterator &other);
            randomAccessIterator& operator=( randomAccessIterator& other);
            ~randomAccessIterator();
            T& operator*();
            T& operator->();
            
            
            //pre-increment
            randomAccessIterator& operator++();
            // pre-decrement
            randomAccessIterator& operator--();
            // post-increment
            randomAccessIterator operator++(int);
            // post-decrement
            randomAccessIterator operator--(int);

            
            randomAccessIterator operator+(difference_type n);
            randomAccessIterator operator=(T n);
            randomAccessIterator operator-(difference_type n);
            randomAccessIterator& operator+=(difference_type n);
            randomAccessIterator& operator-=(difference_type n);
            
            
            bool operator == (const randomAccessIterator& other);
            bool operator != (const randomAccessIterator& other);
            bool operator < (const randomAccessIterator& other);
            bool operator > (const randomAccessIterator& other);
            bool operator <= (const randomAccessIterator& other);
            bool operator >= (const randomAccessIterator& other);
            
            T & operator[] (int n);
            
    };
}