/**
* Definition for binary tree
* struct TreeNode {
*	int val;
*	TreeNode *left;
*	TreeNode *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> res;
		while(root || !st.empty()) {
			while(root) {
				st.push(root);
				root=root->left;
			}// left-root-right
			TreeNode *node = st.top();
			st.pop();
			res.push_back(node->val);
			if(node->right) root=node->right;
		}
		return res;
	}
};
