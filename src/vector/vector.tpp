/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:41:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/06 20:44:42 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/vector.hpp"
#include "../../includes/vector/ra_iterator.hpp"



template<class T>
ft::Vector<T>::Vector(): _size(0), _data(NULL), _capacity(0), _alloc(){}




