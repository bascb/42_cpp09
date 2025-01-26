/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:17:18 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/26 17:20:06 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool execute_operation(std::stack<int>& operands, int type);

bool push_number(std::stack<int>& operands, std::string number_str);

int get_token_type(std::string token);

bool valid_operator(char c);

bool is_number(std::string str);

bool validate_expression(std::string expression)
{
    for (std::string::iterator it=expression.begin(); it!=expression.end(); ++it)
	{
		if (!isdigit(*it) && !isspace(*it) && !valid_operator(*it))
			return (false);
	}
	return (true);
}

bool process_expression(std::string expression)
{
    std::istringstream iss(expression);
    std::string token;
    int token_type;
    std::stack<int> operands;
    int result;
 
    while (iss >> token)
    {
        token_type = get_token_type(token);
        if (token_type == NUMBER)
        {
            if (!push_number(operands, token))
                return (false);
        }
        else
        {
            if (!execute_operation(operands, token_type))
                return (false);
        }
    }
    if (operands.size() != 1)
    {
        std::cerr << "Error: incorrect calculation." << std::endl;
        return (false);
    }
    result = operands.top();
    operands.pop();
    std::cout << result << std::endl;
    return (true);
}

bool execute_operation(std::stack<int>& operands, int type)
{
    int operand1;
    int operand2;
    int result;

    if (operands.size() < 2)
    {
        std::cerr << "Error: insufficient operands." << std::endl;
        return (false);
    }
    operand2 = operands.top();
    operands.pop();
    operand1 = operands.top();
    operands.pop();
    switch (type)
    {
        case SUM:
            result = operand1 + operand2;
            break;
        case SUBTRACTION:
            result = operand1 - operand2;
            break;
        case MULTIPLICATION:
            result = operand1 * operand2;
            break;
        case DIVISION:
            if (operand2 == 0)
            {
                std::cerr << "Error: Dviding by 0." << std::endl;
                return (false);
            }
            result = operand1 / operand2;
            break;
        default:
            std::cerr << "Error: invalid input." << std::endl;
            return (false);
    }
    operands.push(result);
    return (true);
}

bool push_number(std::stack<int>& operands, std::string number_str)
{
    std::stringstream convert_number(number_str);
    int number;
    
	convert_number >> number;
	if (convert_number.fail())
	{
        std::cerr << "Error: invalid input." << std::endl;
        return (false);
    }
    operands.push(number);
    return (true);
}

int get_token_type(std::string token)
{
    char operators[5] = "+-*/";

    if (token.size() == 1 && valid_operator(token[0]))
    {
        for (int i = 0; i < 4; ++i)
        {
            if (token[0] == operators[i])
                return i;
        }
    }
    if (is_number(token))
        return (NUMBER);
    return (INVALID_TOKEN);
}

bool valid_operator(char c)
{
    std::string operators = "+-*/";

    if (operators.find(c) != std::string::npos)
        return (true);
    return (false);
}

bool is_number(std::string str)
{
    std::string::iterator it = str.begin();

    if (str.size() > 1 && (*it == '+' || *it == '-'))
    {
        ++it;
    }
	while (it != str.end())
	{
		if (!isdigit(*it))
			return (false);
        ++it;
	}
	return (true);
}