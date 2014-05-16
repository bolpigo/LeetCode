class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int maxs=0;
		for(int i = 1; i < prices.size(); ++i) {
			int tmp = prices.at(i)-prices.at(i-1);
			if(tmp > 0) maxs+=tmp;
		}
		return maxs;
	}
};
