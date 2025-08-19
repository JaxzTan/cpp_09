/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:49 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/19 12:44:52 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other) {
        _Data = other._Data;
        _InputData = other._InputData;
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::ft_get(const std::string &filename, char sep) const
{
    std::ifstream                   file(filename);
    std::map<std::string, double>   data;
    std::string                     line;

    if (!file.is_open())
        return(std::map<std::string, double>());
    // Skip the first line (header)
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string              date;
        std::string              value;
        std::getline(iss, date, sep);
        std::getline(iss, value);
        if (date.empty() || value.empty()) {
            ft_error(INVALID_INPUT);
        }
        data.insert(std::make_pair(date, std::stod(value)));
    }
    file.close();
    return(data);
}

void BitcoinExchange::ft_process(const string &filename, string inputFile)
{
    _Data = ft_get(filename, ',');
    _InputData = ft_get(inputFile, '|');

    if (_Data.empty() || _InputData.empty())
        ft_error(EMPTY_DATA); return;
    (void) inputFile;
}

int BitcoinExchange::ft_error(error err) const
{
    switch (err) {
        case INVALID_INPUT:
            std::cerr << "Invalid input." << std::endl;
            break;
        case FILE_NOT_FOUND:
            std::cerr << "File not found." << std::endl;
            break;
        case PARSE_ERROR:
            std::cerr << "Parse error." << std::endl;
            break;
        case EMPTY_DATA:
            std::cerr << "Empty data." << std::endl;
            break;
        default:
            std::cerr << "Unknown error." << std::endl;
            break;
    }
    return 1;
}

const char *BitcoinExchange::Invalid::what() const throw()
{
    return ("Don't ask me what is the error, DDDD");
}
