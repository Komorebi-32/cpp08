/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:20:30 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 12:02:54 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

/*

Finds the first occurence of `num` in `cont`. Throws an exception if nothing found.

A simpler implementation would have been to return the result of `std::find()`
directly. If the element is not found, the return would have been `cont.end()`. 
This approach is also valid in containers handling, but it implies that the
caller handles the `cont.end()` return case to avoid segfault by trying to
dereference `cont.end()`. 

Note: Need to pass a ref to the container, because if `cont` is passed by value, 
`std::find()` would return an iterator to a copy of an element of `cont` which
would have been destroyed at the end of this function. 
*/
template<typename T>
typename T::iterator easyfind(T &cont, int num)
{
    typename T::iterator it = std::find(cont.begin(), cont.end(), num);
    
    // If find() returns the end iterator, the element wasn't found
    if (it == cont.end()) {
        throw std::exception();
    }
    
    return it;
}

#endif