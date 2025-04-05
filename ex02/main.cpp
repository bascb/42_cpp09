/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:58 by bcastelo          #+#    #+#             */
/*   Updated: 2025/04/05 17:53:35 by bcastelo         ###   ########.fr       */
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
    double vector_time;
    
    if (argc < 2)
    {
        std::cerr << "Error: Too few arguments" << std::endl;
        return (1);
    }

    start = clock();
    if (!insert_into_vector(argc, argv, sorted_vector))
        return (1);
    if (merge_insertion_with_vector(sorted_vector) == -1)
        return (1);
    end = clock();
    vector_time = diff_in_microseconds(start, end);
    print_original(argc, argv);
    print_vector(sorted_vector, "After : ");
    std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector : " << vector_time << " us" << std::endl;
    
    return (0);
}