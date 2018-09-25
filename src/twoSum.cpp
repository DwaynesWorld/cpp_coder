#include "twoSum.hpp"
#include <unordered_map>
#include <vector>

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target. You may assume that each input would have
// exactly one solution, and you may not use the same element twice.

// O(n)
std::vector<int> TwoSumSolution::twoSum(std::vector<int> &nums, int target) {
  std::vector<int> r = {};
  std::unordered_map<int, int> m;

  for (size_t i = 0; i < nums.size(); i++) {
    auto search = m.find(target - nums[i]);
    if (search != m.end()) {
      r.push_back(i);
      r.push_back(search->second);
      return r;
    }

    m[nums[i]] = i;
  }

  return r;
}