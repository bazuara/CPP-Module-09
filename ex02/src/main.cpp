/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:16:04 by bazuara           #+#    #+#             */
/*   Updated: 2025/04/01 10:55:36 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::vector<int> vectorInput;
  std::deque<int> dequeInput;

  for (int i = 1; i < argc; ++i) {
    char *end;
    long val = std::strtol(argv[i], &end, 10);

    if (*end != '\0' || val <= 0 || val > INT_MAX) {
      std::cerr << "Error" << std::endl;
      return 1;
    }

    vectorInput.push_back(static_cast<int>(val));
    dequeInput.push_back(static_cast<int>(val));
  }

  std::cout << "Before: ";
  for (size_t i = 0; i < vectorInput.size(); ++i)
    std::cout << vectorInput[i] << " ";
  std::cout << std::endl;

  PmergeMe::sortAndMeasure(vectorInput, dequeInput);

  return 0;
}
