/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komorebi <komorebi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:36:01 by komorebi          #+#    #+#             */
/*   Updated: 2026/04/29 17:29:16 by komorebi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <sstream>

#define GREY "\033[90m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define YELLOW "\033[93m"
#define CYAN "\033[96m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

static int g_passCount = 0;
static int g_failCount = 0;

std::string toStr(unsigned int value)
{
	std::ostringstream oss;
	oss << value;
	return (oss.str());
}

void printHeader(const std::string &name)
{
	std::cout << "\n" << BOLD << CYAN << "[TEST] " << name << RESET << std::endl;
}

void pass(const std::string &msg)
{
	++g_passCount;
	std::cout << GREEN << "[PASS] " << msg << RESET << std::endl;
}

void fail(const std::string &msg)
{
	++g_failCount;
	std::cout << RED << "[FAIL] " << msg << RESET << std::endl;
}

void expectThrowLongest(Span &span, const std::string &name)
{
	try
	{
		span.longestSpan();
		fail(name + " longestSpan should throw");
	}
	catch (const std::exception &e)
	{
		std::cout << YELLOW << "[INFO] " << name << " longestSpan throw: " << e.what() << RESET << std::endl;
		pass(name + " longestSpan throws");
	}
}

void expectThrowShortest(Span &span, const std::string &name)
{
	try
	{
		span.shortestSpan();
		fail(name + " shortestSpan should throw");
	}
	catch (const std::exception &e)
	{
		std::cout << YELLOW << "[INFO] " << name << " shortestSpan throw: " << e.what() << RESET << std::endl;
		pass(name + " shortestSpan throws");
	}
}

void expectEq(const std::string &label, unsigned int got, unsigned int expected)
{
	if (got == expected)
		pass(label + " = " + toStr(got));
	else
		fail(label + " expected " + toStr(expected) + " got " + toStr(got));
}

int main(void)
{
	std::cout << BOLD << CYAN << "\n================ SPAN TESTS (SHORTEST/LONGEST) ================" << RESET << std::endl;

	printHeader("Size 0: both methods throw");
	{
		Span s0(5);
		expectThrowLongest(s0, "size0");
		expectThrowShortest(s0, "size0");
	}

	printHeader("Size 1: both methods throw");
	{
		Span s1(5);
		s1.addNumber(42);
		expectThrowLongest(s1, "size1");
		expectThrowShortest(s1, "size1");
	}

	printHeader("Size 2: basic span");
	{
		Span s2(5);
		s2.addNumber(4);
		s2.addNumber(11);
		expectEq("size2 longest", s2.longestSpan(), 7);
		expectEq("size2 shortest", s2.shortestSpan(), 7);
	}

	printHeader("Given hector-style values");
	{
		Span hectorLeCastor(5);
		hectorLeCastor.addNumber(2);
		hectorLeCastor.addNumber(5);
		hectorLeCastor.addNumber(32);
		hectorLeCastor.addNumber(64);
		hectorLeCastor.addNumber(-32);
		expectEq("hector longest", hectorLeCastor.longestSpan(), 96);
		expectEq("hector shortest", hectorLeCastor.shortestSpan(), 3);
	}

	printHeader("Duplicates: shortest should be zero");
	{
		Span dup(6);
		dup.addNumber(5);
		dup.addNumber(5);
		dup.addNumber(7);
		dup.addNumber(9);
		expectEq("duplicates shortest", dup.shortestSpan(), 0);
		expectEq("duplicates longest", dup.longestSpan(), 4);
	}

	printHeader("Negative and positive values");
	{
		Span mix(6);
		mix.addNumber(-10);
		mix.addNumber(-3);
		mix.addNumber(0);
		mix.addNumber(8);
		expectEq("mix longest", mix.longestSpan(), 18);
		expectEq("mix shortest", mix.shortestSpan(), 3);
	}

	printHeader("Reverse insertion order should not matter");
	{
		Span rev(5);
		rev.addNumber(9);
		rev.addNumber(6);
		rev.addNumber(3);
		rev.addNumber(0);
		expectEq("reverse longest", rev.longestSpan(), 9);
		expectEq("reverse shortest", rev.shortestSpan(), 3);
	}

	std::cout << "\n" << BOLD << CYAN << "================ SUMMARY ================" << RESET << std::endl;
	std::cout << GREEN << "Passed: " << g_passCount << RESET << std::endl;
	std::cout << RED << "Failed: " << g_failCount << RESET << std::endl;

	if (g_failCount != 0)
		return (1);
	return (0);
}