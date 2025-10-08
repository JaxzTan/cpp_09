/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:19:22 by jaxztan           #+#    #+#             */
/*   Updated: 2025/09/01 11:52:30 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 3)
        ft_error(INVALID_INPUT);
    if (!ft_process(ac, av))
        return (1);
    return 0;
}
