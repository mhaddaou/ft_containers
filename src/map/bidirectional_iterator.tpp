/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:12:45 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/16 21:02:04 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map/bidirectional_iterator.hpp"

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T,cmp,alloc>::bidirectional_iterator():_tree(NULL), _node(NULL){}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>::bidirectional_iterator(tree t, pointer node){
    _tree = t;
    _node = ptr;
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>::bidirectional_iterator(const bidirectional_iterator& other){
    *this = other;
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>& ft::bidirectional_iterator<T, cmp, alloc>::operator=(const bidirectional_iterator& other){
    _tree = other._tree;
    _node = other._node;
    return (*this);
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>::~bidirectional_iterator(){}

template <typename T, class cmp, class alloc>
T& ft::bidirectional_iterator<T, cmp, alloc>::operator*() const{
    return (*_node);
}

template <typename T, class cmp, class alloc>
T* ft::bidirectional_iterator<T, cmp, alloc>::operator->() const{
    return (_tree);
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>& ft::bidirectional_iterator<T, cmp, alloc>::operator++(){
    _node = ft::map->next(_node);
    return (*this);
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc> ft::bidirectional_iterator<T, cmp, alloc>::operator++(int){
    bidirectional_iterator tmp(*this);
    _node = ft::map->next(_node);
    return (tmp);
}

template <typename T, class cmp, class alloc>
ft::bidirectional_iterator<T, cmp, alloc>&  ft::bidirectional_iterator<T, cmp, alloc>::operator--(){
    _node = ft::map->prev(_node);
    return (*this);
}

template <typename T, class cmp, class alloc>
 ft::bidirectional_iterator<T, cmp, alloc> ft::bidirectional_iterator<T, cmp, alloc>::operator--(int) {
        bidirectional_iterator tmp(*this);
        _node = avltree->prev(_node);
        return tmp;
    }
template <typename T, class cmp, class alloc>
bool operator==(const ft::bidirectional_iterator<T, cmp, alloc>& lhs, const ft::bidirectional_iterator<T, cmp, alloc>& rhs){
    return ((lhs._node == rhs._node) && (lhs._tree == rhs._tree) );
}

template <typename T, class cmp, class alloc>
bool operator!=(const ft::bidirectional_iterator<T, cmp, alloc>& lhs, const ft::bidirectional_iterator<T, cmp, alloc>& rhs){
    return (!(lhs == rhs));
}

// template <typename T, class cmp, class alloc>