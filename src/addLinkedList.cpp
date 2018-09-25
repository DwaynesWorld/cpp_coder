#include "addLinkedList.hpp"

// You are given two non-empty linked lists representing two non-negative
// integers. The digits are stored in reverse order and each of their nodes
// contain a single digit. Add the two numbers and return it as a linked list.
// You may assume the two numbers do not contain any leading zero, except the
// number 0 itself.

ListNode *AddLinkedListSolution::addTwoNumbers(ListNode *l1, ListNode *l2) {
  auto a = l1, b = l2;

  if (!a && !b)
    return new ListNode(0);
  else if (a && !b)
    return a;
  else if (b && !a)
    return b;

  int temp = (a->val + b->val) % 10;
  int carry = (a->val + b->val) / 10;
  a = a->next;
  b = b->next;

  auto head = new ListNode(temp);
  auto prev = head;

  while (true) {
    bool finish = true;
    temp = carry;

    if (a) {
      temp += a->val;
      a = a->next;
      finish = false;
    }

    if (b) {
      temp += b->val;
      b = b->next;
      finish = false;
    }

    if (!finish) {
      carry = temp / 10;
      temp = temp % 10;

      prev->next = new ListNode(temp);
      prev = prev->next;
    } else {
      if (carry) {
        prev->next = new ListNode(carry);
        prev = prev->next;
      }
      return head;
    }
  }
}