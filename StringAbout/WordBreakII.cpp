class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int n = s.size();
		vector<string> res;
		if(0==n) return res;
		bool *dp = new bool[n];
		memset(dp,false,sizeof(dp)*n);
		for(int i = 0; i < n; ++i) {
			for(int j = i; j >= 0; --j) {
				string r(s.begin()+j,s.begin()+i+1);
				if(find(dict.begin(),dict.end(),r) != dict.end()) {
					if((j-1>=0 && dp[j-1]) || j==0) dp[i]=true;
				}
			}
		}
		dfs(0,n,s,"",dict,res,dp);
		delete []dp;
		return res;
	}
	void dfs(int curn, int n, string &s, string &cur, unordered_set<string> &dict, vector<string> res, bool *dp) {
		if(curn == n) {
			res.push_back(cur);
			break;
		}
		for(int i = curn; i < n; ++i) {
			string r(s.begin()+curn,s.begin()+i+1);
			if((i+1==n || dp[i+1]) && find(dict.begin(),dict.end(),r) != dict.end()) {
				int c = cur.size();
				cur+=r;
				if(i<n-1) cur+=" ";
				dfs(i+1,n,s,cur,dict,res,dp);
				cur.resize(c);
			}
		}
	}
};
