/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:09:12 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/05 10:36:46 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RA_ITERATOR_HPP
#define RA_ITERATOR_HPP

#include <iostream>
#include <algorithm>
#include <string>

template <typename T>
class  RandomAccessIterator{
    public:
        //typedefs
        typedef T value_type;
        typedef T& reference;
        typedef T* pointer;
        typedef std::ptrdiff_t difference_type;
        typedef std::random_access_iterator_tag iterator_category;
        
        //constructors
        RandomAccessIterator();
        RandomAccessIterator(T *p);
        
        //destructor
        ~RandomAccessIterator();

        //overload return operators
        RandomAccessIterator & operator ++();
        RandomAccessIterator & operator --();
        RandomAccessIterator & operator ++(int);
        RandomAccessIterator & operator --(int);
        T &operator *() const;
        T* operator ->() const;

        //overload comparison operators
        bool operator == (const RandomAccessIterator& other) const;
        bool operator != (const RandomAccessIterator& other) const;
        bool operator < (const RandomAccessIterator& other) const;
        bool operator <=(const RandomAccessIterator& other) const;
        bool operator > (const RandomAccessIterator& other) const;
        bool operator >=(const RandomAccessIterator& other) const;
        
    private:
        T* _ptr;
    
};

#endif