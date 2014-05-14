/**
* Definition for singly-linked list.
* struct ListNode {
*	int val;
*	ListNode *next;
*	ListNode(int x):val(x),next(NULL){}
* };
*/
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		ListNode phead(0);//set a node always poins the head
		phead.next=head;
		if(!head) return NULL;
		ListNode *p=head->next, *tail=head;
		while(p) {
			if(tail->val <= p->val) { //p is larger than the largestrsorted list element
				tail=p;
				p=p->next;
				break;
			}
			ListNode *q=phead.next, *preq=NULL;
			while(q!=p) { //there must can find the post q > p
				if(q->val > p->val)
					break;
				else preq=q;
				q=q->next;
			}
			tail->next=p->next;
			p->next=q;
			if(!preq) preq=&phead; //p is smallest in the sorted list
			preq->next=p;
			p=tail->next;
		}
		return phead.next;
	}
}
