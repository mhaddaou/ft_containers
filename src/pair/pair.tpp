/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:29:07 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/17 15:32:02 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pair/pair.hpp"

template <class T1, class T2>
ft::pair<T1, T2>::pair():first(first_type()), second(second_type()){}

template <class T1, class T2>
ft::pair<T1, T2>::pair(const T1& x, const T2& y): first(x), second(y){}

template <class T1, class T2>
template <class U1, class U2>
ft::pair<T1, T2>::pair(const pair<U1, U2>& p){
    first = p.first;
    second = p.second;
}

template<class T1, class T2>
ft::pair<T1, T2>::pair(const pair& p){
    *this = p;
}

template<class T1, class T2>
ft::pair<T1,T2>& ft::pair<T1,T2>::operator=(const pair& other){
    first = other.first;
    second = other.second;
}


