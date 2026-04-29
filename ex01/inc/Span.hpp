/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:34:59 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 14:35:10 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>

class Span {
public:
    // ---------- Constructors / Destructor ----------

    Span(void);
    Span(const Span& copy);
    ~Span(void);

    // ---------- Overloading Operators Methods -------

    Span& operator=(const Span& copy);

    // ---------- Getter and Setter Methods ------------

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
};

#endif // SPAN_HPP