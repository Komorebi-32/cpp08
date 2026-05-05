/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:28:30 by komorebi          #+#    #+#             */
/*   Updated: 2026/05/05 16:29:16 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>

class MutantStack {
public:
    // ---------- Constructors / Destructor ----------

    MutantStack(void);
    MutantStack(const MutantStack& copy);
    ~MutantStack(void);

    // ---------- Overloading Operators Methods -------

    MutantStack& operator=(const MutantStack& copy);

    // ---------- Getter and Setter Methods ------------

    // ---------- Member Methods -----------------------

protected:
    // ---------- Protected Data Members ---------------------

private:
    // ---------- Private Data members -------------------------
};

#endif // MUTANTSTACK_HPP