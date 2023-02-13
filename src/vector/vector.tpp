/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:41:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/13 00:09:19 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/vector.hpp"
#include "../../includes/vector/ra_iterator.hpp"



// template<class T>
// ft::Vector<T>::Vector(): _size(0), _data(NULL), _capacity(0), _alloc(){}



template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector():_size(0),_data(NULL), _capacity(0){}
// {
//     _data = NULL;
//     _size = 0;
//     _capacity = 0;
// }
template<typename T, typename Alloc>
ft::vector<T, Alloc>::vector(const Alloc& alloc):
    _data(NULL),
    _size(0),
    _capacity(0),
    _alloc(alloc)
{}

template<typename T, typename Alloc>
ft::reverse_iterator<ft::RandomAccessIterator<T> > ft::vector<T, Alloc>::rbegin(){
    return (reverse_iterator(this->end()));
}

template<typename T, typename Alloc>
ft::reverse_iterator<ft::RandomAccessIterator<const T> > ft::vector<T, Alloc>::rbegin() const{
    return (const_reverse_iterator(this->end()));
}

template<typename T, typename Alloc>
ft::reverse_iterator<ft::RandomAccessIterator<T> > ft::vector<T, Alloc>::rend(){
    return (reverse_iterator(this->begin()));
}

template <typename T, typename Alloc>
ft::reverse_iterator<ft::RandomAccessIterator<const T> > ft::vector<T, Alloc>::rend() const{
    return (const_reverse_iterator(this->begin()));
}