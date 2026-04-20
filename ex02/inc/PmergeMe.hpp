/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:29 by jaxztan           #+#    #+#             */
/*   Updated: 2026/04/20 10:22:55 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define GREEN_H "\033[0;32m"
# define RESET_H "\033[0m"
# define RED_H "\033[0;31m"
# define BLUE_H "\033[0;34m"
# define YELLOW_H "\033[0;33m"
# define PURPLE_H "\033[0;35m"

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
        std::vector<int>	_Vec;
        std::deque<int>		_Deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void    			addElement(int element);

        void    			fordJohnsonSortVector(int unitSize);
        void    			printVector() const;
        size_t				getVectorSize(void) const;
		std::string			strVec() const;
		std::vector<int>	&getVector(void);
    
        void				printDeque() const;
        size_t				getDequeSize(void) const;
		std::string			strDeque() const;
		std::deque<int>		&getDeque(void);
        void				fordJohnsonSortDeque(int unitSize);


        bool    			isValidNumber(const std::string &str);
        bool			    ft_parse(int ac, char **av);

    };
    
long						jacobsthalGenerator(long n);
bool					    ft_process(int ac, char **av);
void					    ft_error(enum error err);

/**
 * @brief Advances an iterator by a given number of steps and returns the new iterator
 */
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

/**
 * @brief Swaps two adjacent units (blocks) of elements within a container.
 * 
 * This function is given an iterator to the last element of the first unit
 * and swaps every element in that unit with the corresponding element in the
 * immediately following (adjacent) unit.
 * 
 * @tparam T The type of the iterator.
 * @param firstUnit An iterator pointing to the last element of the first unit.
 * @param unitSize The number of elements in each unit.
 */
template <typename T>
void	swapUnits(T firstUnit, int unitSize) {
	T	start = advanceIter(firstUnit, - unitSize + 1);
	T	end = advanceIter(start, unitSize);
	while (start != end)
	{
		std::iter_swap(start, advanceIter(start, unitSize));
		start++;
	}
}

// simply check is the numbers inside container is sorted or not
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
