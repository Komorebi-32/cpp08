/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:28:30 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/05 16:58:11 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // ---------- Constructors / Destructor ----------

    MutantStack(void) {};
    MutantStack(const MutantStack& copy) : std::stack<T>(copy)
    {
        *this = copy;
    };
    ~MutantStack(void) {};

    // ---------- Overloading Operators Methods -------

    MutantStack& operator=(const MutantStack& copy)
    {
        if (this != &copy)
            std::stack<T>::operator=(copy);
        return (*this);
    };

    // ---------- Getter and Setter Methods ------------
    typedef std::stack<T>::container_type::iterator iterator;

    iterator begin()
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }

    //protected ? reverse iterator ? 

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    // std::stack stackos;
};

#endif // MUTANTSTACK_HPP