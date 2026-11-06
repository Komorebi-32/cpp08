/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:29:28 by komorebi          #+#    #+#             */
/*   Updated: 2026/11/06 12:13:11 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <sstream>
#include <stack>
#include <string>

#define GREEN "\033[92m"
#define RED "\033[91m"
#define CYAN "\033[96m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

static int g_passCount = 0;
static int g_failCount = 0;

template <typename T>
std::string toString(const T& value)
{
    std::ostringstream stream;
    stream << value;
    return (stream.str());
}

std::string toString(bool value)
{
    return (value ? "true" : "false");
}

void printHeader(const std::string& name)
{
    std::cout << "\n" << BOLD << CYAN << "[TEST] " << name << RESET << std::endl;
}

template <typename T>
void expectEqual(const std::string& label, const T& actual, const T& expected)
{
    if (actual == expected)
    {
        ++g_passCount;
        std::cout << GREEN << "[PASS] " << label
                  << " | expected: " << toString(expected)
                  << " | actual: " << toString(actual) << RESET << std::endl;
    }
    else
    {
        ++g_failCount;
        std::cout << RED << "[FAIL] " << label
                  << " | expected: " << toString(expected)
                  << " | actual: " << toString(actual) << RESET << std::endl;
    }
}

template <typename Iterator>
std::string rangeToString(Iterator begin, Iterator end)
{
    std::ostringstream stream;
    bool first = true;

    for (Iterator it = begin; it != end; ++it)
    {
        if (!first)
            stream << ' ';
        stream << *it;
        first = false;
    }
    return (stream.str());
}

void runComparisonTest()
{
    printHeader("Subject example: MutantStack and std::list output");
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    expectEqual("MutantStack top after push(5), push(17)",
                mstack.top(), 17);
    mstack.pop();
    expectEqual("MutantStack size after pop()", mstack.size(),
                static_cast<std::stack<int>::size_type>(1));
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::string mutantStackOrder = rangeToString(it, ite);
    expectEqual("MutantStack iteration order", mutantStackOrder,
                std::string("5 3 5 737 0"));

    std::stack<int> stackCopy(mstack);
    expectEqual("std::stack copy size", stackCopy.size(),
                static_cast<std::stack<int>::size_type>(5));
    expectEqual("std::stack copy top", stackCopy.top(), 0);

    std::list<int> values;
    values.push_back(5);
    values.push_back(17);
    expectEqual("std::list back after push_back(5), push_back(17)",
                values.back(), 17);
    values.pop_back();
    expectEqual("std::list size after pop_back()", values.size(),
                static_cast<std::list<int>::size_type>(1));
    values.push_back(3);
    values.push_back(5);
    values.push_back(737);
    values.push_back(0);

    std::list<int>::iterator listIt = values.begin();
    std::list<int>::iterator listEnd = values.end();
    ++listIt;
    --listIt;
    std::string listOrder = rangeToString(listIt, listEnd);
    expectEqual("std::list iteration order", listOrder,
                std::string("5 3 5 737 0"));
    expectEqual("std::list and MutantStack produce the same order",
                listOrder, mutantStackOrder);

    std::list<int> listCopy(values);
    expectEqual("std::list copy size", listCopy.size(),
                static_cast<std::list<int>::size_type>(5));
    expectEqual("std::list copy back", listCopy.back(), 0);
}

void runIteratorEdgeCaseTest()
{
    printHeader("Iterator edge cases");
    MutantStack<int> values;
    const MutantStack<int>& constValues = values;

    expectEqual("empty mutable forward range",
                values.begin() == values.end(), true);
    expectEqual("empty mutable reverse range",
                values.rbegin() == values.rend(), true);
    expectEqual("empty const forward range",
                constValues.begin() == constValues.end(), true);
    expectEqual("empty const reverse range",
                constValues.rbegin() == constValues.rend(), true);

    values.push(42);
    MutantStack<int>::iterator it = values.begin();
    MutantStack<int>::const_iterator constIt = constValues.begin();
    MutantStack<int>::reverse_iterator reverseIt = values.rbegin();
    MutantStack<int>::const_reverse_iterator constReverseIt = constValues.rbegin();

    expectEqual("single value through mutable iterator", *it, 42);
    expectEqual("single value through const iterator", *constIt, 42);
    expectEqual("single value through reverse iterator", *reverseIt, 42);
    expectEqual("single value through const reverse iterator", *constReverseIt, 42);
    ++it;
    ++constIt;
    ++reverseIt;
    ++constReverseIt;
    expectEqual("mutable iterator advances to end", it == values.end(), true);
    expectEqual("const iterator advances to end",
                constIt == constValues.end(), true);
    expectEqual("reverse iterator advances to rend",
                reverseIt == values.rend(), true);
    expectEqual("const reverse iterator advances to rend",
                constReverseIt == constValues.rend(), true);

    values.push(84);
    values.push(126);
    expectEqual("forward traversal", rangeToString(values.begin(), values.end()),
                std::string("42 84 126"));
    expectEqual("reverse traversal", rangeToString(values.rbegin(), values.rend()),
                std::string("126 84 42"));
    expectEqual("const forward traversal",
                rangeToString(constValues.begin(), constValues.end()),
                std::string("42 84 126"));
    expectEqual("const reverse traversal",
                rangeToString(constValues.rbegin(), constValues.rend()),
                std::string("126 84 42"));
}

void runStackAndCopyTest()
{
    printHeader("Stack operations and copying");
    MutantStack<int> original;
    expectEqual("new stack is empty", original.empty(), true);
    original.push(10);
    original.push(20);
    original.push(30);
    expectEqual("size after three pushes", original.size(),
                static_cast<std::stack<int>::size_type>(3));
    expectEqual("top after push(10), push(20), push(30)", original.top(), 30);

    MutantStack<int> constructedCopy(original);
    expectEqual("copy-constructed contents",
                rangeToString(constructedCopy.begin(), constructedCopy.end()),
                std::string("10 20 30"));

    MutantStack<int> assignedCopy;
    assignedCopy.push(-1);
    assignedCopy = original;
    expectEqual("copy-assigned contents",
                rangeToString(assignedCopy.begin(), assignedCopy.end()),
                std::string("10 20 30"));
    assignedCopy = assignedCopy;
    expectEqual("contents after self-assignment",
                rangeToString(assignedCopy.begin(), assignedCopy.end()),
                std::string("10 20 30"));

    constructedCopy.pop();
    constructedCopy.push(40);
    expectEqual("original remains unchanged after modifying copy",
                original.top(), 30);
    expectEqual("modified copy has new top", constructedCopy.top(), 40);
    expectEqual("modified copy retains same size", constructedCopy.size(),
                static_cast<std::stack<int>::size_type>(3));

    std::stack<int> standardCopy(original);
    expectEqual("converted std::stack size", standardCopy.size(),
                static_cast<std::stack<int>::size_type>(3));
    expectEqual("converted std::stack top", standardCopy.top(), 30);

    while (!original.empty())
        original.pop();
    expectEqual("stack is empty after popping all elements", original.empty(), true);
    expectEqual("size after popping all elements", original.size(),
                static_cast<std::stack<int>::size_type>(0));
}

int main(void)
{
    std::cout << BOLD << CYAN
              << "\n================ MUTANTSTACK TESTS ================"
              << RESET << std::endl;

    runComparisonTest();
    runIteratorEdgeCaseTest();
    runStackAndCopyTest();

    std::cout << "\n" << BOLD << CYAN
              << "================ SUMMARY ================"
              << RESET << std::endl;
    std::cout << GREEN << "Passed: " << g_passCount << RESET << std::endl;
    std::cout << RED << "Failed: " << g_failCount << RESET << std::endl;

    return (g_failCount == 0 ? 0 : 1);
}
