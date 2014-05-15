/**
* Definition for singly-linked list.
* struct ListNode {
*	int val;
*	ListNode *next;
*	ListNode(int x):val(x),next(NULL) {}
* };
*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		bool flag = false;
		ListNode *fp=head, *sp=head;
		while(fp && fp->next) {
			fp=fp->next->next;
			sp=sp->next;
			if(fp==sp) {
				flag=true;
				break;
			}
		}
		if(flag) {
			fp=head;
			while(fp!=sp) {//polt will help,2a+2b=a+2b+c 
				fp=fp->next;
				sp=sp->next;
			}
			return sp;
		}
		return NULL;
	}
};
