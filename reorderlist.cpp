#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode *n = head;
        while(n != nullptr) {
            nodes.push_back(n);
            n = n->next;
        }
        int i = 0;
        int j = nodes.size() - 1;
        ListNode** prev = &head;
        while(i < j) {
            n = nodes[i++];
            *prev = n; 
            n->next = nodes[j--];
            prev = &n->next->next;
        }
        if (i == j) {
            n = nodes[i];
            *prev = n;
            prev = &n->next;
        } 
        *prev = nullptr;
    }
};

vector<int> listToVector(ListNode* head) {
    vector<int> result;
    ListNode *n = head;
    while(n != nullptr) {
        result.push_back(n->val);
        n = n->next;
    }
    return result;
}


TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    sol.reorderList(list);
    auto r = listToVector(list);
    vector<int> expected = {1, 4, 2, 3};
    REQUIRE(r == expected);
}

TEST_CASE("sample 2", "[samples]") {
    Solution sol;
    ListNode *list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    sol.reorderList(list);
    auto r = listToVector(list);
    vector<int> expected = {1, 5, 2, 4, 3};
    REQUIRE(r == expected);
}

