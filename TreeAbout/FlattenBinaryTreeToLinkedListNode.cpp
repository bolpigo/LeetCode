/** Definition for binary tree
* struct TreeNode {
*	int val;
*	TreeNode *left, *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public://O(n) space O(n) time
	void flatten(TreeNode *root) {
		if(!root) return;
		stack<TreeNode *> st;
		vector<TreeNode *> res;
		st.push(root);
		while(!st.empty()) {
			TreeNode *node = st.top();
			st.pop();
			res.push_back(node);
			if(node->right) st.push(root->right);
			if(node->left) st.push(root->left);
		}
		vector<TreeNode *>::iterator it=res.begin();
		while(it+1 != res.end()) {
			(*it)->left=NULL;
			(*it++)->right=*it;
		}
	}
};
