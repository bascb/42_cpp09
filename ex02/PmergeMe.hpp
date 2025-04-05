/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:19:43 by bcastelo          #+#    #+#             */
/*   Updated: 2025/04/05 19:38:00 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int merge_insertion_with_vector(std::vector<unsigned int>& original);

int merge_insertion_with_list(std::list<unsigned int>& original);

int insert_into_vector(int argc, char **argv, std::vector<unsigned int>& numbers);

int insert_into_list(int argc, char **argv, std::list<unsigned int>& numbers);

void print_original(int argc, char **argv);

void print_vector(std::vector<unsigned int>& data, std::string label);

void print_list(std::list<unsigned int>& data, std::string label);

#endif