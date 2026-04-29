/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:19:36 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 12:19:08 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void)
{
    int values[] = {2, 5, 32, 64};
    std::vector<int> myFirstVector(values, values + 4);

    try
    {
        std::cout << "---Trying to find 32 in the vector---" << std::endl;
        std::vector<int>::iterator it = easyfind(myFirstVector, 32);
        std::cout << "found " << *it << " in the vector\n" << std::endl; 

        std::cout << "---Trying to find 128 in the vector---" << std::endl;
        it = easyfind(myFirstVector, 128);
    }
    catch(const std::exception& e)
    {
        std::cout << "element not found!" << '\n';
    }
}