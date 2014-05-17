class Solution {
public://with extra n space
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        if(0==m)
            return 0;
        int* dp = new int[m];
        memset(dp,-1,sizeof(m));
        dp[0]=triangle[0][0];
        int minPath = dp[0];
        for(int i = 1; i < m; i++) {
            int* tmp = new int[i+1];
            for(int j = 0; j <= i; j++) {
                tmp[j]=dp[j];
                if(j==0) {
                    dp[j]=tmp[j]+triangle[i][j];
                    minPath = dp[j];
                } else if(j==i) {
                    dp[j]=tmp[j-1]+triangle[i][j];
                }else {
                    dp[j]=min(tmp[j]+triangle[i][j],tmp[j-1]+triangle[i][j]);
                }
                if(minPath > dp[j])
                    minPath = dp[j];
            }
            delete []tmp;
        }
	delete []dp;
        return minPath;
    }
};
