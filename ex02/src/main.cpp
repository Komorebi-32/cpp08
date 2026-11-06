/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:29:28 by komorebi          #+#    #+#             */
/*   Updated: 2026/11/06 12:02:27 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cassert>
#include <iostream>
#include <list>
#include <stack>

template <typename Iterator>
void printRange(const char* label, Iterator begin, Iterator end)
{
    std::cout << label;
    for (Iterator it = begin; it != end; ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

void runComparisonTest()
{
    std::cout << "=== Subject example: MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top after push(5), push(17): " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size after pop(): " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    printRange("iteration order (begin to end): ", it, ite);

    std::stack<int> stackCopy(mstack);
    std::cout << "std::stack copy: size=" << stackCopy.size()
              << ", top=" << stackCopy.top() << std::endl;

    std::cout << "\n=== Same operations: std::list ===" << std::endl;
    std::list<int> values;
    values.push_back(5);
    values.push_back(17);
    std::cout << "back after push_back(5), push_back(17): "
              << values.back() << std::endl;
    values.pop_back();
    std::cout << "size after pop_back(): " << values.size() << std::endl;
    values.push_back(3);
    values.push_back(5);
    values.push_back(737);
    values.push_back(0);

    std::list<int>::iterator listIt = values.begin();
    std::list<int>::iterator listEnd = values.end();
    ++listIt;
    --listIt;
    printRange("iteration order (begin to end): ", listIt, listEnd);

    std::list<int> listCopy(values);
    std::cout << "std::list copy: size=" << listCopy.size()
              << ", back=" << listCopy.back() << std::endl;
}

void runIteratorEdgeCaseTest()
{
    std::cout << "\n=== Iterator edge cases ===" << std::endl;
    MutantStack<int> values;
    const MutantStack<int>& constValues = values;

    assert(values.begin() == values.end());
    assert(values.rbegin() == values.rend());
    assert(constValues.begin() == constValues.end());
    assert(constValues.rbegin() == constValues.rend());
    std::cout << "empty stack: forward and reverse ranges are empty" << std::endl;

    values.push(42);
    MutantStack<int>::iterator it = values.begin();
    MutantStack<int>::const_iterator constIt = constValues.begin();
    MutantStack<int>::reverse_iterator reverseIt = values.rbegin();
    MutantStack<int>::const_reverse_iterator constReverseIt = constValues.rbegin();

    assert(*it == 42);
    assert(*constIt == 42);
    assert(*reverseIt == 42);
    assert(*constReverseIt == 42);
    ++it;
    ++constIt;
    ++reverseIt;
    ++constReverseIt;
    assert(it == values.end());
    assert(constIt == constValues.end());
    assert(reverseIt == values.rend());
    assert(constReverseIt == constValues.rend());
    std::cout << "single element: mutable/const forward and reverse iterators "
              << "all visit 42 and reach their end" << std::endl;

    values.push(84);
    values.push(126);
    printRange("forward order: ", values.begin(), values.end());
    printRange("reverse order: ", values.rbegin(), values.rend());
    printRange("const forward order: ", constValues.begin(), constValues.end());
    printRange("const reverse order: ", constValues.rbegin(), constValues.rend());
    assert(values.begin() != values.end());
    assert(values.rbegin() != values.rend());
}

void runStackAndCopyTest()
{
    std::cout << "\n=== Stack operations and copying ===" << std::endl;
    MutantStack<int> original;
    assert(original.empty());
    original.push(10);
    original.push(20);
    original.push(30);
    std::cout << "after push(10), push(20), push(30): size="
              << original.size() << ", top=" << original.top() << std::endl;

    MutantStack<int> constructedCopy(original);
    MutantStack<int> assignedCopy;
    assignedCopy.push(-1);
    assignedCopy = original;
    assignedCopy = assignedCopy;
    printRange("copy-constructed contents: ",
               constructedCopy.begin(), constructedCopy.end());
    printRange("copy-assigned contents: ",
               assignedCopy.begin(), assignedCopy.end());

    constructedCopy.pop();
    constructedCopy.push(40);
    std::cout << "after changing copy only: original top=" << original.top()
              << ", changed copy top=" << constructedCopy.top() << std::endl;
    assert(original.size() == 3);
    assert(original.top() == 30);
    assert(constructedCopy.size() == 3);
    assert(constructedCopy.top() == 40);

    std::stack<int> standardCopy(original);
    std::cout << "converted std::stack: size=" << standardCopy.size()
              << ", top=" << standardCopy.top() << std::endl;

    while (!original.empty())
        original.pop();
    std::cout << "after popping all original elements: empty="
              << (original.empty() ? "true" : "false")
              << ", size=" << original.size() << std::endl;
    assert(original.empty());
    assert(original.size() == 0);
}

int main(void)
{
    runComparisonTest();
    runIteratorEdgeCaseTest();
    runStackAndCopyTest();
    return 0;
}