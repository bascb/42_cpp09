/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:25:14 by bcastelo          #+#    #+#             */
/*   Updated: 2024/12/21 13:04:01 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
    BitcoinExchange prices;
    std::string line;
    
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }

    std::ifstream file(argv[1]);
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    file.close();
    return (0);
}