/**
* Definition for a point.
* struct Point {
*	int x;
*	int y;
*	Point():x(0),y(0){}
*	Point(int a, int b):x(a),y(b){}
* };
*/
class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int res=0;
		for(int i = 0; i < points.size(); ++i) {
			unordered_map<double, int> tmp; //map,斜率与点数的映射
			int sps=0, tmps=1;//相同点sps，当次循环最大不重复点数tmps
			for(int j = i+1; j < points.size(); ++j) {
				Point x = points.at(i);
				Point y = points.at(j);
				double slope =1.1e20;//初始化斜率,模拟雾穷大
				if(x.x!=y.x) {
					slope=(y.y-x.y)*1.0/(y.x-x.x);
				} else if(x.y==y.y){
					sps++;//相同点数++
					continue;
				}
				if(tmp.find(slope)==tmp.end()) {
					tmp[slope]=2;
				} else {
					++tmp[slope];
				}
				if( tmp[slope] > tmps) tmps=tmp[slope];
			}
			if(res < tmps + sps) res = tmps+sps;
		}
		return res;
	}
};
