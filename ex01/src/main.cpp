/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:52:00 by jaxztan           #+#    #+#             */
/*   Updated: 2025/10/21 11:22:26 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

int compute(int a, int b, char c)
{
    switch (c)
    {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            if (b == 0)
                std::exit(err_msg(FAIL_COMPUTE));
            return (a / b);
    }
    return (0);
}

int main(int ac, char **av)
{
    int a, b;
    std::list<int> list;

    if (ac != 2)
        return err_msg(BAD_ARG);
    str s = av[1];

    // Loop through the string
    for (size_t i = 0; i < s.size(); i++)
    {
        // If digit, convert and put to list
        if (isdigit(s[i]))
            list.push_back(s[i] - '0');

        // If operator, pop 2 elements (ensure have 2 elements) 
        //  => compute => push back to list
        else if (isOperator(s[i]))
        {
            if (list.size() < 2)
                return (err_msg(FAIL_COMPUTE));

            b = list.back();
            list.pop_back();
            a = list.back();
            list.pop_back();
            list.push_back(compute(a, b, s[i]));
            if (list.size() != 1)
                return (err_msg(EXTRA_ELEMENT));

        }

        else if (s[i] == ' ')
            continue;
        else
            return (err_msg(BAD_EXPRESS));
    }

    // Validate final result
    if (list.size() != 1)
        return err_msg(BAD_EXPRESS);
    std::cout << list.back() << "\n";
}
