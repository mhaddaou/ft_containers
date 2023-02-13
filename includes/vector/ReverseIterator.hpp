/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:33:37 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/13 00:31:51 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef REVERSEITERATOR_HPP
// #define REVERSEITERATOR_HPP
#pragma once

// #include "ra_iterator.hpp"
#include "it_traits.hpp"

namespace ft{
    template< class Iter >
    class reverse_iterator{
        public:
            typedef Iter iterator_type;
            typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iter>::value_type value_type;
            typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer pointer;
            typedef typename ft::iterator_traits<Iter>::reference reference;

            //constructor
            reverse_iterator();
            explicit reverse_iterator( iterator_type x );
            // template< class U >
            // reverse_iterator( const reverse_iterator<U>& other );
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other );
            //destructor
            ~reverse_iterator();
            // copy assignment operator
            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other );
            //base
            
            iterator_type base() const;
            reference operator*() const;
            pointer operator->() const;
            reference operator[]( difference_type n ) const;
            reverse_iterator& operator++();
            reverse_iterator& operator--();
            reverse_iterator operator++( int );
            reverse_iterator operator--( int );
            reverse_iterator operator+( difference_type n ) const;
            reverse_iterator operator-( difference_type n ) const;
            reverse_iterator& operator+=( difference_type n );	
            reverse_iterator& operator-=( difference_type n );

        private:
            Iter current;
    };
    
    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs );
    
    
    #include "../../src/tpp/ReverseIterator.tpp"
    
};