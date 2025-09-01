/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:15:26 by jaxztan           #+#    #+#             */
/*   Updated: 2025/09/01 11:18:30 by jaxztan          ###   ########.fr       */
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

void PmergeMe::addElement(int element)
{
    _Vec.push_back(element);
    _Deq.push_back(element);
}

void PmergeMe::sortVector()
{
    std::sort(_Vec.begin(), _Vec.end());
}

void PmergeMe::sortDeque()
{
    std::sort(_Deq.begin(), _Deq.end());
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
            std::cerr << "Error: No valid data to process." << std::endl;
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

void PmergeMe::process(int ac, char **av)
{
    long num;
    for(int i = 1; i < ac; i++)
    {
        num = std::stol(av[i], NULL, 10);
        if (!check_num(num))
        {
            ft_error(PARSE_ERROR);
            exit(1);
        }
        else
            addElement(static_cast<int>(num));
    }
//     std::cout << "!!!" << std::endl << "start priting vector "<< std::endl;
//     for(std::vector<int>::iterator it = _Vec.begin(); it != _Vec.end(); ++it)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << "!!!" << std::endl << std::endl;
}
