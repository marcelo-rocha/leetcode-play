#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

// Delete Node in a Linked List Problem
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* makeList(vector<int> &items) {
    ListNode *head, *prev = nullptr;
    for(int n: items) {
        ListNode * node = new ListNode(n);
        if(prev != nullptr) {
            prev->next = node;
            prev = node;
        } else {
            prev = head = node;
        }
    }
    return head;
}

vector<int> getValues(ListNode *head) {
    vector<int> r;
    auto node = head;
    while(node != nullptr) {
        r.push_back(node->val);
        node = node->next;
    }
    return r;
}

class Solution {
public:
    void deleteNode(ListNode* node) {
        auto n = node->next;
        node->val = n->val;
        node->next = n->next;
        delete n;         
    }
};


TEST_CASE( "four nodes", "[samples]" ) {
    Solution sol;
    ListNode *head = makeList(vector<int>({4, 5, 1, 9}));
    sol.deleteNode(head->next);
    auto r = getValues(head);
    REQUIRE(r == vector<int>({4, 1, 9}));
}