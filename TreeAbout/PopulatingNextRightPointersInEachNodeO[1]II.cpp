class Solution {
public://with O(1) space
	void connect(TreeNode *root) {
		if(!root) return;
		TreeNode *p = root->next;
		while(p) {
			if(p->left) {
				p=p->left;
				break;
			}
			if(p->right) {
				p=p->right;
				break;
			}
			p=p->next;
		}
		if(root->right) root->right->next=p;
		if(root->left) root->left->next=root->right==NULL?p:root->right;
		connect(root->right);
		connect(root->left);
	}
};
