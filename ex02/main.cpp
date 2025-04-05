/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:58 by bcastelo          #+#    #+#             */
/*   Updated: 2025/03/31 19:38:51 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <time.h>
#include "PmergeMe.hpp"

double diff_in_microseconds(clock_t start, clock_t end) {
    return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0);
}

int	main(int argc, char **argv)
{
    std::vector<unsigned int> sorted_vector;
    clock_t start, end;
    
    if (argc < 2)
    {
        std::cerr << "Error: Too few arguments" << std::endl;
        return (1);
    }

    print_original(argc, argv);
    start = clock();
    if (!insert_into_vector(argc, argv, sorted_vector))
        return (-1);
    if (merge_insertion_with_vector(sorted_vector) == -1)
        return (1);
    end = clock();
    std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector : " << diff_in_microseconds(start, end) << " us" << std::endl;
    print_vector(sorted_vector, "After : ");
    
    return (0);
}