#include <bits/stdc++.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *node){
  while (node != nullptr) {
    cout << node->val << " ";
    node = node->next;
  }
  cout << "\n"; 
}


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      if (head == nullptr || head->next == nullptr) {
        return head;
      }

      ListNode *oddTail = head;
      ListNode *evenHead, *evenTail;
      evenHead = evenTail = head->next;
      ListNode *src = head->next->next;
      while(true) {
        if(src == nullptr) {
          break;
        }
        oddTail->next = src;
        oddTail = src;
        src = src->next;

        if (src==nullptr) {
          break;
        }
        evenTail->next = src;
        evenTail = src;
        src = src->next;
      }

      oddTail->next = evenHead;
      evenTail->next = nullptr;   
      return head;   
    }
};

int main() {
  ListNode *list1 = new ListNode(1, 
    new ListNode(2, 
      new ListNode(3,
        new ListNode(4,
          new ListNode(5)))));
  Solution sol1;
  auto r1 = sol1.oddEvenList(list1);
  printList(r1);

  ListNode *list2 = new ListNode(2, 
    new ListNode(1, 
      new ListNode(3,
        new ListNode(5,
          new ListNode(6,
            new ListNode(4,
              new ListNode(7)))))));
  Solution sol2;
  auto r2 = sol2.oddEvenList(list2);
  printList(r2);

}