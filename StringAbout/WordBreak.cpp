class Solution {
public:
	bool wordBreak(string &s, unordered_set<string> &dict) {
		unordered_set<string> unmatched;
		return wordBreak(s,dict,unmatched);
	}
	bool wordBreak(string &s, unordered_set<string> &dict, unordered_set<string> &unmatched) {
		if(s.size() == 0) return true;
		bool flag = false;
		for(int i = 1; i <= s.size(); ++i) {
			string prestr=s.substr(0,i);
			unordered_set<string>::const_iterator dit=dict.find(prestr);
			if(dit != dict.end()) {
				string poststr=s.substr(i);
				unordered_set<string>::const_iterator uit=uit.find(poststr);
				if(uit != unmatched.end()) continue;
				else {
					flag=wordBreak(poststr,dict,unmatched);
					if(flag) return true;
					else {
						unmatched.insert(poststr);
					}
				}
			}
		}
	}
}
