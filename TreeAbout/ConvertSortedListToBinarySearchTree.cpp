/**
* Definition for singlt-linked list.
* struct ListNode {
*	int val;
*	ListNode *next;
*	ListNode(int x):val(x),next(NULL){}
* };
*/
/**
* Definition for binary tree
* struct TreeNode {
*	int val;
*	TreeNode *left, *right;
*	TreeNode(int x):val(x),left(NULL),right(NULL){}
* };
*/
class Solution {
public://O(n)space O(nlgn) time
	TreeNode *sortedListToBST(ListNode *head) {
		int n = 0;
		ListNode *p=head;
		while(p) {
			p=p->next;
			++n;
		}
		return partition(head,0,n-1);
	}
private:
	TreeNode *partition(ListNode *&head, int start, int end) {
		if(start>end) return NULL;
		int mid = (start+end)/2;
		TreeNode *lhs = partition(head,start,mid-1);
		TreeNode *root = new TreeNode(head->val);
		root->left=lhs;
		head=head->next;
		root->right = partition(head, mid+1, end);
		return root;
	}
};
