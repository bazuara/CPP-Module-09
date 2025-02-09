/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:14:43 by bazuara           #+#    #+#             */
/*   Updated: 2025/02/08 17:50:16 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: Usage: ./btc <input_file>" << std::endl;
    return 1;
  }

  std::ifstream inputFile(argv[1]);
  if (!inputFile.is_open()) {
    std::cerr << "Error: Could not open file." << std::endl;
    return 1;
  }

  BitcoinExchange btc("data.csv");
  std::string line;
  while (std::getline(inputFile, line)) {
    std::istringstream ss(line);
    std::string date, valueStr;
    if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
      date.erase(date.find_last_not_of(" \t\n\r") + 1);
      valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r"));

      if (!btc.isValidDate(date)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        continue;
      }
      if (!btc.isValidValue(valueStr)) {
        std::cerr << "Error: invalid value." << std::endl;
        continue;
      }

      float value = std::atof(valueStr.c_str());
      float result = btc.getBitcoinValue(date, value);
      std::cout << date << " => " << value << " = " << result << std::endl;
    } else {
      std::cerr << "Error: bad input format." << std::endl;
    }
  }

  inputFile.close();
  return 0;
}
