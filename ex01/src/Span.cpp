/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:35:45 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/05 13:50:53 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define GREY "\033[90m"
#define RESET "\033[0m"

/*
default-initializing the vector here. Explicitly written to improve readability,
but still optional to write it.
*/
Span::Span(void) : _treasureChest(), _capacity(0)
{
    std::cout << GREY << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N)
{
    std::cout << GREY << "Span parameterized constructor called" << RESET << std::endl;
    this->_treasureChest.reserve(N);
    this->_capacity = N;
}

Span::Span(const Span &copy)
{
    std::cout << GREY << "Span copy constructor called" << RESET << std::endl;
    *this = copy;
}

Span::~Span(void)
{
    std::cout << GREY << "Span destructor called" << RESET << std::endl;
}

std::vector<int>::iterator Span::begin(void)
{
    return (this->_treasureChest.begin());
}

std::vector<int>::iterator Span::end(void)
{
    return (this->_treasureChest.end());
}

std::vector<int>::const_iterator Span::begin(void) const
{
    return (this->_treasureChest.begin());
}

std::vector<int>::const_iterator Span::end(void) const
{
    return (this->_treasureChest.end());
}

Span &Span::operator=(const Span &copy)
{
    std::cout << GREY << "Span assignment operator called" << RESET << std::endl;
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
    int res;

    sortedChest = this->_treasureChest;
    it = sortedChest.begin();
    std::sort(it, sortedChest.end());

    res = *(it + 1) - *it;
    it++;

    while ((it + 1) != sortedChest.end())
    {
        if (*(it + 1) - *it < res)
            res = *(it + 1) - *it;
        it++;
    }
    return (res);
}
