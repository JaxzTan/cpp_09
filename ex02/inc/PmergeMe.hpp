/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:29 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/21 10:05:21 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

# define GREEN_H "\033[0;32m" //constructor called
# define RESET_H "\033[0m"
# define RED_H "\033[0;31m" //destructor called
# define BLUE_H "\033[0;34m" // getrawbit
# define YELLOW_H "\033[0;33m" //N/A
# define PURPLE_H "\033[0;35m" //N/A

extern int numOfComparisons;

typedef std::string string;
enum error {
    INVALID_INPUT,
    FILE_NOT_FOUND,
    PARSE_ERROR,
    EMPTY_DATA
};

class PmergeMe{
    private:
        std::vector<int> _Vec;
        std::deque<int> _Deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void    	addElement(int element);

        void    	printVector() const;
        size_t		getVectorSize(void) const;
		std::string	strVec() const;
		std::vector<int>	&getVector(void) { return (_Vec); };
        void    	fordJohnsonSortVector(int unitSize);

    
        void    printDeque() const;
        size_t  getDequeSize(void) const;
		std::string	strDeque() const;
		std::deque<int>	&getDeque(void) { return (_Deq); };
        void    fordJohnsonSortDeque(int unitSize);


        bool    isValidNumber(const std::string &str);
        bool    ft_parse(int ac, char **av);

    };
    
long	jacobsthalGenerator(long n);
    
void    process_time(clock_t start, clock_t end, size_t size);
bool    ft_process(int ac, char **av);
void    ft_error(enum error err);
bool    check_num(long num);

template <typename T>
T advanceIter(T it, int steps)
{
	std::advance(it, steps);
	return (it);
}

template <typename T>
bool	compare(T left, T right)
{
	numOfComparisons++;
	return (*left < *right);
}

template <typename T>
void	swapUnits(T firstUnit, int unitSize)
{
	T	start = advanceIter(firstUnit, -unitSize + 1);
	T	end = advanceIter(start, unitSize);
	while (start != end)
	{
		std::iter_swap(start, advanceIter(start, unitSize));
		start++;
	}
}

template <typename T>
bool	isSorted(T &container)
{
	if (container.empty())
	{
		std::cerr << RED_H "empty container\n" << RESET_H;
		return (true);
	}

	typename T::iterator it = container.begin();
	typename T::iterator next = it;
	++next;
	for (; next != container.end(); ++it, ++next)
	{
		if (*it > *next)
			return (false);
	}
	return (true);
}
