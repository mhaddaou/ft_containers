/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_iterator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:21:53 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/05 12:03:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/ra_iterator.hpp"


//constructors
template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(): _ptr(NULL){}

template <typename T>
RandomAccessIterator<T>::RandomAccessIterator(T *p) : _ptr(p){}

//destructor
template <typename T>
RandomAccessIterator<T>::~RandomAccessIterator(){}

//overload return operators
template <typename T>
RandomAccessIterator<T> & RandomAccessIterator<T>::operator ++(){
    _ptr++;
    return (*this);
}

template <typename T>
RandomAccessIterator<T> & RandomAccessIterator<T>::operator --(){
    _ptr--;
    return (*this);
}

template <typename T>
RandomAccessIterator<T> & RandomAccessIterator<T>::operator ++(int){
    RandomAccessIterator<T> copy;
    _ptr++;
    return (copy);
}

template <typename T>
RandomAccessIterator<T> & RandomAccessIterator<T>::operator --(int){
    RandomAccessIterator<T> copy;
    _ptr--;
    return (copy);
}

template <typename T>
T & RandomAccessIterator<T>::operator *() const {
    return (*_ptr);
}


template <typename T>
T * RandomAccessIterator<T>::operator ->() const {
    return (_ptr);
}

//overload comparison operators
template <typename T>
bool RandomAccessIterator<T>::operator == (const RandomAccessIterator<T> & other) const{
    return (*this == other);
}

template <typename T>
bool RandomAccessIterator<T>::operator != (const RandomAccessIterator<T> & other) const{
    return (*this != other);
}

template <typename T>
bool RandomAccessIterator<T>::operator < (const RandomAccessIterator<T> & other) const{
    return (*this < other);
}

template <typename T>
bool RandomAccessIterator<T>::operator <= (const RandomAccessIterator<T> & other) const{
    return (*this <= other);
}

template <typename T>
bool RandomAccessIterator<T>::operator > (const RandomAccessIterator<T> & other) const{
    return (*this > other);
}

template <typename T>
bool RandomAccessIterator<T>::operator >= (const RandomAccessIterator<T> & other) const{
    return (*this >= other);
}

