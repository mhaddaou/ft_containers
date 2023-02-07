/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/07 23:55:00 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"
#include "../includes/vector/vector.hpp"
#include <vector>
#include<unistd.h>   
int main (){
    std::vector<int> a;
    a.push_back(9);
    a.push_back(7);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    // a.assign(6,4);
    // a.reserve(0);
    // a[0] = 1;
    // std::cout << a.capacity() << std::endl;
    // a.insert(a.begin() , 5);
    // std::cout << a[1] << std::endl;
    // a.insert(a.begin() + 2, 0);
    ft::Vector<int> vec;
    vec.assign(a.begin(), a.end());
    ft::RandomAccessIterator<int> it = vec.end();
    // std::cout << *it << std::endl;
    it--;
    // it++;
    // it++;
    // it++;
    vec.insert(it , 110);
    sleep(4444);
    
    return (0);
}