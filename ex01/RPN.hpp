/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:01:26 by bcastelo          #+#    #+#             */
/*   Updated: 2025/01/26 00:55:44 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stack>

#define SUM 0
#define SUBTRACTION 1
#define MULTIPLICATION 2
#define DIVISION 3
#define NUMBER 4
#define INVALID_TOKEN 5

bool validate_expression(std::string expression);

bool process_expression(std::string expression);

#endif
