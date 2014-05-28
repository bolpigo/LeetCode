class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int n=s.size();
		vector<string> res;
		for(int i=0; i < n-3; ++i) {
			string s1 = s.substr(0,i+1);
			if(!judge(s1)) break;
			for(int j = i+1; j < n-2; ++j) {
				string s2 = s.substr(i+1, j-i);
				if(!judge(s2)) break;
				for(int k = j+1; k < n-1; ++k) {
					string s3 = s.substr(j+1, k-j);
					if(!judge(s3)) break;
					string s4 = s.substr(k+1);
					if(!judge(s4)) continue;
					string tmp = s1+"."+s2+"."+s3+"."+s4;
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
private:
	bool judge(string &s) {
		if(s.size() > 1 && s[0] == '0') return false;
		int i = atoi(s.c_str());
		if(i > 255) return false;
		return true;
	}
};
