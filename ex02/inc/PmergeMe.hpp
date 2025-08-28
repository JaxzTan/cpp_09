/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:21:29 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/27 20:21:45 by jaxztan          ###   ########.fr       */
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

class PmergeMe{
    private:
        std::vector<int> _Vec;
        std::deque<int> _Deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void addElement(int element);
        void sortVector();
        void sortDeque();
        void printVector() const;
        void printDeque() const;

        bool isValidNumber(const std::string &str);

};

enum error {
    INVALID_INPUT,
    FILE_NOT_FOUND,
    PARSE_ERROR,
    EMPTY_DATA
};

void ft_error(enum error err);