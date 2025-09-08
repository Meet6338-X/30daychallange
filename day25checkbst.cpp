#include <cstddef>
#include <climits>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) 
{
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) 
{
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != "null") 
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") 
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int main() {
    vector<vector<string>> tests = 
    {
        {"2","1","3"},
        {"5","1","4","null","null","3","6"},
        {"10","5","15","null","null","6","20"}
    };
    
    for (auto &t : tests) 
    {
        TreeNode* root = buildTree(t);
        cout << (isValidBST(root) ? "true" : "false") << endl;
    }
    return 0;
}