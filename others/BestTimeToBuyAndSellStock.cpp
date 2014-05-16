class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int ans=0,maxs=0;
		for(int i = 1; i < prices.size(); ++i) {
			if(ans < 0) ans = 0;
			ans+=prices.at(i)-prices.at(i-1);
			maxs=max(ans,maxs);
		}
		return maxs;
	}
};
