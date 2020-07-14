#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef pair<TreeNode*, TreeNode*> TreeNodePair;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == q)
            return true;
        queue<TreeNodePair> nodeQueue;
        nodeQueue.emplace(p, q);
        while(!nodeQueue.empty()) {
            auto &elem = nodeQueue.front();
            auto x = elem.first;
            auto y = elem.second;
            if (x != nullptr && y != nullptr) {
                if (x->val != y->val) {
                    return false;
                }
                nodeQueue.emplace(x->left, y->left);
                nodeQueue.emplace(x->right, y->right);
            } else if (x != nullptr || y != nullptr) {
                return false;
            }
            nodeQueue.pop(); 
        }
        return true;        
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    TreeNode *t1 = new TreeNode(1, 
        new TreeNode(2),
        new TreeNode(3));
    TreeNode *t2 = new TreeNode(1, 
        new TreeNode(2),
        new TreeNode(3));
    REQUIRE(sol.isSameTree(t1, t2));
}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;
    TreeNode *t1 = new TreeNode(1, 
        new TreeNode(2),
        nullptr);
    TreeNode *t2 = new TreeNode(1, 
        nullptr,
        new TreeNode(2));
    REQUIRE(!sol.isSameTree(t1, t2));
}

TEST_CASE( "Sampple 3", "[samples]" ) {
    Solution sol;
    TreeNode *t1 = new TreeNode(1, 
        new TreeNode(2),
        new TreeNode(3));
    TreeNode *t2 = new TreeNode(1, 
        new TreeNode(3),
        new TreeNode(2));
    REQUIRE(!sol.isSameTree(t1, t2));
}
