/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:29:22 by bazuara           #+#    #+#             */
/*   Updated: 2025/02/09 11:46:08 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>
#include <cstdlib>

RPN::RPN() {}

bool RPN::isOperator(const std::string &token) {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(const std::string &op, int a, int b) {
  if (op == "+") return a + b;
  if (op == "-") return a - b;
  if (op == "*") return a * b;
  if (op == "/") {
    if (b == 0) {
      throw std::runtime_error("Error: Division by zero");
    }
    return a / b;
  }
  throw std::runtime_error("Error: Invalid operator");
}

int RPN::evaluate(const std::string &expression) {
  std::istringstream iss(expression);
  std::string token;
  while (iss >> token) {
    if (isdigit(token[0])) {
      stack.push(std::atoi(token.c_str()));
    } else if (isOperator(token)) {
      if (stack.size() < 2) {
        throw std::runtime_error("Error: Not enough operands");
      }
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();
      stack.push(applyOperation(token, a, b));
    } else {
      throw std::runtime_error("Error: Invalid token");
    }
  }
  if (stack.size() != 1) {
    throw std::runtime_error("Error: Malformed expression");
  }
  return stack.top();
}
