#define CATCH_CONFIG_MAIN  
#include "catch.hpp"

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
    vector<vector<int>> output;
    void traversal(TreeNode *node, int level) {
        if (node == nullptr) 
            return;
        if(level == output.size()) {
            vector<int> row({node->val});
            output.push_back(row);
        } else {
            output[level].push_back(node->val);
        }
        traversal(node->left, level + 1);
        traversal(node->right, level + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        output.clear();
        traversal(root, 0);
        reverse(output.begin(), output.end());
        return output;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    TreeNode *root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, 
            new TreeNode(15),
            new TreeNode(7)));
    auto r = sol.levelOrderBottom(root);
    vector<vector<int>> expected;
    expected.push_back(vector<int>({15, 7}));
    expected.push_back(vector<int>({9,20}));
    expected.push_back(vector<int>({3}));
    REQUIRE(expected == r);
}
