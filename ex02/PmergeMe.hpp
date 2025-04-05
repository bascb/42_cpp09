/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:19:43 by bcastelo          #+#    #+#             */
/*   Updated: 2025/03/31 19:35:30 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm> 

int merge_insertion_with_vector(std::vector<unsigned int>& original);

int insert_into_vector(int argc, char **argv, std::vector<unsigned int>& numbers);

void print_original(int argc, char **argv);

void print_vector(std::vector<unsigned int>& data, std::string label);

#endif