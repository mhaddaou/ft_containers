/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:26:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/06 22:14:43 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ra_iterator.hpp"
#include "../includes/vector/vector.hpp"
#include <vector>
int main (){
    std::vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.assign(6,4);

    std::cout << a.size() << std::endl;
    
    
    return (0);
}