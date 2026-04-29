/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:35:45 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 16:36:10 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
default-initializing the vector here. Explicitly written to improve readability,
but still optional to write it.
*/
Span::Span(void) : _treasureChest(), _capacity(0)
{
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
    std::cout << "Span parameterized constructor called" << std::endl;
    this->_treasureChest.reserve(N);
    this->_capacity = N;
}

Span::Span(const Span &copy)
{
    std::cout << "Span copy constructor called" << std::endl;
    *this = copy;
}

Span::~Span(void)
{
    std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(const Span &copy)
{
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &copy)
    {
        // copy data members here
    }
    return (*this);
}

/*
Adds a single number to the Span. Any attempt to add a new element if there
are already N elements stored should throw an exception.

Throws a `std::length_error()` exception because `std::exception`
is the generic base type and doesn't carry a user message or semantic category
*/
void Span::addNumber(int num)
{
    // check if there are already N elements before filling
    if (this->_treasureChest.size() < this->_capacity)
        this->_treasureChest.push_back(num);
    else
        throw std::length_error("Span is full");
}

unsigned int Span::longestSpan()
{
    if (_treasureChest.size() <= 1)
        throw std::runtime_error("Span is too small");

    return (*std::max_element(_treasureChest.begin(), _treasureChest.end()) - *std::min_element(_treasureChest.begin(), _treasureChest.end()));
}

unsigned int Span::shortestSpan()
{
    if (_treasureChest.size() <= 1)
        throw std::runtime_error("Span is too small");

    std::vector<int> sortedChest;
    std::vector<int>::iterator it;
    unsigned int res;

    sortedChest = this->_treasureChest;
    it = sortedChest.begin();
    std::sort(it, sortedChest.end());

    res = *(it + 1) - *it;
    it++;

    while (it != sortedChest.end())
    {
        if (*(it + 1) - *it < res)
            res = *(it + 1) - *it;
        it++;
    }
}
