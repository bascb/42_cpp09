/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:22:23 by bcastelo          #+#    #+#             */
/*   Updated: 2025/02/04 23:08:36 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int insert_into_vector(int argc, char **argv, std::vector<unsigned int>& numbers);

bool push_number_to_vector(std::vector<unsigned int>& numbers, std::string number_str);

bool is_all_digits(std::string str);

bool is_duplicated_in_vector(std::vector<unsigned int>& data, unsigned int value);

void print_vector(std::vector<unsigned int>& data, std::string label);

double getTimeInMicroseconds(void);

int sort_with_vector(int argc, char **argv)
{
    std::vector<unsigned int> unordered;
    double start;
    double end;
     
    start = getTimeInMicroseconds();
    if (!insert_into_vector(argc, argv, unordered))
        return (-1);
    end = getTimeInMicroseconds();
    print_vector(unordered, "Before : ");
    std::cout << "Time to process a range of " << unordered.size() << " elements with std::vector : " << end - start << " us" << std::endl;
    return (0);
}

int insert_into_vector(int argc, char **argv, std::vector<unsigned int>& numbers)
{
    int counter = 0;
    
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string token;

        while (iss >> token)
        {
            if (iss.fail() || !is_all_digits(token) || !push_number_to_vector(numbers, token))
	        {
		        std::cerr << "Error: invalid input." << std::endl;
		        return (0);
	        }
            ++counter;
        }
    }
    return (counter);
}

bool push_number_to_vector(std::vector<unsigned int>& numbers, std::string number_str)
{
    std::stringstream convert_number(number_str);
    unsigned int number;
    
	convert_number >> number;
	if (convert_number.fail() || is_duplicated_in_vector(numbers, number))
        return (false);
    numbers.push_back(number);
    return (true);
}

bool is_all_digits(std::string str)
{
	for ( std::string::iterator it=str.begin(); it!=str.end(); ++it)
	{
		if (!isdigit(*it))
			return (false);
	}
	return (true);
}

bool is_duplicated_in_vector(std::vector<unsigned int>& data, unsigned int value)
{
    if (std::find(data.begin(), data.end(), value) != data.end())
        return (true);
    return (false);
}

void print_vector(std::vector<unsigned int>& data, std::string label)
{
    std::cout << label;
    for (std::vector<unsigned int>::iterator it=data.begin(); it!=data.end(); ++it)
    {
        std::cout << *it << " ";   
    }
    std::cout << std::endl;
}

double getTimeInMicroseconds(void)
{
    struct timespec ts;
    
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000000 + ts.tv_nsec / 1000.0);
}