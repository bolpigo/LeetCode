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
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if(!root) return;
		queue<TreeNode *> q;
		q.push(root);
		q.push(NULL);
		vector<int> tmp;
		int z = 1;
		while(!q.empty()) {
			TreeNode *node = q.front();
			q.pop();
			if(node) {
				tmp.push_back(node->val);
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			} else {
				if(++z%2) {
					reverse(tmp.begin(),tmp.end());
				}
				res.push_back(tmp);
				tmp.clear();
				if(!q.empty()) {
					q.push(NULL);
				}
			}
		}
		return res;
	}
};
