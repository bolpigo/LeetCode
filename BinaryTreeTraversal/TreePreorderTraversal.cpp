/**
* Definition for Binary tree
* struct TreeNode {
* 	int val;
*	TreeNode *left;
*	TreeNode *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> res;
		if(!root) return res;
		st.push(root);
		while(!st.empty()) {
			TreeNode *node = st.top();
			st.pop();//root-left-right
			res.push_back(node->val);
			if(node->right) st.push(node->right);
			if(node->left) st.push(node->left);
		}
		return res;
	}
};
