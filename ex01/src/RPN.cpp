/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:51:56 by jaxztan           #+#    #+#             */
/*   Updated: 2025/08/21 14:14:58 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

bool err_msg(Error code)
{
    std::cerr << RED "Error RPN: " RESET;
    switch (code) 
    {
        case BAD_ARG: std::cerr << "Invalid argument. Expected => ./RPN \"2 3 +\"\n"; break;
        case BAD_EXPRESS: std::cerr << "Only allowed numbers and operator: + - * /\n"; break; 
        case FAIL_COMPUTE: std::cerr << "Cannot compute\n"; break;
    }
    return EXIT_FAILURE;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*'|| c == '/');
}
