// leetcode challenge 537(Construct Binary Search Tree from Preorder Traversal)
#include <vector>
#include <iostream>
#include <limits>
#include <string>

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
private:
    vector<int>::const_iterator *stop_ = nullptr;
    TreeNode* bstRecursive(vector<int>::const_iterator &it, int max) {
        if(it == *stop_) { 
            return nullptr;
        }
        int val = *it;
        if (val > max) {
            return nullptr;
        }
        auto node = new TreeNode(val); 
        ++it;
        node->left = bstRecursive(it, val);
        node->right = bstRecursive(it, max);
        return node;
    }


public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        auto it = preorder.cbegin();
        auto stop = preorder.cend();
        stop_ = &stop;
        auto root = new TreeNode(*it);
        ++it;
        root->left = bstRecursive(it, root->val);
        root->right = bstRecursive(it, numeric_limits<int>::max());
        return root;       
    }
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

int main() {
    vector<int> input{8,5,1,7,10,12};
    Solution sol;
    auto bt = sol.bstFromPreorder(input);
    printTree(bt, 0);
}