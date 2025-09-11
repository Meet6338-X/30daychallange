#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) 
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val)
            && isMirror(t1->left, t2->right)
            && isMirror(t1->right, t2->left);
    }
};

TreeNode* buildTree(const vector<string>& nodes) 
{
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) 
    {
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

void runTest(const vector<string>& input) 
{
    TreeNode* root = buildTree(input);
    Solution sol;
    bool result = sol.isSymmetric(root);
    cout << (result ? "true" : "false") << endl;
}

int main() 
{
    runTest({"1", "2", "2", "3", "4", "4", "3"});               
    runTest({"1", "2", "2", "null", "3", "null", "3"});         
    runTest({"1"});                                             
    runTest({});                                                
    runTest({"1", "2", "2", "3", "null", "null", "3"});

    return 0;
}