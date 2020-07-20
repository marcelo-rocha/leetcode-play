#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val) {
            head = head->next;
        }
        if(head) {
            ListNode* prev = head;
            ListNode* current = head->next;
            while(current) {
                if (current->val == val) {
                    current = current->next;
                    prev->next = current;
                } else {
                    prev = current;
                    current = current->next;
                }
            }
        }
        return head;       
    }
};


vector<int> listAsVector(ListNode *head) {
    ListNode* node = head;
    vector<int> r;
    while(node) {
        r.push_back(node->val);
            node = node->next;
    }
    return r;
}

ListNode* vectorToLL(const vector<int> &v) {
    ListNode *node = nullptr;
    for(auto it = v.rbegin(); it != v.rend(); ++it ) {
        node = new ListNode(*it, node);
    }
    return node;
} 

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    // 1->2->6->3->4->5->6
    ListNode* head = vectorToLL({1,2,6,3,4,5,6});
    auto r = listAsVector(sol.removeElements(head, 6));
    vector<int> expected({1, 2, 3, 4, 5});
    REQUIRE(r == expected);
}
