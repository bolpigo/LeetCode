class Solution {
public:
	bool isPalindrome(string s) {
		string str;
		for(int i = 0; i < s.size(); ++i) {
			if(isalnum(s[i])) {
				str+=tolower(s[i]);
			}
		}
		int i=0, j=str.size()-1;
		while(i<j) {
			if(s[i]!=s[j]) return false;
			++i;--j;
		}
		return true;
	}
};
