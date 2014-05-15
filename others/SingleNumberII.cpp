class Solution {
public:/*binary sim three calulate*/
	int singleNumber(int A[], int n) {
		int ones=0, twos=0, threes=0;
		for(int i = 0; i < n; ++i) {
			twos |= (ones & A[i]);
			ones ^= A[i];
			threes = ~(ones & twos);//divid with 3
			ones &= threes;
			twos &= threes;
		}
		return ones;
	}
};
