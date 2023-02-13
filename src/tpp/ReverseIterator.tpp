/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseIterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:41:40 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/13 11:33:08 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector/ReverseIterator.hpp"


template <typename T>
ft::reverse_iterator<T>::reverse_iterator():current(NULL){}

template <typename T>
ft::reverse_iterator<T>::reverse_iterator(iterator_type x):current(x){}

template<typename Iter> template<typename U>
ft::reverse_iterator<Iter>::reverse_iterator(const ft::reverse_iterator<U>& other) {
    *this = other;
}

template<typename T>
ft::reverse_iterator<T>::~reverse_iterator(){}

template <typename T> template <typename U>
ft::reverse_iterator<T>& ft::reverse_iterator<T>::operator=(const ft::reverse_iterator<U>& other) {
    current = other.current;
    return (*this);
}

template<typename T>
T ft::reverse_iterator<T>::base() const {
    return (this->current);
}

template<typename Iter>
typename ft::iterator_traits<Iter>::reference ft::reverse_iterator<Iter>::operator*() const {
    Iter tmp = current;
    return *--tmp;
}

template <typename Iter>
typename ft::iterator_traits<Iter>::pointer ft::reverse_iterator<Iter>::operator->() const{
    return &(operator*());
}

template<typename Iter>
typename ft::iterator_traits<Iter>::reference ft::reverse_iterator<Iter>::operator[](typename ft::iterator_traits<Iter>::difference_type n) const {
    // return *(*this + n);
    // return (this->current[-n - 1]);
    return base()[-n - 1];
    
}

template <typename T>
ft::reverse_iterator<T>& ft::reverse_iterator<T>::operator++(){
    --current;
    return (*this);
}

template <typename T>
ft::reverse_iterator<T>& ft::reverse_iterator<T>::operator--(){
    ++current;
    return (*this);
}

template <typename T>
ft::reverse_iterator<T> ft::reverse_iterator<T>::operator++(int){
    reverse_iterator tmp(*this);
    --current;
    return (tmp);
}

template <typename T>
ft::reverse_iterator<T> ft::reverse_iterator<T>::operator--(int){
    reverse_iterator tmp(*this);
    ++current;
    return (tmp);
}

template <typename Iter>
ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator + (typename ft::iterator_traits<Iter>::difference_type n) const{
    return (reverse_iterator<Iter>(current - n));
}

template <typename Iter>
ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator - (typename ft::iterator_traits<Iter>::difference_type n) const{
    return (reverse_iterator<Iter>(current + n));
}

template <typename Iter>
ft::reverse_iterator<Iter>& ft::reverse_iterator<Iter>::operator += (typename ft::iterator_traits<Iter>::difference_type n){
    current -= n;
    return (*this);
}

template <typename Iter>
ft::reverse_iterator<Iter>& ft::reverse_iterator<Iter>::operator -= (typename ft::iterator_traits<Iter>::difference_type n){
    current += n;
    return (*this);
}

template < class Iter1, class Iter2>
bool operator== (const ft::reverse_iterator<Iter1>& lhs,
            const ft::reverse_iterator<Iter2>& rhs){
                return (lhs.current == rhs.current);
            }
template< class Iter1, class Iter2 >
bool operator!=( const ft::reverse_iterator<Iter1>& lhs,
                 const ft::reverse_iterator<Iter2>& rhs ){
                    return !(lhs.current == rhs.current);
                 }
template< class Iter1, class Iter2 >
    bool operator<( const ft::reverse_iterator<Iter1>& lhs,
                const ft::reverse_iterator<Iter2>& rhs ){
                    return (lhs.current < rhs.current);
                }
template< class Iter1, class Iter2 >
    bool operator<=( const ft::reverse_iterator<Iter1>& lhs,
                 const ft::reverse_iterator<Iter2>& rhs ){
                    return (lhs->current <= rhs.current);
                 }
template< class Iterator1, class Iterator2 >
    bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs ){
                    return (lhs->current > rhs.current);
                }
template< class Iterator1, class Iterator2 >
    bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ){
                    return (lhs.current >= rhs.current);
                 }
        