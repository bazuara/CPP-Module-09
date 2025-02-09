/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:28:43 by bazuara           #+#    #+#             */
/*   Updated: 2025/02/09 11:46:17 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
 private:
  std::stack<int> stack;
  bool isOperator(const std::string &token);
  int applyOperation(const std::string &op, int a, int b);

 public:
  RPN();
  int evaluate(const std::string &expression);
};

#endif
