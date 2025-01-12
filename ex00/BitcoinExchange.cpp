/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 12:55:59 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/12 17:44:57 by bcastelo         ###   ########.fr       */
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

void BitcoinExchange::initDatabase( std::string file_path)
{
	std::string line;
	std::string date;
	std::string value;
	std::size_t delimiter_pos;
	std::size_t space_pos;
	float fl_value;
	
	std::ifstream file(file_path.c_str());
	if (!file.is_open())
    	throw BitcoinExchange::FileErrorException();

	while (std::getline(file, line))
    {
		delimiter_pos = line.find(',');
		if (delimiter_pos != std::string::npos)
		{
			date = line.substr (0, delimiter_pos);
			if (date == "date")
				continue;
			value = line.substr (delimiter_pos);
			value.erase(0, 1);
			while ((space_pos = date.find(' ')) != std::string::npos)
        		date.erase(space_pos, 1);
			while ((space_pos = value.find(' ')) != std::string::npos)
        		value.erase(space_pos, 1);
			if (date.empty() || value.empty())
			{
				file.close();
				throw BitcoinExchange::DatabaseEntryException();
			}
			std::stringstream convert_value(value);
			convert_value >> fl_value;
			if (invalid_date(date) || convert_value.fail())
			{
				file.close();
				throw BitcoinExchange::DatabaseEntryException();
			}
			database.insert(std::pair<std::string,float>(date, fl_value));
		}
		else
		{
			file.close();
			throw BitcoinExchange::DatabaseEntryException();
		}
    }
	file.close();
}

void BitcoinExchange::printEntryValue( std::string entry )
{
	std::string date;
	std::string value;
	std::size_t delimiter_pos;
	std::size_t space_pos;
	float fl_value;
	float total_amount;
	std::map<std::string,float>::iterator it;

	delimiter_pos = entry.find('|');
	if (delimiter_pos == std::string::npos)
	{
		std::cout << "Error: bad input => " << entry << std::endl;
		return ;
	}
	date = entry.substr (0, delimiter_pos);
	value = entry.substr (delimiter_pos);
	value.erase(0, 1);
	while ((space_pos = date.find(' ')) != std::string::npos)
        date.erase(space_pos, 1);
	if (date == "date")
		return ;
	while ((space_pos = value.find(' ')) != std::string::npos)
        value.erase(space_pos, 1);
	if (date.empty() || value.empty())
	{
		std::cout << "Error: bad input => " << entry << std::endl;
		return ;
	}
	if (invalid_date(date))
	{
		std::cout << "Error: bad input => " << entry << std::endl;
		return ;
	}
	std::stringstream convert_value(value);
	convert_value >> fl_value;
	if (convert_value.fail())
	{
		std::cout << "Error: invalid value" << std::endl;
		return ;
	}
	if (fl_value < 0 || fl_value > 1000.0)
	{
		if (fl_value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	it = database.lower_bound(date);
	if (it == database.begin() && date != it->first)
	{
		std::cout << "Error: no exchange rate for date " << date << std::endl;
		return ;
	}
	else if (it == database.end() || date != it->first)
		--it;
	total_amount = fl_value * it->second;
	std::cout << date << " " << " => " << value << " = ";
	if (total_amount > 100000.0)
		std::cout << std::fixed << std::setprecision(2) << total_amount << std::endl;
	else
		std::cout << total_amount << std::endl;
}

const char *BitcoinExchange::FileErrorException::what(void) const throw()
{
	return ("Unable to open database file!");
}

const char *BitcoinExchange::DatabaseEntryException::what(void) const throw()
{
	return ("Bad database entry!");
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

bool invalid_date( std::string date)
{
	std::string year_str;
	std::string month_str;
	std::string day_str;
	std::stringstream date_stream(date);
	std::size_t delimiter_pos = 0;
	int del_nbr = 0;

	while ((delimiter_pos = date.find('-', delimiter_pos)) != std::string::npos)
	{
		++del_nbr;
		++delimiter_pos;
	}

	if (del_nbr != 2)
		return (true);

	std::getline(date_stream, year_str, '-');
	std::getline(date_stream, month_str, '-');
	std::getline(date_stream, day_str, '-');

	if (invalid_year(year_str) || invalid_month(month_str) || invalid_day(day_str))
		return (true);
	
	return (false);
}

bool invalid_year( std::string year_str)
{
	int year;
	std::stringstream year_stream(year_str);
	
	if (!is_all_digits(year_str))
		return (true);
	year_stream >> year;
	if (year_stream.fail() || year < 2009)
		return (true);
	return (false);
}

bool invalid_month( std::string month_str)
{
	int month;
	std::stringstream month_stream(month_str);
	
	if (!is_all_digits(month_str))
		return (true);
	month_stream >> month;
	if (month_stream.fail() || month < 1 || month > 12)
		return (true);
	return (false);
}

bool invalid_day( std::string day_str)
{
	int day;
	std::stringstream day_stream(day_str);
	
	if (!is_all_digits(day_str))
		return (true);
	day_stream >> day;
	if (day_stream.fail() || day < 1 || day > 31)
		return (true);
	return (false);
}