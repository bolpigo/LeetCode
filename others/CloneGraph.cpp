/**
* Definition for un directed graph.
* struct UndirectedGraphNode {
*	int label;
*	vector<UndirectedGraphNode *> neighbors;
*	UndirectedGraphNode(int x):label(x){}
* };
*/
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(!node) return NULL;
		map<UndirectedGraphNode *, UndirectedGraphNode *> maps;
		queue<UndirectedGraphNode *> q;
		UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
		maps.insert(make_pair(node,newnode));
		q.push(node);
		while(!q.empty()) {
			UndirectedGraphNode *tmp=q.front();
			UndirectedGraphNode *clonetmp=maps[tmp];
			q.pop();
			vector<UndirectedGraphNode *> res = tmp->neighbors;
			for(int i = 0; i < res.size(); ++i) {
				UndirectedGraphNode *tm = res[i];
				if(maps.find(tm) != maps.end()) {
					clonetmp->neighbors.push_back(mas.find(tm));
				} else {
					UndirectedGraphNode *cloneNode = new UndirectedGraphNode(tm->label);
					maps.insert(make_pair(tm, cloneNode));
					q.push(tm);
					cloneNode->neighbors.push_back(cloneNode);
				}
			}
		}
		return newnode;
	}
};
