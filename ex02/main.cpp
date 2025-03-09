/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:58 by bcastelo          #+#    #+#             */
/*   Updated: 2025/03/09 17:29:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Too few arguments" << std::endl;
        return (1);
    }

    for (int i = 0; i < 100; ++i)
    {
    if (sort_with_vector(argc, argv) == -1)
        return (1);
    }
    
    return (0);
}