#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    static bool comparePair (pair<short,short> x, pair<short,short> y) { return x.first != y.first ? x.first > y.first : x.second < y.second; }
    
    map<short, vector<pair<short, short>>> map_;

    void traverse(TreeNode* node, int x, int y) {
        auto &v = map_[x];
        v.emplace_back(y, node->val);
        if (node->left != nullptr) {
            traverse(node->left, x-1, y-1);
        }
        if (node->right != nullptr) {
            traverse(node->right, x + 1, y - 1);
        }
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        } 
        traverse(root, 0, 0);
        for(auto it = map_.begin(); it != map_.end(); ++it) {
            auto &v = it->second;
            if (v.size() > 1) {
                sort(v.begin(), v.end(), comparePair);
            }
            vector<int> row;
            for(auto &p: v) {
                row.push_back(p.second);                
            }
            result.push_back(row);
        }
        return result;
    }
};

TEST_CASE( "Sampple 1", "[samples]" ) {
    Solution sol;

    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20, 
            new TreeNode(15),
            new TreeNode(7)));

    auto r = sol.verticalTraversal(root);

    vector<vector<int>> expectedValue{{9}, {3, 15}, {20}, {7}};
    REQUIRE(r == expectedValue);

}

TEST_CASE( "Sampple 2", "[samples]" ) {
    Solution sol;

    TreeNode* root = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)),
        new TreeNode(3, 
            new TreeNode(6),
            new TreeNode(7)));

    auto r = sol.verticalTraversal(root);

    vector<vector<int>> expectedValue{{4}, {2}, {1, 5, 6}, {3}, {7}};
    REQUIRE(r == expectedValue);

}
