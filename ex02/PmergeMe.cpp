/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:22:23 by bcastelo          #+#    #+#             */
/*   Updated: 2025/03/15 11:38:48 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void sort_pairs_with_vector(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end, unsigned int set_size);

void sort_all_pairs_with_vector(std::vector<unsigned int>& data, std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end);

unsigned int binary_insertion_with_vector(std::vector<unsigned int>& numbers, unsigned int nbr);

void sort_larger_elements_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend, std::vector<unsigned int>& original);

void insert_into_main_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend);

void insert_to_main_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend);

int insert_into_vector(int argc, char **argv, std::vector<unsigned int>& numbers);

bool push_number_to_vector(std::vector<unsigned int>& numbers, std::string number_str);

bool is_all_digits(std::string str);

bool is_duplicated_in_vector(std::vector<unsigned int>& data, unsigned int value);

void print_vector(std::vector<unsigned int>& data, std::string label);

void print_original(int argc, char **argv);

double get_time_microseconds(void);

double diff_in_microseconds(struct timespec start, struct timespec end);

void print_diff_time(std::string step, struct timespec start, struct timespec end);

std::vector<unsigned int> fordJohnsonSort(std::vector<unsigned int> arr);

int merge_insertion_with_vector(int argc, char **argv)
{
    std::vector<unsigned int> original;
    std::vector<unsigned int> main;
    std::vector<unsigned int> pend;
    struct timespec start, end;

    //print_original(argc, argv);
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (!insert_into_vector(argc, argv, original))
        return (-1);
    sort_pairs_with_vector(original.begin(), original.end(), 1);
    sort_larger_elements_with_vector(main, pend, original);
    insert_into_main_with_vector(main, pend);
    clock_gettime(CLOCK_MONOTONIC, &end);
    //print_vector(main, "After : ");
    std::cout << "Time to process a range of " << original.size() << " elements with std::vector : " << diff_in_microseconds(start, end) << " us" << std::endl;
    return (0);
}

void sort_pairs_with_vector(std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end, unsigned int set_size)
{
    unsigned int aux;
    unsigned int pair_size = set_size * 2;
    std::vector<unsigned int>::iterator init = start;
    
    while (init + pair_size - 1 < end)
    {
        if (*(init + set_size - 1) > *(init + pair_size - 1))
        {
            for (std::vector<unsigned int>::iterator it = init; it < init + set_size; ++it)
            {
                aux = *it;
                *it = *(it + set_size);
                *(it + set_size) = aux;
            }
        }
        init += pair_size;
    }
    //if (set_size < end - start)
    //    sort_pairs_with_vector(start, end, set_size * 2);
}

void sort_all_pairs_with_vector(std::vector<unsigned int>& data, std::vector<unsigned int>::iterator start, std::vector<unsigned int>::iterator end)
{
    std::vector<unsigned int>::iterator exte;
    std::vector<unsigned int>::iterator inte;
    unsigned int aux;
    
    for (exte = start + 1; exte + 2 < end; exte += 2)
    {
        for (inte = exte + 2; inte < end; inte += 2)
        {
            if (*exte > *inte)
            {
                aux = *exte;
                *exte = *inte;
                *inte = aux;
                aux = *(exte - 1);
                *(exte - 1) = *(inte - 1);
                *(inte - 1) = aux;
            }
            print_vector(data, "Sorting : ");
        }
    }
}

unsigned int binary_insertion_with_vector(std::vector<unsigned int>& numbers, unsigned int nbr)
{
    std::vector<unsigned int>::iterator left = numbers.begin();
    std::vector<unsigned int>::iterator right = numbers.end() - 1;
    std::vector<unsigned int>::iterator mid;
    unsigned int pos;

    if (!numbers.size())
    {
        numbers.push_back(nbr);
        return (0);
    }

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (*mid > nbr)
            right = mid - 1;
        else
            left = mid + 1;
    }
    pos = left - numbers.begin();
    numbers.insert(left, nbr);
    return (pos);
}

void sort_larger_elements_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend, std::vector<unsigned int>& original)
{
    std::vector<unsigned int>::iterator it;
    unsigned int pos;

    for (it = original.begin() + 1; it < original.end(); it += 2)
    {
        pos = binary_insertion_with_vector(main, *it);
        if (!pend.size() || pend.begin() + pos >= pend.end())
            pend.push_back(*(it - 1));
        else
            pend.insert(pend.begin() + pos, *(it - 1));
    }
    if (original.size() % 2 ==1)
        pend.push_back(*(it - 1));
    main.insert(main.begin(), *(pend.begin()));
    pend.erase(pend.begin());
}

void insert_into_main_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend)
{
    std::vector<unsigned int>::iterator it;
    std::vector<unsigned int>::iterator mid = pend.begin() + (pend.end() - 1 - pend.begin()) / 2;

    for (it = pend.begin() + 1; it < mid; it += 2)
    {
        binary_insertion_with_vector(main, *it);
        binary_insertion_with_vector(main, *(it - 1));
    }
    for (it = pend.end() - 1; it >= mid; --it)
    {
        binary_insertion_with_vector(main, *it);
    }
}

void insert_to_main_with_vector(std::vector<unsigned int>& main, std::vector<unsigned int>& pend)
{
    for (std::vector<unsigned int>::iterator it = pend.begin(); it < pend.end(); ++it)
    {
        binary_insertion_with_vector(main, *it);
        pend.erase(it);
    }
    if (pend.size())
        insert_to_main_with_vector(main, pend);
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
            if (!push_number_to_vector(numbers, argv[i]))
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

void print_original(int argc, char **argv)
{
    std::cout << "Before : "; 
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl; 
}

double get_time_microseconds(void)
{
    struct timespec ts;
    
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000000 + ts.tv_nsec / 1000.0);
}

double diff_in_microseconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1.0e6 + (end.tv_nsec - start.tv_nsec) / 1.0e3;
}

void print_diff_time(std::string step, struct timespec start, struct timespec end)
{
    std::cout << step << " : " << diff_in_microseconds(start, end) << std::endl;
}

// Function to insert an element into a sorted sequence with minimal comparisons
void mergeInsert(std::vector<unsigned int>& sorted, unsigned int element) {
    int left = 0, right = sorted.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (element < sorted[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    sorted.insert(sorted.begin() + left, element);
}

// Ford-Johnson sorting function
std::vector<unsigned int> fordJohnsonSort(std::vector<unsigned int> arr) {
    if (arr.size() <= 1) return arr;

    std::vector<unsigned int> sorted;
    
    // Initial pairing and sorting
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        unsigned int a = std::min(arr[i], arr[i + 1]);
        unsigned int b = std::max(arr[i], arr[i + 1]);
        if (sorted.empty() || b >= sorted.back()) {
            sorted.push_back(a);
            sorted.push_back(b);
        } else {
            mergeInsert(sorted, a);
            mergeInsert(sorted, b);
        }
    }

    // Handle the last unpaired element (if size is odd)
    if (arr.size() % 2 == 1) {
        mergeInsert(sorted, arr.back());
    }

    return sorted;
}
