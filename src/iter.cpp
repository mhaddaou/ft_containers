/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:04:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/05 12:07:07 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

namespace ft{
    // typedef ptrdiff_t difference_type;
    template <typename T>
    randomAccessIterator<T>::randomAccessIterator() : _ptr(NULL){
        std::cout << "randomAccessIterator" << std::endl;
    }

    template <typename T>
    randomAccessIterator<T>::randomAccessIterator(T ptr) : _ptr(ptr){}
    template <typename T>
    randomAccessIterator<T>::randomAccessIterator( randomAccessIterator &other){
        this = other;
        return (*this);
    }
    
    template <typename T>
    randomAccessIterator<T> & randomAccessIterator<T>::operator=( randomAccessIterator &other){
        _ptr = other._ptr;
        return (*this);
    }

    template <typename T>
    randomAccessIterator<T>::~randomAccessIterator(){}
    
    template <typename T>
    T & randomAccessIterator<T>::operator*(){
        return (*_ptr);
    }
    
    template <typename T>
    T& randomAccessIterator<T>::operator->(){
        return(_ptr);
    }
    
    //pre-increment
    template <typename T>   
    randomAccessIterator<T>& randomAccessIterator<T>::operator++(){
        _ptr++;
        return (*this);
    }
    
    // pre-decrement
    template < typename T > 
    randomAccessIterator<T> & randomAccessIterator<T>::operator--(){
        _ptr--;
        return (*this);
    }
    
    // post-increment
    template <typename T>
    randomAccessIterator<T>  randomAccessIterator<T>::operator++(int){
        randomAccessIterator<T> copy(*this);
        _ptr++;
        return (copy);
    }

    // post-decrement
    template <typename T>
    randomAccessIterator<T> randomAccessIterator<T>::operator--(int){
        randomAccessIterator<T> copy(*this);
        _ptr--;
        return (copy);
    }
    
    template< typename T >
    randomAccessIterator<T> randomAccessIterator<T>::operator+(difference_type n){
        return (randomAccessIterator(_ptr + n));
    }
    template< typename T >
    randomAccessIterator<T>  randomAccessIterator<T>::operator=(T n){
        _ptr = n;
        return (*this);
    }
    template< typename T >
    randomAccessIterator<T> randomAccessIterator<T>::operator-(difference_type n){
        return (randomAccessIterator(_ptr - n));
    }
    
    template< typename T >
    randomAccessIterator<T>& randomAccessIterator<T>::operator+=(difference_type n){
        _ptr += n;
        return (*this);
    }
    
    template <typename T >
    randomAccessIterator<T>& randomAccessIterator<T>::operator-=(difference_type n){
        _ptr -= n;
        return (*this);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator == (const randomAccessIterator<T> & other){
        return (_ptr == other._ptr);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator!= (const randomAccessIterator<T> & other){
        return (_ptr!= other._ptr);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator > (const randomAccessIterator<T> & other){
        return (_ptr > other._ptr);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator < (const randomAccessIterator<T> & other){
        return (_ptr < other._ptr);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator >= (const randomAccessIterator<T> & other){
        return (_ptr >= other._ptr);
    }
    
    template <typename T>
    bool randomAccessIterator<T>::operator <= (const randomAccessIterator<T> & other){
        return ( _ptr <= other._ptr);
    }
    
    template <typename T>
    T & randomAccessIterator<T>::operator[] (int n){
        return (_ptr[n]);
    }
    
};
