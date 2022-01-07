/**
 * Problem:
 * Given the head of a linked list, remove the nth node 
 * from the end of the list and return its head.
 * 
 */
#include "node.h"

namespace leetcode {
    int size_list(ListNode* head) {
      auto size{1};
      for(auto tmp = head; tmp->next != nullptr; tmp = tmp->next) {
          size++;
      }
      return size;
    }
    ListNode* removeNodeEven(ListNode* head, int n) {
        if (n == 1) {
            delete head;
            return nullptr;
        } else {
            auto tmp = head->next;
            delete head;
            head = tmp;
            return head;
        }
    }
    // this is the naive version that can be done with 2 passes.
    // it's possible using a dummy node make it in one pass.
    ListNode* removeNthFromEndNaive(ListNode* head, int n) {
      if ((head == nullptr) || (n <=0)) {
          return head;
      }        
      int max_loop = size_list(head) - n;
      ListNode* slow = head;
      ListNode* fast = head;
      if (max_loop == 0) {
          return removeNodeEven(head, max_loop);
      }
      while( (fast != nullptr) && (max_loop > 0)) {
          slow = fast;
          fast = fast->next;
          max_loop--;
      }
      if (fast != nullptr) {
        slow->next = fast->next;
      }
      return head;
    }  
};