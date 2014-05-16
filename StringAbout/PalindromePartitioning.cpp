class Solution {
public:
	vector<vector<string> > partition(string s) {
		vector<vector<string> > res;
		vector<string> vec;
		partition(res,vec,s,0);
		return res;
	}
	void partition(vector<vector<string> > &res, vector<string> &vec, const string &s, int pos) {
		if(pos == s.size()) {
			res.push_back(vec);
			return;
		}
		for(int i = pos; i < s.size() ; ++i) {
			string str = s.substr(pos, i-pos+1);
			if(judge(str)) {
				vec.push_back(str);
				partition(res,vec,s,i+1);
				vec.pop_back();
			}
		}
	}
	bool judge(const string &s) {
		int i = 0, j = s.size()-1;
		while(i<j) {
			if(s[i] != s[j]) return false;
			++i;--j;
		}
		return true;
	}
};
