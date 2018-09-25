#include <addLinkedList.hpp>
#include <iostream>
#include <twoSum.hpp>
#include <vector>

void _twoSumSolution();
void _addLinkedListSolution();

main(int argc, char const* argv[]) {
  _addLinkedListSolution();
  _twoSumSolution();
  return 0;
}

void _addLinkedListSolution() {
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
  auto result = solution.addTwoNumbers(&node1_1, &node2_1);
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

void _twoSumSolution() {
  int target = 9;
  std::vector<int> input = {2, 7, 11, 15};

  auto solution = TwoSumSolution();
  auto result = solution.twoSum(input, target);
  if (result.size() == 2) {
    std::cout << "Indexes: (" << result[0] << ", " << result[1] << ")"
              << std::endl;
  }
  return;
}
