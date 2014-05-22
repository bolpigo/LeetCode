/**
* Definition for binary tree
* struct TreeNode {
*	int val;
*	TreeNode *left, *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public:
	void recoverTree(TreeNode *root) {
		if(!root) return;
		stack<TreeNode *> st;
		vector<TreeNode *> res;
		TreeNode *p=root;
		while(p || !st.empty()) {
			while(p) {
				st.push(p);
				p=p->left;
			}
			if(!st.empty()) {
				p=st.top();
				st.pop();
				res.push_back(p);
				p=p->right;
			}
		}
		int lhs=0,rhs=res.size()-1;
		while(res[lhs]->val < res[lhs+1]->val) ++lhs;
		while(res[rhs]->val > res[rhs-1]->val) --rhs;
		if(lhs != rhs) {
			int tmp = res[lhs]->val;
			res[lhs]->val = res[rhs]->val;
			res[rhs]->val = tmp;
		}
	}
};
