/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:58 by bcastelo          #+#    #+#             */
/*   Updated: 2025/03/16 16:29:21 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
    std::vector<unsigned int> sorted_vector;
    struct timespec start, end;
    
    if (argc < 2)
    {
        std::cerr << "Error: Too few arguments" << std::endl;
        return (1);
    }

    print_original(argc, argv);
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (!insert_into_vector(argc, argv, sorted_vector))
        return (-1);
    if (merge_insertion_with_vector(sorted_vector) == -1)
        return (1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector : " << diff_in_microseconds(start, end) << " us" << std::endl;
    print_vector(sorted_vector, "After : ");
    
    return (0);
}