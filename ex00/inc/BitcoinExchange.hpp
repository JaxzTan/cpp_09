/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:52 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/21 13:07:32 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

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
        std::map<string, double> _InputData;
        double _Answer[];

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void    ft_process(const string &filename, string inputFile);
        void     ft_error(error err) const;
        std::map<string, double>    ft_get(const string &filename, char sep, bool trim) const;
        int                         check_valid_date(std::map<std::string, double>::const_iterator it) const;
        bool                        is_valid_date(const std::string &date) const;
        void                        printing(std::map<std::string, double>::const_iterator it) const;
        double                         find(const std::string &_date) const;

        class Invalid : public std::exception {
            public:
                virtual const char *what() const throw();
        };
    };
