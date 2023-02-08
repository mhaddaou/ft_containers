/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:45:59 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/08 17:05:24 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/ra_iterator.hpp"



template <typename T>
ft::RandomAccessIterator<T>::RandomAccessIterator():_ptr(NULL){}

template< typename T >
ft::RandomAccessIterator<T>::RandomAccessIterator(T *ptr):_ptr(ptr){}

template< typename T >
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator++(){
    _ptr++;
    return (*this);
}

template< typename T >
ft::RandomAccessIterator<T>& ft::RandomAccessIterator<T>::operator--(){
    --_ptr;
    return (*this);
}

template <typename T >
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator++(int){
    RandomAccessIterator copy(*this);
    _ptr++;
    return (copy);
}

template <typename T>
ft::RandomAccessIterator<T> ft::RandomAccessIterator<T>::operator--(int){
    RandomAccessIterator tmp(*this);
    _ptr--;
    return tmp;
}

template <typename T>
T & ft::RandomAccessIterator<T>::operator * () const{
    return (*_ptr);
}

template <typename T>
T * ft::RandomAccessIterator<T>::operator->() const{
    return (_ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator == (const RandomAccessIterator & other) const{
    return (_ptr == other._ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator!= (const RandomAccessIterator & other) const{
    return (_ptr!= other._ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator < (const RandomAccessIterator & other) const{
    return (_ptr < other._ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator <= (const RandomAccessIterator & other) const{
    return (_ptr <= other._ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator > (const RandomAccessIterator & other) const{
    return (_ptr > other._ptr);
}

template <typename T>
bool ft::RandomAccessIterator<T>::operator >= (const RandomAccessIterator & other) const{
    return (_ptr >= other._ptr);
}