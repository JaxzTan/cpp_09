/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:51:25 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/21 11:22:20 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <list>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

typedef std::string str;

enum Error {
    BAD_ARG,
    BAD_EXPRESS,
    FAIL_COMPUTE,
    EXTRA_ELEMENT
};

bool err_msg(Error code);
bool isOperator(char c);
