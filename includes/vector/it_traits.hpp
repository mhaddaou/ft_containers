/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_traits.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:35:40 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/12 19:36:48 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
namespace ft{
    template <typename Iterator> 
    struct iterator_traits {
        typedef typename Iterator::difference_type		difference_type;
        typedef typename Iterator::value_type			value_type;
        typedef typename Iterator::pointer				pointer;
        typedef typename Iterator::reference			reference;
        typedef typename Iterator::iterator_category	iterator_category;
    };
    template <class T> 
    class iterator_traits<T *> {
        public:
            typedef std::ptrdiff_t					          diffrence_type;
            typedef T								                  value_type;
            typedef T*								                pointer;
            typedef T&								                reference;
            typedef std::random_access_iterator_tag	  iterator_category;
        };
    template <class T> 
    class iterator_traits<const T *> {
        public:
            typedef std::ptrdiff_t			        diffrence_type;
            typedef T								            value_type;
            typedef const T*						        pointer;
            typedef const T&						  reference;
            typedef std::random_access_iterator_tag	iterator_category;
        };

};