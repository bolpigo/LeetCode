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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if(!root) return res;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		vector<int> vec;
		while(!q.empty()) {
			TreeNode *node = q.front();
			q.pop();
			if(node) {
				vec.push_back(node->val);
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			} else {
				res.push_back(vec);
				vec.clear();
				if(!q.empty()) {
					q.push(NULL);
				}
			}
		}
		return res;
	}
};
