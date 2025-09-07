#include <cstddef>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lcadunction(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    if (!root || root == p || root == q) return root;

    TreeNode* left = lcadunction(root->left, p, q);
    TreeNode* right = lcadunction(root->right, p, q);

    if (left && right) return root;   
    return left ? left : right;     
}

TreeNode* buildTree(vector<string>& nodes) 
{
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() 
{
    vector<string> tree1 = {"3","5","1","6","2","0","8","null","null","7","4"};
    TreeNode* root1 = buildTree(tree1);

    TreeNode* p = findNode(root1, 5);
    TreeNode* q = findNode(root1, 4);
    cout << "LCA of 5 and 4 = " << lcadunction(root1, p, q)->val << endl;

    p = findNode(root1, 5);
    q = findNode(root1, 1);
    cout << "LCA of 5 and 1 = " << lcadunction(root1, p, q)->val << endl;

    vector<string> tree2 = {"1","2"};
    TreeNode* root2 = buildTree(tree2);
    p = findNode(root2, 1);
    q = findNode(root2, 2);
    cout << "LCA of 1 and 2 = " << lcadunction(root2, p, q)->val << endl;

    p = findNode(root1, 5);
    q = findNode(root1, 5);
    cout << "LCA of 5 and 5 = " << lcadunction(root1, p, q)->val << endl;

    p = findNode(root1, 3);
    q = findNode(root1, 4);
    cout << "LCA of 3 and 4 = " << lcadunction(root1, p, q)->val << endl;

    return 0;
}