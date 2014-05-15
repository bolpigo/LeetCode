class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.size() == 0) return true;
		if(find(dict.begin(),dit.end(),s)!=dict.end()) return true;
		int n = s.size();
		bool *dp = new bool[n];
		memset(dp,false,sizeof(dp)*n);
		for(int i = 0; i < n; ++i) {
			for(int j = i; j >= 0; --j) {
				string r(s.begin()+j,s.begin()+i+1);
				if(find(dict.begin(),dict.end(),r)!=dict.end()) {
					if((j-1 >= 0 && dp[j-1]) || j==0) dp[i]=true;
				}
			}
		}
		bool tmp = dp[n-1];
		delete []dp;
		return tmp;
	}
};
