/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   urils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou < mhaddaou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 13:59:04 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/02/11 14:10:10 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

namespace ft{

    template <typename InputIt>
    size_t distance(InputIt first, InputIt last){
        size_t dis = 0;
        for (; first != last; first++){
            dis++;
        }
        return dis;
    }
};