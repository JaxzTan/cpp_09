/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:15:26 by jaxztan           #+#    #+#             */
/*   Updated: 2026/01/02 14:19:27 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int numOfComparisons = 0;

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other) {
        _Vec = other._Vec;
        _Deq = other._Deq;
    }
    return *this;
}

long	jacobsthalGenerator(long n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	long	prev = 0, curr = 1;
	for (long i = 2; i <= n; i++)
	{
		long	next = curr + 2 * prev;
		prev = curr;
		curr = next;
	}
	return (curr);	
}

void PmergeMe::addElement(int element)
{
    _Vec.push_back(element);
    _Deq.push_back(element);
}

void PmergeMe::printVector() const
{
    std::cout << "Vector: ";
    for(int i = 0; i < static_cast<int>(_Vec.size()); i++)
        std::cout << _Vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
    std::cout << "Deque: ";
    for(int i = 0; i < static_cast<int>(_Deq.size()); i++)
        std::cout << _Deq[i] << " ";
    std::cout << std::endl;
}

bool PmergeMe::isValidNumber(const string &str)
{
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void ft_error(enum error err)
{
    switch (err) {
        case INVALID_INPUT:
            std::cerr << "Error: Invalid input." << std::endl;
            break;
        case FILE_NOT_FOUND:
            std::cerr << "Error: File not found." << std::endl;
            break;
        case PARSE_ERROR:
            std::cerr << "Error: Argument Number Not Valid" << std::endl;
            break;
        case EMPTY_DATA:
            std::cerr << "Error: No valid data to ft_parse." << std::endl;
            break;
        default:
            std::cerr << "Error: Unknown error." << std::endl;
    }
    exit(EXIT_FAILURE);
}


bool PmergeMe::ft_parse(int ac, char **av)
{
    long num;
    for(int i = 1; i < ac; i++)
    {
        num = std::stol(av[i], NULL, 10); // to handle all num within positive int range
        if (num < 1 || num > INT_MAX)
        {
            ft_error(PARSE_ERROR);
            return false;
        }
        else
            addElement(static_cast<int>(num));
    }
    return true;
}

bool ft_process(int ac, char **av)
{
    PmergeMe pmerge;
    if (!pmerge.ft_parse(ac, av))
        return false;

    clock_t		dequeStartTime = clock(); // number of CPU clock ticks elapsed
    std::cout << BLUE_H << "[ DEQUE CONTAINER ]\n" << RESET_H;
    std::cout << YELLOW_H << "Before: " << pmerge.strDeque() << RESET_H << std::endl;
    pmerge.fordJohnsonSortDeque(1);
    std::cout << YELLOW_H << "After: " << pmerge.strDeque() << RESET_H << std::endl;
    clock_t		dequeEndTime = clock();
    if (!isSorted(pmerge.getDeque()))
    {
        std::cout << RED_H "Fatal: sequence not sorted: " ;
        pmerge.printDeque();
        exit(1);
    }
    std::cout << GREEN_H "Sorted successfully!" RESET_H << std::endl;
		double dequeTimeElapsed = static_cast<double>(dequeEndTime - dequeStartTime) / CLOCKS_PER_SEC * 1000000;
		std::cout << YELLOW_H "Time to process a range of " << pmerge.getDequeSize()
				<< " elements with std::deque: "
				<< dequeTimeElapsed << " us\n" RESET_H;
		std::cout << "Num of comparisons: " << numOfComparisons << std::endl;



    std::cout << std::endl << std::endl;



    numOfComparisons = 0;
    clock_t		vectorStartTime = clock(); // number of CPU clock ticks elapsed
    std::cout << BLUE_H << "[ VECTOR CONTAINER ]\n" << RESET_H;
    std::cout << YELLOW_H << "Before: " << pmerge.strVec() << RESET_H << std::endl;
    pmerge.fordJohnsonSortVector(1);
    std::cout << YELLOW_H << "After: " << pmerge.strVec() << RESET_H << std::endl;
    clock_t		vectorEndTime = clock();
    if (!isSorted(pmerge.getVector()))
    {
        std::cout << RED_H "Fatal: sequence not sorted: " ;
        pmerge.printVector();
        exit(1);
    }
    std::cout << GREEN_H "Sorted successfully!" RESET_H << std::endl;
		double vectorTimeElapsed = static_cast<double>(vectorEndTime - vectorStartTime) / CLOCKS_PER_SEC * 1000000;
		std::cout << YELLOW_H "Time to process a range of " << pmerge.getVectorSize()
				<< " elements with std::vector: "
				<< vectorTimeElapsed << " us\n" RESET_H;
		std::cout << "Num of comparisons: " << numOfComparisons << std::endl;

    return true;
}
