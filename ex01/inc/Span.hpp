/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:59 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 16:22:16 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

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
    void addMultipleNumbers(); //int[] as parameter ?

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    std::vector<int>    _treasureChest;
    unsigned int        _capacity;
};

#endif // SPAN_HPP