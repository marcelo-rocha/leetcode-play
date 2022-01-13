// Leetcode problem https://leetcode.com/problems/palindrome-linked-list/
#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

using namespace std;


// * Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        auto len = getLength(head);
        if (len <= 1) {
            return true;
        }
        int splitLen = len / 2;
        auto oddLength = (len % 2) == 1;

        auto splitIdx = oddLength ? splitLen : splitLen - 1;

        auto rightList = revert(breakList(head, splitIdx, oddLength));

        return compare(head, rightList);        
    }
private:
    int getLength(ListNode *head) {
        int r = 0;
        auto p = head;
        while (p != nullptr) {
            r++;
            p = p->next;
        }
        return r;
    }

    ListNode* revert(ListNode *head) {
        ListNode *previous = nullptr;
        auto p = head;
        while (p != nullptr) {
            auto next = p->next;
            p->next = previous;
            previous = p;
            p = next;
        }
        return previous;
    }

    ListNode* breakList(ListNode *head, int pos, bool excludeTail) {
        if ((pos == 0) && excludeTail) {
            excludeTail = false;
        }
        int i = 0;
        auto p = head;
        ListNode *previous = nullptr;
        while (p != nullptr) {
            if (i == pos) {
                auto r = p->next;
                excludeTail ? previous->next = nullptr : p->next = nullptr;
                return r;
            }
            previous = p;
            p = p->next;
            i++;
        }
        return nullptr;
    }
    bool compare(ListNode *lx, ListNode *ly) {
        auto x = lx, y = ly;

        while (x != nullptr && y != nullptr) {
            if (x->val != y->val) {
                return false;
            }
            x = x->next;
            y = y->next;
        }
        return (x == nullptr) && (y == nullptr);
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    auto head = new ListNode(1, 
        new ListNode(2, 
        new ListNode(2, 
        new ListNode(1))));
    
    auto r = sol.isPalindrome(head);
    REQUIRE(r == true);
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    auto head = new ListNode(1, 
        new ListNode(2, 
        new ListNode(3, 
        new ListNode(2, 
        new ListNode(1)))));
    
    auto r = sol.isPalindrome(head);
    REQUIRE(r == true);
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    auto head = new ListNode(1, 
        new ListNode(1));
    
    auto r = sol.isPalindrome(head);
    REQUIRE(r == true);
}

TEST_CASE( "Sampple 4", "[samples]" ) {
    Solution sol;
    auto head = new ListNode(1, 
        new ListNode(2));
    
    auto r = sol.isPalindrome(head);
    REQUIRE(r == false);
}