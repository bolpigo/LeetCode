/** 
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*	int label;
*	RandomListNode *next, *random;
*	RandomListNode(int x):label(x),next(NULL),random(NULL){}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head) return NULL;
		RandomListNode *p=head, *q;
		while(p) {
			q = new RandomListNode(p->label);
			q->next=p->next;
			p->next=q;
			p=q->next;
		}
		p=head;
		while(p) {
			if(p->random)
				p->next->random=p->random->next;
			p=p->next->next;
		}
		q=p->next;
		RandomListNode *nhead=q;
		while(p) {
			p->next=q->next;
			p=q->next;
			if(p) {
				q->next=p->next;
				q=p->next;
			}
		}
		return nhead;
	}
};
