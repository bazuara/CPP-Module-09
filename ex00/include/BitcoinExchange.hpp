// BitcoinExchange.hpp
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, float> btcPrices;

  // unused cannonical form
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

 public:
  explicit BitcoinExchange(const std::string &databaseFile);
  float getBitcoinValue(const std::string &date, float amount);
  void loadDatabase(const std::string &databaseFile);
  bool isValidDate(const std::string &date);
  bool isValidValue(const std::string &value);
};

#endif
