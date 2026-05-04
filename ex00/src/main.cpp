/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chengsoo99@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:50 by jaxztan           #+#    #+#             */
/*   Updated: 2026/05/02 21:36:21 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << RED << "Error: " << YELLOW << "Usage: " << av[0] << " <filename>" << RESET << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.ft_process(av[1]); // everything go in here
    return 0;
}
