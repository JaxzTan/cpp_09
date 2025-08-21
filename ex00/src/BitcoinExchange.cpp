/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:49 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/21 13:42:05 by jaxztan          ###   ########.fr       */
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

std::map<std::string, double> BitcoinExchange::ft_get(const std::string &filename, char sep, bool trim) const
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
            return(std::map<std::string, double>());
        }
        if (trim == true)
        {
            date = date.substr(0, date.length() - 1);
            value = value.substr(1, value.length());
        }
        data.insert(std::make_pair(date, std::stod(value)));
    }
    file.close();
    return(data);
}

bool BitcoinExchange::is_valid_date(const std::string &date) const
{
    // Check if the date is in the format YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    // Check if the year, month, and day are valid numbers
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue; // Skip dashes
        if (!isdigit(date[i]))
            return false;
    }
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31 || year == 0 || month == 0 || day == 0)
        return (false);
    std::cout << "Year: " << year << ", Month: " << month << ", Day: " << day << std::endl;
    return true;
}

int BitcoinExchange::check_valid_date(std::map<std::string, double>::const_iterator it) const
{
    std::cout << "3it is (" <<it->first << ")" << std::endl;
    if (!is_valid_date(it->first))
        ft_error(INVALID_INPUT);
}

void BitcoinExchange::printing(std::map<std::string, double>::const_iterator it) const
{
        std::cout << it->first << " ==> " << it->second << std::endl;
}

double BitcoinExchange::find(const std::string &_date) const
{
    std::map<std::string, double>::const_iterator it = _Data.begin();
    int year1 = std::stoi(_date.substr(0, 4));
    int month1 = std::stoi(_date.substr(5, 2));
    int day1 = std::stoi(_date.substr(8, 2));
    double res;
    std::string date;
    if (it != _Data.end()) {
        date = it->first;
        int year2 = std::stoi(date.substr(0, 4));
        int month2 = std::stoi(date.substr(5, 2));
        int day2 = std::stoi(date.substr(8, 2));
        if (year1 == year2 && month1 == month2 && day1 == day2)
            return (std::stod(_date));
    }
    // The rest of your logic here
    return(res);
}

void BitcoinExchange::ft_process(const string &filename, string inputFile)
{
    _Data = ft_get(filename, ',', false);
    _InputData = ft_get(inputFile.c_str(), '|', true);
    std::cout << "Bitcoin Exchange Data:" << std::endl;
    int i = 0;
    for(std::map<std::string, double>::const_iterator it = _InputData.begin(); it != _InputData.end(); ++it) {
        _Answer[i] = find(it->first);
        check_valid_date(it);
        printing(it);
        i++;
    }
    // for (std::map<std::string, double>::const_iterator it = _InputData.begin(); it != _InputData.end(); ++it) {
    //     std::cout << "4it is (" << it->first << ")" << "==>" << it->second << std::endl;
    // }
}

void    BitcoinExchange::ft_error(error err) const
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
            std::cerr << "Error: Empty data." << std::endl;
            break;
        default:
            std::cerr << "Error: Unknown error." << std::endl;
            break;
    }
}

const char *BitcoinExchange::Invalid::what() const throw()
{
    return ("Don't ask me what is the error, DDDD");
}
