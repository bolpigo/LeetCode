class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		unordered_map<int,int> maps;
		int maxC=0;
		for(int i = 0; i < num.size(); ++i) {
			maps[num[i]]=0;
		}
		for(int i = 0; i < num.size(); ++i) {
			int curC=1;
			int next=num[i]+1;
			while(maps.find(next)!=maps.end() && maps[next]!=-1) {
				maps[next]=-1;
				curC++;
				next++;
			}
			int pre=num[i]-1;
			while(maps.find(pre)!=maps.end() && maps[pre]!=-1) {
				maps[pre]=-1;
				curC++;
				pre--;
			}
			if(maxC<curC) maxC=curC;
		}
		return maxC;
	}
}
