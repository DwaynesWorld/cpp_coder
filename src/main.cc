#include <iostream>
#include <vector>

#include "add_linkedlist.h"
#include "median_of_two.h"
#include "two_sum.h"

void _MedianOfTwoSolution();
void _TwoSumSolution();
void _AddLinkedListSolution();

main(int argc, char const* argv[]) {
  _MedianOfTwoSolution();
  _AddLinkedListSolution();
  _TwoSumSolution();
  return 0;
}

void _MedianOfTwoSolution() {
  // std::vector<int> v1 = {1, 2, 3};
  // std::vector<int> v2 = {4, 5, 6, 7, 100};
  std::vector<int> v1 = {1, 3};
  std::vector<int> v2 = {2};
  MedianOfTwoSolution solution;
  auto median = solution.FindMedianSortedArraysB(v1, v2);
  std::cout << "Median: " << median << std::endl;
}

void _AddLinkedListSolution() {
  ListNode node1_1(2);
  ListNode node1_2(4);
  ListNode node1_3(3);

  node1_1.next = &node1_2;
  node1_2.next = &node1_3;

  ListNode node2_1(5);
  ListNode node2_2(6);
  ListNode node2_3(4);

  node2_1.next = &node2_2;
  node2_2.next = &node2_3;

  auto solution = AddLinkedListSolution();
  auto result = solution.AddTwoNumbers(&node1_1, &node2_1);
  if (result != nullptr) {
    std::string r = std::to_string(result->val);

    ListNode* currentNode = result->next;
    while (currentNode != nullptr) {
      r = std::to_string(currentNode->val) + r;
      currentNode = currentNode->next;
    }

    std::cout << "Result: 342 + 465 = " << r << std::endl;
    delete result;  // Need to properly delete linked nodes.
  }

  return;
}

void _TwoSumSolution() {
  int target = 9;
  std::vector<int> input = {2, 7, 11, 15};

  auto solution = TwoSumSolution();
  auto result = solution.TwoSum(input, target);
  if (result.size() == 2) {
    std::cout << "Indexes: (" << result[0] << ", " << result[1] << ")"
              << std::endl;
  }
  return;
}
