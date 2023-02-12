/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:41:40 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/12 16:17:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ReverseIterator.hpp"

template <class T>
ft::reverse_iterator<T>::reverse_iterator():current(NULL){}

template <class T>
ft::reverse_iterator<T>::reverse_iterator(iterator_type x):current(x){}

template<class U>
ft::reverse_iterator<U>::reverse_iterator(const reverse_iterator<U>& other){
    this = other;
}

template<class T>
ft::reverse_iterator<T>::~reverse_iterator(){}

template<class T>
reverse_iterator & ft::reverse_iterator<T>::operator=(const reverse_iterator<T>& other){
    this->current = other.current;
    return *this;
}

template<class T>
iterator_type ft::reverse_iterator<T>::base() const {
    return (this->current);
}

template<class T>
T& ft::reverse_iterator<T>::operator*() const{
    T tmp = this->current;
    return (*--tmp);
}

