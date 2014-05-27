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
	vector<TreeNode *> generateTrees(int n) {
		return dfs(1, n);
	}
private:
	vector<TreeNode *> dfs(int start, int end) {
		vector<TreeNode *> res;
		if(start > end) {
			res.push_back(NULL);
			return res;
		}
		for(int k = start; k <= end; ++k) {
			vector<TreeNode *> lhs = dfs(start, k-1);
			vector<TreeNode *> rhs = dfs(k+1, end);
			for(int i = 0; i < lhs.size(); ++i) {
				for(int j = 0; j < rhs.size(); ++j) {
					TreeNode *root = new TreeNode(k);
					root->left = lhs.at(i);
					root->right = rhs.at(j);
					res.push_back(root);
				}
			}
		}
		return res;
	}
};
