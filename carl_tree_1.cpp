#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* a, TreeNode* b) : val(x), left(a), right(b) {}
};

// 更常见的是写一个 TreeNode* newNode(){}; 用于动态分配创建新的节点。

// Construct Tree
TreeNode d = {1};
TreeNode e = {2};
TreeNode b = {4, &d, &e};
TreeNode c = {6};
TreeNode a = {5, &b, &c};
TreeNode* root = &a;  // 通常会传指针进去。

vector<int> preorder(TreeNode* root) {
    stack<TreeNode*> st;  // 通常对于节点都是传入的指针，没有人存结点，全部存指针地址。
    vector<int> result;
    st.push(root);
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if(node->right) st.push(node->right); // 可能是NULL, 必须要加入判断。
        if(node->left) st.push(node->left);
    }
    return result;
}

int main() {
    vector<int> res = preorder(root);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}