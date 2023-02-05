/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:05:08 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/05 10:17:27 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"

#include <vector>

int main (){
    
    std::vector<int> v ;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    RandomAccessIterator<int> first = v.data();
    std::cout << *first << std::endl;
          
    
}