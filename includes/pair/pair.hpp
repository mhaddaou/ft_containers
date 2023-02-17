/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:28:48 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/17 16:08:35 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft{
    template<class T1, class T2> 
    struct pair{
        public:
            //Member types
            
            typedef T1  first_type;
            typedef T2  second_type;
           
           

            //Member functions

            pair(); 

            pair( const T1& x, const T2& y );
            
            template< class U1, class U2>
            pair( const pair<U1, U2>& p );
            
            pair( const pair& p );
            pair& operator=( const pair& other );

            // template< class T1, class T2 >
        private:
            
            //Member objects
            T1  first;
            T2  second;
            
            	

        
    };

    //Non member functions
    
    template< class T1, class T2 >
    ft::pair<T1, T2> make_pair( T1 t, T2 u ){
        return (ft::pair<T1, T2>(t, u));
    }

    template< class T1, class T2, class U1, class U2 >
    bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return ((lhs.first == rhs.first) && (lhs.second == rhs.second));
    }
    
    template< class T1, class T2, class U1, class U2 >
    bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return !(lhs == rhs);
    }
    
    template< class T1, class T2, class U1, class U2 >
    bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return ((lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second < rhs.second)));
    }
    
    template< class T1, class T2, class U1, class U2 >
    bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return (!(rhs < lhs));
    }
    
    template< class T1, class T2, class U1, class U2 >
    bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return (rhs < lhs);
    }
    
    template< class T1, class T2, class U1, class U2 >
    bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<U1, U2>& rhs ){
        return (!(lhs < rhs));
    }
    
    #include "../../src/pair/pair.tpp"
    
};