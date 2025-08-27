/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:52 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/27 16:31:48 by jaxztan          ###   ########.fr       */
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
    EMPTY_DATA
};

class BitcoinExchange {
    private:
        // error _error;
        std::map<string, double> _Data;
        // std::map<string, double> _InputData;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        int                        ft_process(const string &filename, string inputFile);
        void                        ft_error(error err) const;
        std::map<string, double>    ft_get(const string &filename, char sep, bool trim) const;
        bool                        is_valid_date(const std::string &date) const;
        double                      find(const std::string &_date) const;
        bool                        is_valid_value(const double &value) const;
    };
