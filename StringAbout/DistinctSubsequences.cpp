class Solution {
public:
	int numDistinct(string S, string T) {
		int n1=S.size()+1,n2=T.size()+1;
		vector<vector<int> > dp(n2,vector<int>(n1));
		for(int i = 0; i < n1; ++i) {
			dp[0][i]=1;
		}
		for(int i = 1; i < n2; ++i) {
			for(int j = 1; j < n1; ++j) {
				dp[i][j]=dp[i][j-1];
				if(S[j-1]==T[i-1])
					dp[i][j]+=dp[i-1][j-1];
			}
		}
		return dp[n2-1][n1-1];
	}
};
