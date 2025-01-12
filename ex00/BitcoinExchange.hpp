/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:39:08 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/12 17:32:59 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
#include <exception>
#include <cctype>

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& );
        BitcoinExchange& operator=( const BitcoinExchange& );
        ~BitcoinExchange( void );
        void initDatabase( std::string );
        void printEntryValue( std::string );
        class FileErrorException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class DatabaseEntryException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
    private:
        std::map<std::string,float> database;
};

bool invalid_date( std::string );
bool invalid_year( std::string );
bool invalid_month( std::string );
bool invalid_day( std::string );

#endif