/**
* Definition for singly-linked list.
* struct ListNode {
* 	int val;
*	ListNode *next;
*	ListNode(int x):val(x),next(NULL){}
* };
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if(!head) return false;
		ListNode *fp=head, *sp=head;
		while(fp && fp->next) {
			fp=fp->next->next;
			sp=sp->next;
			if(fp==sp) return true;
		}
		return false;
	}
}
