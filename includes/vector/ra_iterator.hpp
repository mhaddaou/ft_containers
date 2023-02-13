/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_iterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 08:09:12 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/13 11:32:31 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RA_ITERATOR_HPP
#define RA_ITERATOR_HPP

#include <iostream>
#include <algorithm>
#include "it_traits.hpp"
#include <string>
namespace ft{
    

    
    template <typename T>
    class  RandomAccessIterator{
        public:
            //typedefs
            typedef T value_type;
            typedef T& reference;
            typedef T* pointer;
            typedef std::ptrdiff_t difference_type;
            typedef std::random_access_iterator_tag iterator_category;
            
            //constructors
            RandomAccessIterator();
            RandomAccessIterator(T *p);
            
            //destructor
            ~RandomAccessIterator(){}

            //overload return operators
            RandomAccessIterator & operator ++();
            RandomAccessIterator & operator --();
            RandomAccessIterator  operator ++(int);
            RandomAccessIterator  operator --(int);
            operator RandomAccessIterator< T const>() const{
                return RandomAccessIterator< T const>(_ptr);
            }
            T &operator *() const;
            T* operator ->() const;

            //overload comparison operators
            bool operator == (const RandomAccessIterator& other) const;
            bool operator != (const RandomAccessIterator& other) const;
            bool operator < (const RandomAccessIterator& other) const;
            bool operator <=(const RandomAccessIterator& other) const;
            bool operator > (const RandomAccessIterator& other) const;
            bool operator >=(const RandomAccessIterator& other) const;
            
        private:
            T* _ptr;
        
    };
    template< class Iterator1, class Iterator2 >
    bool operator==( const ft::RandomAccessIterator<Iterator1>& lhs,
                 const ft::RandomAccessIterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator!=( const ft::RandomAccessIterator<Iterator1>& lhs,
                 const ft::RandomAccessIterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator<( const ft::RandomAccessIterator<Iterator1>& lhs,
                const ft::RandomAccessIterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator<=( const ft::RandomAccessIterator<Iterator1>& lhs,
                 const ft::RandomAccessIterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator>( const ft::RandomAccessIterator<Iterator1>& lhs,
                const ft::RandomAccessIterator<Iterator2>& rhs );
    template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::RandomAccessIterator<Iterator1>& lhs,
                 const ft::RandomAccessIterator<Iterator2>& rhs );

    #include "../../src/tpp/RandomAccessIterator.tpp"
};
#endif