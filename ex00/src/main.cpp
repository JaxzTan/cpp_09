/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:50 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/27 16:53:07 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Error: Usage: " << av[0] << " <filename>" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    exchange.ft_process("data.csv", av[1]); // everything go in here
    return 0;
}
