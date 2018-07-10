// leetcode57: insert-interval
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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	vector<Interval> ans;
	int ans_size = 0;
	int intervals_size = intervals.size();

	if (intervals_size == 0) {
		ans_size = 1;
		ans.resize(ans_size);
		ans[0] = newInterval;
	} else {
		// sort the intervals based on the start item
		sort(intervals.begin(), intervals.end(), sort_cmp);

		// the edges of the merged interval 
		int newItem_left = newInterval.start;
		int newItem_right = newInterval.end;

		// this flag is used to identify the start of the merged interval
		bool meetLeft = false;

		// this flag is used to identify whether we have inserted the new interval
		bool isInserted = false;

		// populate the original intervals to the ans until merging the new interval
		for (int i = 0; i < intervals_size; i++) {
			int l = intervals[i].start;
			int r = intervals[i].end;

			// if this interval exists in the left of the new interval,
			// add this interval to the ans
			if (r < newInterval.start) {
				ans_size++;
				ans.resize(ans_size);
				ans[ans_size-1] = intervals[i];
			}

			// if this interval exists in the right of the new interval
			else if (l > newInterval.end) {
				// if we already acquire the edges of the merged interval,
				// we populate the new interval to the ans
				if (meetLeft) {
					meetLeft = false;

					Interval newItem(newItem_left, newItem_right);
					ans_size++;
					ans.resize(ans_size);
					ans[ans_size-1] = newItem;

					isInserted = true;
				}

				// popualte the current interval to the ans
				ans_size++;
				ans.resize(ans_size);
				ans[ans_size-1] = intervals[i];
			}

			// the following cases are used to decide the left edge and the right edge of merged interval

			// if l <= newInterval.start <= r, we find the start of the merged interval
			else if (l <= newInterval.start && newInterval.start <= r) {
				newItem_left = l;
				meetLeft = true;

				// if the current interval contains the new interval, update the right edge
				if (newInterval.end <= r) {
					newItem_right = r;
				}
			}

			// if newInterval.start < l <= newInterval.end <= r, we find the end of the merged interval
			else if (newInterval.start < l && l <= newInterval.end && newInterval.end <= r) {
				newItem_right = r;
			}

			// otherwise, in this case, the new interval contains the current interval,
			// so we directly skip it.
			else if (newInterval.start < l && r < newInterval.end) {
				continue;
			}
		}

		// for specific case: 
		// intervals: [[1,3]]
		// newInterval: [2,4]
		if (meetLeft) {
			meetLeft = false;

			Interval newItem(newItem_left, newItem_right);
			ans_size++;
			ans.resize(ans_size);
			ans[ans_size-1] = newItem;

			isInserted = true;
		}

		// for specific case: 
		// intervals: [[1,3]]
		// newInterval: [4,5]
		if (!isInserted) {
			Interval newItem(newItem_left, newItem_right);
			ans_size++;
			ans.resize(ans_size);
			ans[ans_size-1] = newItem;
		}
	}

	// for specific case: 
	// intervals: [[1,3]]
	// newInterval: [0,0]
	sort(ans.begin(), ans.end(), sort_cmp);

	// for (int i = 0; i < ans_size; i++) {
	// 	cout << "start:" << ans[i].start << " " << "end:" << ans[i].end << endl; 
	// }

	return ans;
}

void test() {
	vector<Interval> ans;

	vector<Interval> test1;
	Interval t11(1,2);
	Interval t12(3,5);
	Interval t13(6,7);
	Interval t14(8,10);
	Interval t15(12,16);
	Interval newInterval1(4,8);
	test1.resize(5);
	test1[0] = t11;
	test1[1] = t12;
	test1[2] = t13;
	test1[3] = t14;
	test1[4] = t15;
	cout << "test1" << endl;
	ans = insert(test1, newInterval1);

	vector<Interval> test2;
	Interval t21(1,3);
	Interval t22(6,9);
	Interval newInterval2(2,5);
	test2.resize(2);
	test2[0] = t21;
	test2[1] = t22;
	cout << "test2" << endl;
	ans = insert(test2, newInterval2);

	vector<Interval> test3;
	Interval t31(1,5);
	Interval newInterval3(2,3);
	test3.resize(1);
	test3[0] = t31;
	cout << "test3" << endl;
	ans = insert(test3, newInterval3);

	return;
}

int main() {
	test();
	return 0;
}
