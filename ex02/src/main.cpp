/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:19:22 by jaxztan           #+#    #+#             */
/*   Updated: 2025/09/01 11:17:45 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 3)
        ft_error(INVALID_INPUT);
    PmergeMe apakabar;
    apakabar.process(ac, av);
    apakabar.sortVector();
    apakabar.sortDeque();
    apakabar.printVector();
    apakabar.printDeque();
    return 0;
}
