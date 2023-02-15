/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/15 15:55:12 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"
#include "../includes/vector/vector.hpp"
#include "../includes/stack/stack.hpp"
#include <stack>
#include <vector>
#include<unistd.h>   
int main (){
    std::vector<int> b;
    b.push_back(0);
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    std::vector<int>::iterator bg = b.begin();
    std::vector<int>::iterator end = b.end();
    std::vector<int>::iterator bb = b.begin();
    std::vector<int>::iterator be = b.end();
    ft::vector<int> a;
    int array [] = {9,13,31, 43};
    std::vector<int> v;
    v.assign(array, array+4);    
    a.assign(array,array + 4);
    ft::vector<int>::iterator it = a.begin();
    std::vector<int>::iterator ite = v.begin();
    // it++;
    // ft::vector<int>::iterator end = a.end();
    // end--;
    // std::cout << *it << std::endl;
    // a.erase(it, end);
    v.insert(ite, bb, be);
    a.insert(it , bg, end);
    std::cout << "cap " << a.capacity() << std::endl;
    std::cout << "cap " << v.capacity() << std::endl;
    ft::vector<int>::iterator e = a.begin();
    ft::vector<int>::iterator r = a.end();
    std::vector<int>::iterator ee = v.begin();
    std::vector<int>::iterator rr = v.end();
    e++;
    ee++;
    ee++;
    e++;
    r--;
    rr--;
    rr--;
    r--;
    a.erase(e, r);
    v.erase(ee, rr);
    ft::vector<int>::iterator begin = a.begin();
    for(; begin != a.end(); ++begin){
        std::cout << *begin << std::endl;
    }
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() <<std::endl;
    std::cout << "---------------" << std::endl;
    std::vector<int>::iterator begine = v.begin();
    for(; begine != v.end(); ++begine){
        std::cout << *begine << std::endl;
    }
    std::cout << v.capacity() << std::endl;
    std::cout << v.size() <<std::endl;

    std::cout << "----------------- push back --------------------"<< std::endl;
    ft::vector<int> m;
    std::vector<int> l;
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    l.push_back(5);
    ft::vector<int> swap;
    // l.swap(swap);
    // // std::cout << l[510] << std::endl;
    // std::cout << l[0] << std::endl;
    // std::cout <<"size == " <<  l.size() << std::endl;
    // std::cout << "capa == " << l.capacity() << std::endl;
    // std::cout << "cap " << l.capacity() << std::endl;
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.push_back(5);
    m.swap(swap);
    if (m == swap)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    // std::cout << m[0] << std::endl;
    // std::cout << m == swap << std::endl;
    // for (ft::vector<int>::iterator it = swap.begin(); it != swap.end(); ++it){
    //     std::cout << *it << std::endl;
    // }
    // m.resize(5,6);
    // for (ft::vector<int>::iterator it = m.begin(); it != m.end(); ++it){
    //     std::cout << *it << std::endl;
    // }
    // std::cout << "size == " << m.size() << std::endl;
    // std::cout << "capa == " << m.capacity() << std::endl;
    
    // std::cout << "m " << m[1] << std::endl;
    std::cout << "----------------------------------- reverse iterator ---------------------------" << std::endl;   
    std::vector<int> p;
    p.push_back(0);
    p.push_back(1);
    p.push_back(2);
    
    std::vector<int>::reverse_iterator itt = p.rend();
    // std::cout << *itt.base() << std::endl;
    itt--;
    itt--;
    std::cout << *itt << std::endl;
    
    ft::vector<int> aa;
    aa.push_back(0);
    aa.push_back(1);
    aa.push_back(2);
    ft::vector<int>::reverse_iterator iti = aa.rend();
    // std::cout << *iti.base();
    iti--;
    iti--;
    std::cout << *iti << std::endl;
    std::cout << "--------------test----------------" << std::endl;

    ft::vector<int> _vec;

    _vec.push_back(5);
    _vec.push_back(15);
    _vec.push_back(20);
    std::vector<int> _a;
    _a.push_back(5);
    _a.push_back(15);
    _a.push_back(20);
    std::vector<int>::iterator _i;
    std::cout << "----------std----------" << std::endl;
    for (std::vector<int>::iterator i = _a.begin(); i != _a.end(); ++i){
        std::cout << *i << std::endl;
    }
    std::cout << "capacity: " << _a.capacity() << std::endl;
    std::cout << "size: " << _a.size() << std::endl;
    std::cout << "----------ft.----------" << std::endl;

    for (ft::vector<int>::iterator _it = _vec.begin();_it != _vec.end(); ++_it){
        std::cout << *_it << std::endl;
    }
    
    std::cout << "capacity: " << _vec.capacity() << std::endl;
    std::cout << "size: " << _vec.size() << std::endl;
    
    std::cout << "--------------------------test stack ------------------------" << std::endl;
    std::stack<int> st;
    st.push(5);
    st.push(6);
    st.pop();
    std::cout << st.top() <<   std::endl;
    ft::stack<int>  stack;
    stack.push(5);
    stack.push(6);
    stack.pop();
    std::cout << stack.top() << std::endl;
        

    
    return (0);
}