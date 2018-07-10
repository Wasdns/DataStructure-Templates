// leetcode56: merge-intervals
#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

static bool sort_cmp(Interval a, Interval b) {
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> ans;
	int ans_size = 0;
	int intervals_size = intervals.size();

	if (intervals_size == 0 || intervals_size == 1) {
		ans = intervals;
	} else {
		// sort the intervals based on the start item
		sort(intervals.begin(), intervals.end(), sort_cmp);

		Interval intervals_node;
		int intervals_index = 1;
		Interval ans_node;
		int ans_index = 0;

		// in the beginnig, I populate the first interval to the ans
		ans_size++;
		ans.resize(ans_size);
		ans[0] = intervals[0];

		while (intervals_index < intervals_size) {
			intervals_node = intervals[intervals_index];
			ans_node = ans[ans_index];

			// there exists overlap between the two nodes 
			if (intervals_node.start >= ans_node.start && intervals_node.start <= ans_node.end) {
				// ans_node contains interval_node
				if (intervals_node.end <= ans_node.end) {
					intervals_index++;
				} else { // otherwise, merge the two nodes by scaling the right edge of ans_node
					ans_node.end = intervals_node.end;
					ans[ans_index] = ans_node;
					intervals_index++;
				}
			} else { // there exists no overlap between the two nodes
				// create new node in the ans
				ans_size++;
				ans.resize(ans_size);
				ans[ans_size-1] = intervals_node;

				// update indexes
				intervals_index++;
				ans_index++;
			}
		}
	}

	// for (int i = 0; i < ans_size; i++) {
	// 	cout << "start:" << ans[i].start << " " << "end:" << ans[i].end << endl; 
	// }

	return ans;
}

void test() {
	vector<Interval> ans;

	vector<Interval> test1;
	Interval t11(1,3);
	Interval t12(2,6);
	Interval t13(8,10);
	Interval t14(15,18);
	test1.resize(4);
	test1[0] = t11;
	test1[1] = t12;
	test1[2] = t13;
	test1[3] = t14;
	cout << "test1" << endl;
	ans = merge(test1);

	vector<Interval> test2;
	Interval t21(1,4);
	Interval t22(4,5);
	test2.resize(2);
	test2[0] = t21;
	test2[1] = t22;
	cout << "test2" << endl;
	ans = merge(test2);

	return;
}

int main() {
	test();
	return 0;
}
