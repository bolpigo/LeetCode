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
	void reorderList(ListNode *head) {
		if(!head) return;
		ListNode *lp=head, *fp=head, *rhead;
		while(fp && fp->next) {
			fp=fp->next->next;
			if(!fp) break;
			lp=lp->next;
		}
		rhead=lp->next;
		lp->next=NULL;
		rhead = reverse(rhead);
		lp=head;
		while(lp) {
			ListNode *tmp=lp->next;
			lp->next=rhead;
			lp=tmp;
			if(rhead) {
				ListNode *tmp2=rhead->next;
				rhead->next=lp;
				rhead=tmp2;
			}
		}
	}
	ListNode *reverse(ListNode *head) {
		ListNode *p=head, *prep=NULL;
		while(p) {
			ListNode *tmp=p->next;
			p->next=prep;
			prep=p;
			p=tmp;
		}
		return prep;
	}
}
