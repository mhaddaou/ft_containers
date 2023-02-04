/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:04:01 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/04 17:25:44 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

namespace ft{
    template <typename T>
    randomAccessIterator<T>::randomAccessIterator() : _ptr(NULL){
        std::cout << "randomAccessIterator" << std::endl;
    }
    template <typename T>
    randomAccessIterator<T>::randomAccessIterator(T *ptr) : _ptr(ptr){}
    template <typename T>
    randomAccessIterator<T>::randomAccessIterator(const randomAccessIterator &other){
        this = other;
        return (*this);
    }
    template <typename T>
    randomAccessIterator<T> & randomAccessIterator<T>::operator=(const randomAccessIterator &other){
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
        return(ptr);
    }
    
    // template <typename T>
    
    
    
    
    
};
