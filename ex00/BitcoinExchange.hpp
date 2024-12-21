/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:39:08 by bcastelo          #+#    #+#             */
/*   Updated: 2024/12/21 13:02:19 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange( void );
        BitcoinExchange( const BitcoinExchange& );
        BitcoinExchange& operator=( const BitcoinExchange& );
        ~BitcoinExchange( void );
    private:
        std::map<char,float> database;
};

#endif