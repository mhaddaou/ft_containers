/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:12:38 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/16 21:01:33 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../includes/vector/it_traits.hpp"

namespace ft{
    template <typename T, class cmp, class alloc>
    class map;
    template <typename T, class cmp, class alloc>
    class bidirectional_iterator{
        public:
            //typedefs
            
            typedef std::bidirectional_iterator_tag iterator_category;
            typedef T value_type;
            typedef std::ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
            typedef const AvlTree<T, cmp, alloc>* tree;
            
            //membered functions

            bidirectional_iterator();
            bidirectional_iterator(tree t, pointer ptr);
            bidirectional_iterator(const bidirectional_iterator& other);
            bidirectional_iterator& operator=(const bidirectional_iterator& other);
            ~bidirectional_iterator();

            //operators

            reference operator*() const;
            pointer operator->() const;
            bidirectional_iterator& operator++();
            bidirectional_iterator operator++(int);
            bidirectional_iterator& operator--();
            bidirectional_iterator operator--(int);
            operator bidirectional_iterator<const T, cmp, alloc> () const 
            {
				return bidirectional_iterator<const T, cmp, alloc>(_node, reinterpret_cast<const AvlTree<const value_type, cmp, alloc>*>(_tree));
			}
            
            
            
        private:
            tree _tree;
            pointer _node;
    };
            //comparison operators
            
            template <typename T, class cmp, class alloc>
            bool operator==(const ft::bidirectional_iterator<T, cmp, alloc>& lhs, const ft::bidirectional_iterator<T, cmp, alloc>& rhs);
            
            template <typename T, class cmp, class alloc>
            bool operator!=(const ft::bidirectional_iterator<T, cmp, alloc>& lhs, const ft::bidirectional_iterator<T, cmp, alloc>& rhs);
    
    
    #include "../../src/map/bidirectional_iterator.tpp"
    


    
};