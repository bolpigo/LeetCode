class Solution {
public:
	int numTrees(int n) {
		return numTrees(1, n);
	}
private:
	int numTrees(int start, int end) {
		if(start >= end) return 1;
		int sum = 0;
		for(int i = start; i <= end; ++i) {
			sum += numTrees(start, i-1) * numTrees(i+1,end);
		}
		return sum;
	}
};
