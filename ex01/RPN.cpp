/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:17:18 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/25 11:42:45 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool valid_operator(char c);

bool validate_expression(std::string expression)
{
    for (std::string::iterator it=expression.begin(); it!=expression.end(); ++it)
	{
		if (!isdigit(*it) && !isspace(*it) && !valid_operator(*it))
			return (false);
	}
	return (true);
}

bool valid_operator(char c)
{
    std::string operators = "+-/*";

    if (operators.find(c) != std::string::npos)
        return (true);
    return (false);
}