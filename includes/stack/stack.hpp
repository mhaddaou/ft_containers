/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:49:22 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/15 15:57:03 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../vector/vector.hpp"

namespace ft{
    template< class T, class Container = ft::vector<T> > 
    class stack{
        public:
            // member types
            
            typedef Container   container_type;
            typedef typename Container::value_type  value_type;
            typedef typename Container::size_type   size_type;
            typedef typename Container::reference   reference;
            typedef typename Container::const_reference const_reference;

            //member functions
            
            explicit stack( const Container& cont = Container() ):cntr(cont){}
            stack( const stack& other ){
                *this = other;
            }
            ~stack(){}
            stack& operator=( const stack& other ){
                cntr =  other.cntr;
                return (*this);
            }
            
            //Element access

            reference top(){
                return (cntr.back());
            }
            
            const_reference top() const{
                return (cntr.back());
            }

            //Capacity
            
            bool empty() const{
                return (cntr.empty());
            }

            size_type size() const{
                return (cntr.size());
            }
            
            //Modifiers
            
            void push( const value_type& value ){
                cntr.push_back( value );
            }
            
            void pop(){
                cntr.pop_back();
            }
        private:
           Container cntr; 
    };

    //Non-member functions
    
    template< class T, class Container >
    bool operator==( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr == rhs.cntr);
                 }

    template< class T, class Container >
    bool operator!=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr != rhs.cntr);
                 }
                 
    template< class T, class Container >
    bool operator<( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr < rhs.cntr);
                 }

    template< class T, class Container >
    bool operator<=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr <= rhs.cntr);
                 }

    template< class T, class Container >
    bool operator>( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr > rhs.cntr);
                 }

    template< class T, class Container >
    bool operator>=( const ft::stack<T, Container>& lhs,
                 const ft::stack<T, Container>& rhs ){
                    return (lhs.cntr >= rhs.cntr);
                 }
    // #include "../../src/stack/stack.tpp"
        
};