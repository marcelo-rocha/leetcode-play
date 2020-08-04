#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <algorithm>
#include <vector>

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
    static bool isOdd(int n) { return (n % 2) != 0; }
    vector<vector<int>> result_;
    void zigzag(TreeNode *node, int level) {
        if (level == result_.size()) {
            result_.push_back(vector<int>({node->val}));
        } else {
            result_[level].push_back(node->val);
        }
        if(node->left) {
            zigzag(node->left, level + 1);
        }
        if(node->right) {
            zigzag(node->right, level + 1);
        } 
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        result_.clear();
        if (root == nullptr) {
            return result_;    
        }
        zigzag(root, 0);
        int level = 0;
        for(auto it = result_.begin(); it != result_.end(); ++it) {
            if (isOdd(level)) {
                std::reverse(result_[level].begin(), result_[level].end());
            }
            level++;
        }
        return std::move(result_);
    }
};

TEST_CASE("sample 1", "[samples]") {
    Solution sol;
    TreeNode *root = new TreeNode(3, 
        new TreeNode(9),
        new TreeNode(20,
            new TreeNode(15),
            new TreeNode(7)));
    auto r = sol.zigzagLevelOrder(root);
    REQUIRE(r.size() == 3);
    REQUIRE(r[0] == vector<int>({3}));
    REQUIRE(r[1] == vector<int>({20, 9}));
    REQUIRE(r[2] == vector<int>({15, 7}));
}

