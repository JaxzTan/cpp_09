/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:15:26 by jaxztan           #+#    #+#             */
/*   Updated: 2025/09/08 09:57:17 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

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

void process_time(clock_t start, clock_t end, size_t size)
{
    double time;
    
    time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "\nSorting time for " << size << " elements is = " << time << " µs\n";
}

void PmergeMe::addElement(int element)
{
    _Vec.push_back(element);
    _Deq.push_back(element);
}

void PmergeMe::printVector() const
{
    std::cout << "Vector: ";
    for(std::vector<int>::const_iterator it = _Vec.begin(); it != _Vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque() const
{
    std::cout << "Deque: ";
    for(std::deque<int>::const_iterator it = _Deq.begin(); it != _Deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
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
            std::cerr << "Error: Parse error." << std::endl;
            break;
        case EMPTY_DATA:
            std::cerr << "Error: No valid data to ft_parse." << std::endl;
            break;
        default:
            std::cerr << "Error: Unknown error." << std::endl;
    }
    exit(EXIT_FAILURE);
}

bool check_num(long num)
{
    if (num < INT_MIN || num > INT_MAX)
        return false;
    return true;
}

bool PmergeMe::ft_parse(int ac, char **av)
{
    long num;
    for(int i = 1; i < ac; i++)
    {
        num = std::stol(av[i], NULL, 10);
        if (!check_num(num))
        {
            ft_error(PARSE_ERROR);
            return false;
        }
        else
            addElement(static_cast<int>(num));
    }
    return true;
}
    // std::cout << "Before: ";
    // for(int i = 1; i < ac; i++)
    // {
    //     std::cout << av[i] << " ";
    // }
    // std::sort(_Vec.begin(), _Vec.end());
    // std::cout << std::endl << "After: ";
    // for(int i = 0; i < ac - 1; i++)
    // {
    //     std::cout << _Vec[i] << " ";
    // }
    // std::cout << std::endl;
//     std::cout << "!!!" << std::endl << "start priting vector "<< std::endl;
//     for(std::vector<int>::iterator it = _Vec.begin(); it != _Vec.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << "!!!" << std::endl << std::endl;

bool ft_process(int ac, char **av)
{
    PmergeMe apakabar;
    if (!apakabar.ft_parse(ac, av))
        return false;
    apakabar.sort();
    std::cout << YELLOW_H << "Before: " << RESET_H << std::endl;
    for(int i = 1; i < ac; i++)
    {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << PURPLE_H << "After: " << RESET_H << std::endl;
    apakabar.fordJohnsonSortVector(apakabar.getVectorSize());
    apakabar.fordJohnsonSortDeque(apakabar.getDequeSize());
    apakabar.printVector();
    apakabar.printDeque();
    return true;
}
