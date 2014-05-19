class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res;
		if(numRows==0) return res;
		res.push_back(vector<int>(1,1));
		for(int i = 1; i < numRows; ++i) {
			vector<int> tmp = res[i-1];
			vector<int> cur(1,1);
			for(int j = 1; j < i; ++j) {
				cur.push_back(tmp[j-1]+tmp[j]);
			}
			cur.push_back(1);
			res.push_back(cur);
		}
		return res;
	}
};
