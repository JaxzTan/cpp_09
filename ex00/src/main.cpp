/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:40:50 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/15 18:55:52 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage: " << av[0] << " <filename>" << std::endl;
        return 1;
    }
    ft_process(av[1]);
    return 0;
}