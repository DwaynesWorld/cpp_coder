#include "median_of_two.h"

#include <algorithm>
#include <iostream>
#include <vector>

void PrintVector(std::vector<int> &v) {
  for (auto i : v) std::cout << i << " ";
  std::cout << "" << std::endl;
}

// O(nlog(n))
double MedianOfTwoSolution::FindMedianSortedArraysA(std::vector<int> &nums1,
                                                    std::vector<int> &nums2) {
  auto numbers = nums1;
  double median = 0;

  numbers.insert(numbers.end(), nums2.begin(), nums2.end());
  int size = numbers.size();

  if (size) {
    std::sort(numbers.begin(), numbers.end());

    if (size % 2 == 0) {
      int mid = (size / 2) - 1;
      int mid2 = mid + 1;
      median = (numbers[mid] + numbers[mid2]) / 2.0;
    } else {
      median = numbers[size / 2];
    }
  }

  return median;
}

// O(n)
double MedianOfTwoSolution::FindMedianSortedArraysB(std::vector<int> &nums1,
                                                    std::vector<int> &nums2) {
  std::vector<int> merged = {};

  int size1 = nums1.size(), size2 = nums2.size();

  // Early Bail
  if (size1 != 0 && size2 == 0) {
    return (size1 % 2 == 0)
               ? (nums1[(size1 / 2) - 1] + nums1[(size1 / 2)]) / 2.0
               : (nums1[size1 / 2]);
  } else if (size1 == 0 && size2 != 0) {
    return (size2 % 2 == 0)
               ? (nums2[(size2 / 2) - 1] + nums2[(size2 / 2)]) / 2.0
               : (nums2[size2 / 2]);
  }

  int size = size1 + size2;
  int targetIndex = 0;
  bool secondIndex = false;

  if (size % 2 == 0) {
    secondIndex = true;
    targetIndex = (size / 2) - 1;
  } else {
    targetIndex = size / 2;
  }

  int i = 0, j = 0, k = 0, a = 0, b = 0;

  while (true) {
    if (i < size1)
      a = nums1[i];
    else
      a = INT_MAX;

    if (j < size2)
      b = nums2[j];
    else
      b = INT_MAX;

    if (a < b) {
      merged.push_back(a);
      i++;
    } else {
      merged.push_back(b);
      j++;
    }

    PrintVector(merged);

    if (k == targetIndex && !secondIndex) {
      return merged[targetIndex];
    } else if (k > targetIndex && secondIndex) {
      return (merged[targetIndex] + merged[targetIndex + 1]) / 2.0;
    }

    k++;
  }
}