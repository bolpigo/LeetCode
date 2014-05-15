class Solution {
public://×î´ó×Ó´®
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int st=0,n=gas.size(),ans=0,sum=0;
		for(int i = 0; i < n; ++i) {
			sum+=gas[i]-cost[i];
			ans+=gas[i]-cost[i];
			if(ans<0) {
				st=i+1;
				ans=0;
			}
		}
		return sum<0?-1:st;
	}
};
