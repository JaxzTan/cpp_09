/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:49 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/27 16:58:10 by jaxztan          ###   ########.fr       */
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
    }
    return *this;
}

std::map<std::string, double> BitcoinExchange::ft_get(const std::string &filename, char sep, bool trim) const
{
    std::ifstream                   file(filename);
    std::map<std::string, double>   data;
    std::string                     line;

    if (!file.is_open() || std::strcmp(filename.c_str(), "data.csv") != 0)
    {
        ft_error(FILE_NOT_FOUND);
        exit(EXIT_FAILURE);
    }
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        string              date;
        string              value;
        std::getline(iss, date, sep);
        std::getline(iss, value);

        if (trim == true && !date.empty() && !value.empty())
        {
            date = date.substr(0, date.length() - 1);
            value = value.substr(1, value.length());
        }
        if (date.empty() || value.empty())
            date = "0000-00-00", value = "0";
        data.insert(std::make_pair(date, std::stod(value)));
    }
    file.close();
    if (data.empty())
        ft_error(EMPTY_DATA);
    return(data);
}

static bool	isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool    BitcoinExchange::is_valid_date(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));
    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1] || (year == 2009 && month == 1 && day < 2))
        return false;

    return true;
}

bool BitcoinExchange::is_valid_value(const double &value) const
{
    if (value <= 0 || value > 1000)
        return false;
    return true;
}

double BitcoinExchange::find(const std::string &_date) const
{
    std::map<std::string, double>::const_iterator it = _Data.lower_bound(_date);

    if (it != _Data.end() && it->first == _date) {
        return it->second;
    }
    if (it == _Data.begin()) {
        return 0.0;
    }
    --it;
    return it->second;
}

void BitcoinExchange::ft_process(const string &filename, string inputFile)
{
    std::ifstream   file(inputFile);
    string          line;
    int             count_line = 0;

    _Data = ft_get(filename, ',', false);

    if (!file.is_open())
    {
        ft_error(FILE_NOT_FOUND);
        exit(EXIT_FAILURE);
    }
    std::cout << YELLOW << "Bitcoin Exchange Data:" << RESET << std::endl << std::endl;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::istringstream  iss(line);
        string              date;
        string              value;
        double              answer = 0.0;
    
        std::getline(iss, date, '|');
        std::getline(iss, value);

        if (!date.empty() && !value.empty())
        {
            date = date.substr(0, date.length() - 1);
            value = value.substr(1, value.length());
        }
        answer = find(date);
        count_line++;
        if (!is_valid_value(answer) || date.empty() || value.empty() || !is_valid_value(std::stod(value))
        || !is_valid_date(date))
        {
            ft_error(INVALID_INPUT);
            continue;
        }
        std::cout << date << " => " << value << " = " << (answer * std::stod(value)) << std::endl;
    }
    file.close();
    if (count_line == 0)
    {
        ft_error(EMPTY_DATA);
        exit(1);
    }
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
