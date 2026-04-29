/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:35:45 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 14:35:53 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(void)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(const Span& copy)
{
    std::cout << "Span copy constructor called" << std::endl;
    *this = copy;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
}

Span& Span::operator=(const Span& copy)
{
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &copy) {
        // copy data members here
    }
    return (*this);
}