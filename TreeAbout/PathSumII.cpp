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
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > res;
		vector<int> vec;
		dfs(root,0,res,vec,sum);
		return res;
	}
	void dfs(TreeNode *root, int cur, vector<vector<int> > &res, vector<int> &vec, int sum) {
		if(!root) return;
		vec.push_back(root->val);
		if(!root->left && !root->right) {
			if(cur+root->val) {
				res.push_back(vec);
			}
			return;
		}
		dfs(root->left,cur+root->val,res,vec,sum);
		if(root->left)
			vec.pop_back();
		dfs(root->right,cur+root->val,res,vec,sum);
		if(root->right)
			vec.pop_back();
	}
};
