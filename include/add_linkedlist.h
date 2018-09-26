#pragma once

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class AddLinkedListSolution {
 public:
  ListNode *AddTwoNumbers(ListNode *l1, ListNode *l2);
};