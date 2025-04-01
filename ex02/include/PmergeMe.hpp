/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:45:25 by bazuara           #+#    #+#             */
/*   Updated: 2025/04/01 10:55:33 by bazuara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <limits.h>

#include <deque>
#include <vector>

class PmergeMe {
 public:
  static void sortAndMeasure(std::vector<int>& vec, std::deque<int>& deq);

 private:
  static void mergeInsertSort(std::vector<int>& data);
  static void mergeInsertSort(std::deque<int>& data);
};

#endif
