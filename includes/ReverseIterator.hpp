/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:33:37 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/08 21:59:54 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/ra_iterator.hpp"

namespace ft{
    
    template< class Iter >
    class reverse_iterator{
        public:
            typedef Iter iterator_type;
            typedef std::iterator_traits<Iter>::iterator_category iterator_category;
            typedef std::iterator_traits<Iter>::value_type value_type;
            typedef std::iterator_traits<Iter>::difference_type difference_type;
            typedef std::iterator_traits<Iter>::pointer pointer;
            typedef std::iterator_traits<Iter>::reference reference;

            //constructor
            reverse_iterator();
            explicit reverse_iterator( iterator_type x );
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
        private:
            Iter current;
    };
    #include "../src/tpp/ReverseIterator.tpp"
};