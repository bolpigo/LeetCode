class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		int *dp=new int[n+1];
		bool **ispar=new bool*[n];
		for(int i = 0; i < n; ++i) {
			ispar[i] = new bool[n];
			for(int j = 0; j < n; ++j) {
				ispar[i][j] = false;
			}
		}
		dp[n]=0;
		for(int i = n-1; i >= 0; --i) {
			dp[i]=n-i;
			for(int j = i; j < n; ++j) {
				if(s[i]==s[j]) {
					if(j-i <= 2 || ispar[i+1][j-1]) {
						ispar[i][j]=true;
						dp[i]=min(dp[i],dp[j+1]+1);
					}
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			delete []ispar[i];
		}
		delete []ispar;
		int res = dp[0]-1;
		delete []dp;
		return res;
	}
};
