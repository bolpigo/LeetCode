/**
* Definition for binary tree
* struct TreeNode {
* 	int val;
*	TreeNode *left;
* 	TreeNode *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> res;
		if(!root) return res;
		st.push(root);
		while(!st.empty()) {
			ListNode *node = st.top();
			st.pop();//right-left-root(reverse)
			res.push_back(node->val);
			if(node->left) st.push_back(node->left);
			if(node->right) st.push_back(node->right);
		}
		reverse(res.begin(),res.end());
		return res;
	}
};
