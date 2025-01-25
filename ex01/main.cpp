/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:53:08 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/25 11:45:06 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
    std::string expression;
    if (argc != 2)
    {
        std::cerr << "Error: To few arguments" << std::endl;
        return (1);
    }

    expression = argv[1];
    if (!expression.size() || !validate_expression(expression))
    {
        std::cerr << "Error: invalid input." << std::endl;
        return (1);
    }
    std::cout << expression << std::endl;
    
    return (0);
}