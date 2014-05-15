/*duply list storage cur element in the cache, with the order of LRU(pre with the nearer visit and next with the older visit)*/
struct Node {
	Node *next;
	Node *pre;
	int key;
	Node(int k):key(k),next(NULL),pre(NULL) {}
};
/*hash-map value storage the structs, it's include the duply list node */
struct hashNde {
	Node *node;
	int val;
	hashNde(){}
	hashNde(int k, int v):val(v){node=new Node(k);}
};
class LRUCache {
private:
	int cap;/*LRUCache maxium capacity*/
	int curcap;/*cur storage capacity*/
	Node *tail;/*LRU node*/
	Node *head;/*recent used node*/
	unordered_map<int hashNde> LRU;/*hasp-map with interager key and the hashNde value*/
public:
	/*init members*/
	LRUCache(int capacity) {
		cap=capacity;
		curcap=0;
		tail=NULL;
		head=NULL;
	}
	/*get value of the key with o(1) time*/
	int get(int key) {
		if(LRU.find(key)!=LRU.end()) {
			Node *nde=LRU[key].node;
			if(LRU[key].val != -1)//early in the cache but remove set the value -1, all the elements in the cache > 0
				changeLRU(nde);//change the dulpy order
			return LRU[key].val;
		}
		return -1;
	}
	/*write element to cache */
	void set(int key, int value) {
		if(curcap<cap){//cache has extra size
			hasNde d(key,value);
			Node *nde = d.node;
			if(LRU.find(key)==LRU.end()) { //new elements
				++curcap;
				if(head) {//head is not null
					head->pre=nde;
					nde->next=head;
					head=nde;//change head points the new elements
				} else { //first add elements
					head=nde;
					tail=nde;
				}
				LRU[key]=d;
			} else { //the elements already in the cache
				LRU[key].val=value;
				changeLRU(LRU[key].node)//change the dulpy order
			}
		} else { //cache need remove LRU elements, then add elements
			if(LRU.find(key) == LRU.end()) { //new elements
				LRU[tail->key].val=-1; //set oldeset elements value -1,not remove it from hashmap
				hashNde d(key,value);
				LRU[key]=d;
				changeLRU(LRU[key].node);
			} else {//the elements already in the cache
				if(LRU[key].val==-1) LRU[tail->key].val=-1;//add new elements 
				LRU[key].val=value;
				changeLRU[LRU[key].node];
			}
		}
	}
	/*visited the nde and asset nde to the List head*/
	void changeLRU(Node *nde) {
		if(nde->pre!=NULL && nde->next != NULL) {//nde is not head nor tail
			nde->pre->next=nde->next;
			nde->next->pre = nde->pre;
			nde->next=head;
			head->pre=nde;
			nde->pre=NULL;
			head=nde;
		} else if(nde->pre != NULL) { //nde is tail
			nde->pre->next=NULL;
			nde->next = head;
			tail=nde->pre;
			head->pre=nde;
			nde->pre=NULL;
			head=nde;
		} else if(nde->pre == NULL && nde->next == NULL) { //nde is new elements or had removed from list
			nde->next=head;
			head->pre=nde;
			head=nde;
			Node *tmp=tail->pre;
			tail->pre=NULL;
			tail=tmp;
			tail->next=NULL;
		}
	}
};
