/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chengsoo99@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:52 by jaxztan           #+#    #+#             */
/*   Updated: 2026/05/02 21:37:58 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef std::string string;

enum error{
    INVALID_INPUT,
    FILE_NOT_FOUND,
    PARSE_ERROR,
    EMPTY_DATA,
    NOT_POSITIVE,
    TOO_LARGE
};

class BitcoinExchange {
    private:
        std::map<string, float>	_Data;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        void					ft_process(const string &inputFile);
        void					ft_error(error err, const std::string &line = "") const;
        std::map<string, float>	ft_get(const string &filename) const;
        bool					is_valid_date(const std::string &date) const;
        float					find(const std::string &_date) const;
        bool					is_valid_value(const float &value) const;
    };
