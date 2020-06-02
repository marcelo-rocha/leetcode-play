#include <vector>
#include <utility>
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

void printTree(TreeNode *root, int level) {
    string spaces(level * 3, ' ');
    if (root == nullptr) {
        cout << spaces << "null\n";
    } else {
        cout << spaces << root->val << "\n";
        printTree(root->left, level + 1);
        printTree(root->right, level + 1);
    }
}

class Solution {
private:
    static bool invert(TreeNode *node) {
        if (node == nullptr) {
            return false;
        }
        if(invert(node->left) | invert(node->right)) {
            swap(node->left, node->right);
        }
        return true; 
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;           
    }
};

TEST_CASE("Demo", "[samples]") {
    Solution sol;
    TreeNode *root = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)),
        new TreeNode(7,
            new TreeNode(6),
            new TreeNode(9))
        );

    TreeNode* r = sol.invertTree(root);

    CHECK(r->val == 4);
    CHECK(r->left->val == 7);
    CHECK(r->right->val == 2);
    CHECK(r->left->left->val == 9);
    CHECK(r->left->right->val == 6);
}
