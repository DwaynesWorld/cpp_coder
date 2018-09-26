#include "two_sum.h"

#include <unordered_map>
#include <vector>

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target. You may assume that each input would have
// exactly one solution, and you may not use the same element twice.

// O(n)
std::vector<int> TwoSumSolution::TwoSum(std::vector<int> &nums, int target) {
  std::vector<int> result = {};
  std::unordered_map<int, int> map;

  for (size_t i = 0; i < nums.size(); i++) {
    auto search = map.find(target - nums[i]);
    if (search != map.end()) {
      result.push_back(i);
      result.push_back(search->second);
      return result;
    }

    map[nums[i]] = i;
  }

  return result;
}