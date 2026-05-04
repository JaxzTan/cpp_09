/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chengsoo99@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:49 by jaxztan           #+#    #+#             */
/*   Updated: 2026/05/02 21:53:58 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

// C++98 helper: convert string to int via istringstream
static int ft_stoi(const std::string &s)
{
    std::istringstream ss(s);
    int val;
    ss >> val;
    return val;
}

// C++98 helper: convert string to float via istringstream
static float ft_stof(const std::string &s)
{
    std::istringstream ss(s);
    float val;
    ss >> val;
    return val;
}

/**
 * @brief Reads Bitcoin exchange data from a CSV file and stores it in a map.
 */
std::map<std::string, float> BitcoinExchange::ft_get(const std::string &filename) const
{
    std::ifstream                   file(filename.c_str());
    std::map<std::string, float>    data;
    std::string                     line;
	char separator = ',';

    if (!file.is_open() || std::strcmp(filename.c_str(), "data.csv") != 0)
    {
        ft_error(FILE_NOT_FOUND);
        return (std::map<std::string, float>());
    }
    std::getline(file, line); // skip the first line

    while (std::getline(file, line)) {
        std::istringstream  iss(line);
        string              date;
        string              value;
        std::getline(iss, date, separator);
        std::getline(iss, value);

        if (date.empty() || value.empty())
            date = "0000-00-00", value = "0";
        data.insert(std::make_pair(date, ft_stof(value)));
    }
    file.close();
    return (data);
}

static bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::is_valid_date(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year  = ft_stoi(date.substr(0, 4));
    int month = ft_stoi(date.substr(5, 2));
    int day   = ft_stoi(date.substr(8, 2));

    if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1] || (year == 2009 && month == 1 && day < 2))
        return false;

    return true;
}

bool BitcoinExchange::is_valid_value(const float &value) const
{
    if (value < 0 || value > 1000)
        return false;
    return true;
}

/**
 * first use lower_bound to find the first element not less than the given date
 * if found and equal, return the value
 * if data earlier than the first date, return 0
 * else return the previous element's value
 */
float BitcoinExchange::find(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _Data.lower_bound(date);

    if (it != _Data.end() && it->first == date)
        return it->second;
    if (it == _Data.begin())
        return 0.0f;
    --it;
    return (it->second);
}

void BitcoinExchange::ft_error(error err, const std::string &line) const
{
    switch (err) {
        case INVALID_INPUT:
            std::cerr << "Error: bad input => " << line << std::endl;
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
        case NOT_POSITIVE:
            std::cerr << "Error: not a positive number." << std::endl;
            break;
        case TOO_LARGE:
            std::cerr << "Error: too large a number." << std::endl;
            break;
        default:
            std::cerr << "Error: Unknown error." << std::endl;
            break;
    }
}

void BitcoinExchange::ft_process(const string &inputFile)
{
    std::ifstream   file(inputFile.c_str());
    string          line;
    int             count_line = 0;

    _Data = ft_get("data.csv");

    if (!file.is_open() || _Data.empty())
    {
        ft_error(FILE_NOT_FOUND);
        return;
    }

    std::cout << YELLOW << "Bitcoin Exchange Data:" << RESET << std::endl << std::endl;
    std::getline(file, line); // skip the first line

    while (std::getline(file, line))
    {
        std::istringstream  iss(line);
        string              date;
        string              value;
        float               answer = 0.0f;
        float               input_value = 0.0f;

        std::getline(iss, date, '|');
        std::getline(iss, value);

        if (!date.empty() && !value.empty())
        {
            date = date.substr(0, date.length() - 1);
            value = value.substr(1, value.length());
        }
        count_line++;
        if (date.empty() || value.empty() || !is_valid_date(date))
        {
            ft_error(INVALID_INPUT, line);
            continue;
        }
        input_value = ft_stof(value);
        if (input_value < 0)
        {
            ft_error(NOT_POSITIVE);
            continue;
        }
        if (input_value > 1000)
        {
            ft_error(TOO_LARGE);
            continue;
        }
        answer = find(date);
        std::cout << date << " => " << value << " = " << (answer * input_value) << std::endl;
    }
    file.close();
    if (count_line == 0)
    {
        ft_error(EMPTY_DATA);
        return;
    }
}
