class Solution {
public:
	int judge(const string &s) {
		if(s=="+") return 1;
		if(s=="-") return 2;
		if(s=="*") return 3;
		if(s=="/") return 4;
		return 0;
	}
	int evalRPN(vector<string> &tokens) {
		stack<int> st;
		int i = 0;
		if(tokens.size() == 0) return 0;
		while(i != tokens.size()) {
			string s = tokens.at(i);
			int tmp = judge(s);
			if(0!=tmp) {
				int x = st.top();
				st.pop();
				int y = st.top();
				st.pop();
				int z;
				if(1==tmp) z=x+y; 
				if(2==tmp) z=y-x;
				if(3==tmp) z=y*x;
				if(4==tmp) z=y/x;
				st.push(z);
			} else {
				st.push(atoi(s.c_str()));
			}
			++i;
		}
		return st.top();
	}
}
