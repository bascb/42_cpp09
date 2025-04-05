/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:22:23 by bcastelo          #+#    #+#             */
/*   Updated: 2025/04/05 20:24:05 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void binary_insertion_with_vector(std::vector<unsigned int>& numbers, unsigned int nbr);

void linear_insertion_with_list(std::list<unsigned int>& numbers, unsigned int nbr);

bool push_number_to_vector(std::vector<unsigned int>& numbers, std::string number_str);

bool push_number_to_list(std::list<unsigned int>& numbers, std::string number_str);

bool is_all_digits(std::string str);

bool is_duplicated_in_vector(std::vector<unsigned int>& data, unsigned int value);

bool is_duplicated_in_list(std::list<unsigned int>& data, unsigned int value);

int merge_insertion_with_vector(std::vector<unsigned int>& original)
{
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    std::vector<unsigned int>::iterator it;
    
    if (original.size() <= 1)
        return (0);
    for (it = original.begin(); it + 1 < original.end(); it += 2)
    {
        if (*it > *(it + 1))
        {
            main.push_back(*it);
            pend.push_back(*(it + 1));
        }
        else
        {
            main.push_back(*(it + 1));
            pend.push_back(*it);
        }
    }
    merge_insertion_with_vector(main);
    if (original.size() % 2 == 1)
        pend.push_back(*(original.end() - 1));
    for (it = pend.begin(); it < pend.end(); ++it)
    {
        binary_insertion_with_vector(main, *it);
    }
    original = main;
    return (0);
}

int merge_insertion_with_list(std::list<unsigned int>& original)
{
    std::list<unsigned int> main;
    std::list<unsigned int> pend;
    std::list<unsigned int>::iterator first = original.begin();
    std::list<unsigned int>::iterator second = original.begin();
    
    if (original.size() <= 1)
        return (0);
    ++second;
    while (first != original.end() && second != original.end())
    {
        if (*first > *second)
        {
            main.push_back(*first);
            pend.push_back(*second);
        }
        else
        {
            main.push_back(*second);
            pend.push_back(*first);
        }
        ++first;
        ++first;
        ++second;
        ++second;
    }
    merge_insertion_with_list(main);
    if (original.size() % 2 == 1)
    {
        second = original.end();
        --second;
        pend.push_back(*second);
    }
    for (first = pend.begin(); first != pend.end(); ++first)
    {
        linear_insertion_with_list(main, *first);
    }
    original = main;
    return (0);
}

void binary_insertion_with_vector(std::vector<unsigned int>& numbers, unsigned int nbr)
{
    std::vector<unsigned int>::iterator left = numbers.begin();
    std::vector<unsigned int>::iterator right = numbers.end() - 1;
    std::vector<unsigned int>::iterator mid;

    if (!numbers.size())
    {
        numbers.push_back(nbr);
        return ;
    }

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (*mid > nbr)
            right = mid - 1;
        else
            left = mid + 1;
    }
    numbers.insert(left, nbr);
}

void linear_insertion_with_list(std::list<unsigned int>& numbers, unsigned int nbr)
{
    std::list<unsigned int>::iterator it = numbers.begin();

    while (it != numbers.end() && *it < nbr)
        ++it;
    numbers.insert(it, nbr);
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

int insert_into_list(int argc, char **argv, std::list<unsigned int>& numbers)
{
    int counter = 0;
    
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string token;

        while (iss >> token)
        {
            if (iss.fail() || !is_all_digits(token) || !push_number_to_list(numbers, token))
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

bool push_number_to_list(std::list<unsigned int>& numbers, std::string number_str)
{
    std::stringstream convert_number(number_str);
    unsigned int number;
    
	convert_number >> number;
   if (convert_number.fail() || is_duplicated_in_list(numbers, number))
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

bool is_duplicated_in_list(std::list<unsigned int>& data, unsigned int value)
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

void print_list(std::list<unsigned int>& data, std::string label)
{
    std::cout << label;
    for (std::list<unsigned int>::iterator it=data.begin(); it!=data.end(); ++it)
    {
        std::cout << *it << " ";   
    }
    std::cout << std::endl;
}

void print_original(int argc, char **argv)
{
    std::cout << "Before : "; 
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl; 
}
