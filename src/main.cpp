/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/08 20:49:53 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"
#include "../includes/vector/vector.hpp"
#include <vector>
#include<unistd.h>   
int main (){
    std::vector<int> a;
    a.push_back(9);
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);
    a.push_back(13);
    std::vector<int> r;
    r.push_back(1);
    r.push_back(2);
    r.push_back(3);
    r.push_back(4);
    r.push_back(5);
    // a.assign(6,4);
    // a.reserve(0);
    // a[0] = 1;
    // std::cout << a.capacity() << std::endl;
    // a.insert(a.begin() , 5);
    // std::cout << a[1] << std::endl;
    // a.insert(a.begin() + 2, 0);
    // ft::Vector<int> vec;
    // vec.assign(a.begin(), a.end());
    std::vector<int> b;
    b.assign(a.begin(), a.end());
    b.insert(b.begin(), r.begin(),r.end());
    ft::vector<int> vec;
    vec.assign(a.begin(), a.end());
    ft::vector<int>::iterator pos = vec.begin();
    pos++;
    vec.insert(pos, 5);
    // ft::vector<int>::iterator it = vec.begin();
    // ft::vector<int>::iterator end = vec.end();
    // it++;
    // // it++;
    // // --end;
    // std::cout << *it << std::endl;
    // std::cout << "--------------------------------" << std::endl;
    // vec.erase(it);
    
    // for(size_t i = 0; i < vec.size();i++){
    //     std::cout << vec[i] << std::endl;
    // }
    // std::cout << vec.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;
    

    // // ft::RandomAccessIterator<int> it = vec.end();
    // ft::Vector<int>::const_iterator it  = vec.begin();
    // // it--;
    // // it--;
    // std::cout << *it << std::endl;
    // std::vector<int>::iterator i = b.end();
    // i--;
    // i--;
    // vec.insert(it, 5, 11);
    // b.insert(i, 5, 11);

    // std::cout << "--------------------------------" << std::endl;

    // for (size_t i = 0; i < b.size();i++){
    //     std::cout << b[i] << std::endl;
    // } 
    // std::cout << "--------------------------------" << std::endl;
    
    // std::cout << b.capacity() << std::endl;
    // std::cout << b.size() << std::endl;
    // std::cout << vec.capacity() << std::endl;
    // std::cout << vec.size() << std::endl;
    

    

    
    return (0);
}