class Solution {
public:
	int candy(vector<int> &ratings) {
		int n = ratings.size();
		vector<int> candys(n,1);
		int sum=1;
		if(0==n) return 0;
		for(int i = 1; i < n; ++i) 
			if(ratings[i]>ratings[i-1]) candys[i]=candys[i-1]+1;
		for(int i = n-1; i >= 1; --i) {
			if(ratings[i-1]>ratings[i] && candys[i-1] <= candys[i]) 
				candys[i-1]=candys[i]+1;
			sum+=candys[i];
		}
		sum+=candys[0];
		return sum;
	}
};
