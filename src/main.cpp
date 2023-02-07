/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/07 06:29:47 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"
#include "../includes/vector/vector.hpp"
#include <vector>
int main (){
    std::vector<int> a;
    a.push_back(9);
    a.push_back(7);
    a.push_back(3);
    // a.push_back(4);
    // a.push_back(5);
    // a.assign(6,4);
    // a.reserve(0);
    // a[0] = 1;
    std::cout << a.capacity() << std::endl;
    ft::Vector<int> vec;
    vec.assign(a.begin(), a.end());
//    ft::RandomAccessIterator<int> it = vec.begin();
//    ft::RandomAccessIterator<int> ite = vec.end();
//    std::cout <<vec.max_size() << std::endl;
//    std::cout << a.max_size() << std::endl;
    vec.reserve(100);
    
    return (0);
}