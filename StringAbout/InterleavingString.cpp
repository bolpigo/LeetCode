class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size()+1;
		int n = s2.size()+1;
		if(s3.size() != s1.size() + s2.size()) return false;
		if(s1.size() == 0) return s2==s3;
		if(s2.size() == 0) return s1==s3;
		bool **dp = new bool*[m];
		for(int i = 0; i < m; ++i) {
			dp[i] = new bool[n];
			for(int j = 0; j < n; ++j) {
				dp[i][j] = false;
			}
		}
		dp[0][0] = true;
		for(int i = 1; i < m; ++i) {
			dp[i][0] = s1[i-1]==s3[i-1];
		}
		for(int i = 1; i < n; ++i) {
			dp[0][i] = s2[i-1]==s3[i-1];
		}
		for(int i = 1; i < m; ++i) {
			for(int j = 1; j < n; ++j) {
				dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
			}
		}
		bool tmp = dp[m-1][n-1];
		for(int i = 0; i < m; ++i) {
			delete[] dp[i];
		}
		delete[] dp;
		return tmp;
	}
};
