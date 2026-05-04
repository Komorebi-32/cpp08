/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:59 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/04 17:35:47 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class Span {
public:
    // ---------- Constructors / Destructor ----------

    Span(void);
    Span(unsigned int N);
    Span(const Span& copy);
    ~Span(void);

    // ---------- Overloading Operators Methods -------

    Span& operator=(const Span& copy);

    // ---------- Getter and Setter Methods ------------

    // ---------- Member Methods -----------------------
    void addNumber(int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    // use this: template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
//what the fuck is an input iterator ??
//need to add the correct parameters to this function (params of insert() ?)
//need to check that the number of elements to add is not too large for the vector
    template <typename InputIterator>
    void addMultipleNumbers(std::vector<int>::iterator position, InputIterator first, InputIterator last)
    {
        if (position < this->_treasureChest.begin() || position > this->_treasureChest.end())
            throw std::runtime_error("Wrong position provided");
        
        std::vector<int> temp(first, last);

        if (temp.size() > this->_capacity - this->_treasureChest.size())
            throw std::length_error("Span does not have enough space");

        this->_treasureChest.insert(position, temp.begin(), temp.end());

    } //int[] as parameter ?

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    std::vector<int>    _treasureChest;
    unsigned int        _capacity;
};

#endif // SPAN_HPP