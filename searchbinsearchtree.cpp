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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *node = root;
        while(node != nullptr) {
            if (node->val == val) {
                return node;
            } else if (val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return node;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;
    TreeNode *root = new TreeNode(4,
        new TreeNode(2, 
            new TreeNode(1),
            new TreeNode(3)),
        new TreeNode(7)
    );
    TreeNode* r = sol.searchBST(root, 2);

    REQUIRE(r != nullptr);
    REQUIRE(r->val == 2);
}
