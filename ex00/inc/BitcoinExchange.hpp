/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:52 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/15 21:05:33 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>

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
    NEGATIVE_VALUE
};

class BitcoinExchange {
    private:
        std::map<string, double> _Data;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        void                        ft_process(const string &filename, const string &inputFile);
        void                        ft_error(error err) const;
        std::map<string, double>    ft_get(const string &filename, char sep) const;
        bool                        is_valid_date(const std::string &date) const;
        double                      find(const std::string &_date) const;
        bool                        is_valid_value(const double &value) const;
    };
