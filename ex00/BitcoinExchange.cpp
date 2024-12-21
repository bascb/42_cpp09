/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:55:59 by bcastelo          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:49 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
#ifdef DEBUG
    std::cout << "BitcoinExchange default constructor called" << std::endl;
#endif
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& src)
{
#ifdef DEBUG
    std::cout << "BitcoinExchange default copy constructor called" << std::endl;
#endif
	database = src.database;
}

BitcoinExchange& BitcoinExchange::operator=( const BitcoinExchange& src )
{
#ifdef DEBUG
	std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
#endif
	if (this != &src)
	{
		this->database = src.database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{
#ifdef DEBUG
	std::cout << "BitcoinExchange Destructor called" << std::endl;
#endif
}