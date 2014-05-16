class Solution {
public://dp
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		if(0==n) return 0;
		int *dp = new int[n];
		dp[0]=0;
		int ans=0,maxs=INT_MIN;
		for(int i = 1; i < n; ++i) {
			if(ans<0) ans=0;
			ans+=prices.at(i)-prices.at(i-1);
			dp[i]=max(dp[i-1],ans);
		}
		ans=0,maxs=dp[n-1];
		for(int i = n-2; i >= 1; --i) {
			if(ans<0) ans=0;
			ans+=prices.at(i+1)-prices.at(i);
			maxs=max(dp[i-1]+ans,maxs);
		}
		return maxs;
	}
};
