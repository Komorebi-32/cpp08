/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:59 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/05 16:27:22 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

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

    //non-const getters: for writable Span objects
    std::vector<int>::iterator begin(void);
    std::vector<int>::iterator end(void);

    //const getters: for read-only Span objects
    std::vector<int>::const_iterator begin(void) const;
    std::vector<int>::const_iterator end(void) const;

    // ---------- Member Methods -----------------------
    void addNumber(int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    /*
    * Inserts a range of elements before the element at `position`.
    * A position equal to size() inserts at the end.
    * Throws if the position is out of bounds or if the Span lacks capacity.
    */
    template <typename InputIterator>
    void addMultipleNumbers(std::vector<int>::size_type position, InputIterator first, InputIterator last)
    {
        if (position > this->_treasureChest.size())
            throw std::out_of_range("Wrong position provided");
        
        std::vector<int> temp(first, last);

        if (temp.size() > this->_capacity - this->_treasureChest.size())
            throw std::length_error("Span does not have enough space");

        this->_treasureChest.insert(this->_treasureChest.begin() + position,
                                    temp.begin(), temp.end());

    }

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    std::vector<int>    _treasureChest;
    unsigned int        _capacity;
};

#endif // SPAN_HPP