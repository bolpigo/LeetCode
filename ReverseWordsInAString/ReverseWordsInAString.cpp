class Solution {
public:
	vector<string> split(const string &s, char delim) {
		int i = 0;
		vector<string> res;
		while(i<s.size()) {
			string str;
			while(i!=s.size() && s.at(i) != delim) {
				str+=s.at(i);
				++i;
			}
			if(str!="") res.push_back(str);
			++i;
		}
		return res;

	}
	void reverseWords(string &s) {
		vector<string> res = split(s,' ');
		s="";
		if(res.size() == 0) return;
		for(int i = res.size()-1; i >= 1; --i) {
			s+=res.at(i)+" ";
		}
		s+=res.at(0);

	}
}
