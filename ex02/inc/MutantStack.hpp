/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:28:30 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/05 17:24:40 by komorebi         ###   ########.fr       */
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
    typedef std::stack<T>::container_type::const_iterator const_iterator;
    typedef std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
        return (this->c.begin());
    }

    iterator end()
    {
        return (this->c.end());
    }
    
    const_iterator begin() const
    {
        return (this->c.begin());
    }

    const_iterator end() const
    {
        return (this->c.end());
    }

    reverse_iterator rbegin()
    {
        return (this->c.rbegin());
    }

    reverse_iterator rend()
    {
        return (this->c.rend());
    }

    const_reverse_iterator rbegin() const
    {
        return (this->c.rbegin());
    }

    const_reverse_iterator rend() const
    {
        return (this->c.rend());
    }

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
    // std::stack stackos;
};

#endif // MUTANTSTACK_HPP