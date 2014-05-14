/**
* Definition for singly-linked list.
* struct ListNode {
* int val;
* ListNode *next;
* ListNode(int x):val(x),next(NULL){}
* };
*/
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		ListNode *p, *q=NULL, *e=NULL, tail; 
		int insize=1, nmerges, psize, qsize;
		if(!head) return head;
		while(true) {
			p=head;
			tail=NULL;
			nmerges=0;//count number of merges we do in this pass.
			while(p) {
				++nmerges;//there exists a merge to be done.
				/*step 'insize' places along from p. */
				q=p;
				psize=0;
				for(int i = 0; i < insize; ++i) {
					if(q) {
						q=q->next;
						++psize;
					}
					else break;
				}
				/*if q hasn't fallen off end, we have two lists to merge.*/
				qsize = insize;
				/* now we have two lists; merge them.*/
				while(psize > 0 || (qsize > 0 && q)) {
					/*decide whether next element of merge comes from p or q.*/
					if(psize == 0) {
						/*p is empty; e must come from q.*/
						e=q;q=q->next;--qsize;
					} else if(qsize == 0 || !q) {
						/*q is empty; e must come from p.*/
						e=p;p=p->next;--psize;
					} else if(p->val <= q->val) {
						/*First element of p is lower(or same).*/
						e=p;p=p->next;--psize;
					} else {
						/*First element of q i lower*/
						e=q;q=q->next;--qsize;
					}
					if(tail) tail->next=e;
					else head=e;
					tail=e;
				}
				p=q;
			}
			tail->next=NULL;
			if(nmerges<=1) return head;
			insize *= 2;
		}
		return NULL;
	}
};
