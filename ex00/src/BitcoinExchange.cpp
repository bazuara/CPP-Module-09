/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:31:26 by bazuara           #+#    #+#             */
/*   Updated: 2025/02/08 12:31:41 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
  loadDatabase(databaseFile);
}

void BitcoinExchange::loadDatabase(const std::string &databaseFile) {
  std::ifstream file(databaseFile.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: Could not open database file");
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date;
    float price;
    if (std::getline(ss, date, ',') && ss >> price) {
      btcPrices[date] = price;
    }
  }
  file.close();
}

float BitcoinExchange::getBitcoinValue(const std::string &date, float amount) {
  std::map<std::string, float>::iterator it = btcPrices.lower_bound(date);
  if (it == btcPrices.end() || it->first > date) {
    if (it != btcPrices.begin()) {
      --it;
    } else {
      throw std::runtime_error(
          "Error: No valid historical data for the given date");
    }
  }
  return amount * it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
  int year, month, day;
  std::istringstream ss(date);
  char dash1, dash2;
  if (!(ss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' ||
      dash2 != '-')
    return false;
  if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;
  return true;
}

bool BitcoinExchange::isValidValue(const std::string &value) {
  std::istringstream ss(value);
  float num;
  if (!(ss >> num) || num < 0 || num > 1000) return false;
  return true;
}
