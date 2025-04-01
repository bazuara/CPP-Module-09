/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:59:39 by bazuara           #+#    #+#             */
/*   Updated: 2025/04/01 10:55:29 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PmergeMe.cpp
#include "PmergeMe.hpp"

#include <algorithm>
#include <ctime>
#include <iostream>

// Helper: Insert using binary search
static void binaryInsert(std::vector<int>& sorted, int value) {
  std::vector<int>::iterator it =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(it, value);
}

static void binaryInsert(std::deque<int>& sorted, int value) {
  std::deque<int>::iterator it =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(it, value);
}

// Merge-Insert Sort (simplified Ford-Johnson idea)
void PmergeMe::mergeInsertSort(std::vector<int>& data) {
  if (data.size() <= 1) return;

  std::vector<int> mainChain;
  std::vector<int> pend;

  // Pair and sort pairs
  for (size_t i = 0; i < data.size(); i += 2) {
    if (i + 1 < data.size()) {
      if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
      mainChain.push_back(data[i]);
      pend.push_back(data[i + 1]);
    } else {
      pend.push_back(data[i]);
    }
  }

  // Recursively sort mainChain
  mergeInsertSort(mainChain);

  // Insert pending elements using binary insert
  for (size_t i = 0; i < pend.size(); ++i) {
    binaryInsert(mainChain, pend[i]);
  }

  data = mainChain;
}

void PmergeMe::mergeInsertSort(std::deque<int>& data) {
  if (data.size() <= 1) return;

  std::deque<int> mainChain;
  std::deque<int> pend;

  for (size_t i = 0; i < data.size(); i += 2) {
    if (i + 1 < data.size()) {
      if (data[i] < data[i + 1]) std::swap(data[i], data[i + 1]);
      mainChain.push_back(data[i]);
      pend.push_back(data[i + 1]);
    } else {
      pend.push_back(data[i]);
    }
  }

  mergeInsertSort(mainChain);

  for (size_t i = 0; i < pend.size(); ++i) {
    binaryInsert(mainChain, pend[i]);
  }

  data = mainChain;
}

void PmergeMe::sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq) {
  clock_t start, end;

  std::vector<int> vecCopy = vec;
  std::deque<int> deqCopy = deq;

  start = clock();
  mergeInsertSort(vecCopy);
  end = clock();

  std::cout << "After: ";
  for (size_t i = 0; i < vecCopy.size(); ++i) std::cout << vecCopy[i] << " ";
  std::cout << std::endl;

  double timeVector =
      static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << timeVector << " us"
            << std::endl;

  start = clock();
  mergeInsertSort(deqCopy);
  end = clock();

  double timeDeque =
      static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
  std::cout << "Time to process a range of " << deq.size()
            << " elements with std::deque  : " << timeDeque << " us"
            << std::endl;
}
