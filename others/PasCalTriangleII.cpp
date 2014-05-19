class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res(1,1);
		for(int i = 1; i <= rowIndex; ++i) {
			vector<int> vec(res);
			for(int j = 1; j < i; ++j) {
				res[j]=vec[j]+vec[j-1];
			}
			res.push_back(1);
		}
		return res;
	}
};
