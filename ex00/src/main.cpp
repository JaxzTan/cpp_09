/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:50 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/08 14:26:05 by jaxztan          ###   ########.fr       */
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
    exchange.ft_process("data.csv", av[1]); // everything go in here
    return 0;
}
