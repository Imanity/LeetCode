#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int pos1 = 0, pos2 = 0;
        int status1 = 0, status2 = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start >= newInterval.start) {
                status1 = 1;
                pos1 = i;
                break;
            }
            if (intervals[i].end >= newInterval.start) {
                status1 = 2;
                pos1 = i;
                break;
            }
        }
        if (!status1) {
            status1 = 1;
            pos1 = intervals.size();
        }
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start > newInterval.end) {
                status2 = 1;
                pos2 = i;
                break;
            }
            if (intervals[i].end > newInterval.end) {
                status2 = 2;
                pos2 = i;
                break;
            }
        }
        if (!status2) {
            status2 = 1;
            pos2 = intervals.size();
        }
        vector<Interval> newIntervals;
        for (int i = 0; i < pos1; ++i) {
            newIntervals.push_back(intervals[i]);
        }
        Interval tmp;
        if (status1 == 1) {
            tmp.start = newInterval.start;
        } else {
            tmp.start = intervals[pos1].start;
        }
        if (status2 == 1) {
            tmp.end = newInterval.end;
        } else {
            tmp.end = intervals[pos2].end;
        }
        newIntervals.push_back(tmp);
        int tmpPos = status2 == 1 ? pos2 : pos2 + 1;
        for (int i = tmpPos; i < intervals.size(); ++i) {
            newIntervals.push_back(intervals[i]);
        }
        return newIntervals;
    }
};

int main() {
    Interval interval[] = { Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16) };
    vector<Interval> intervals(&interval[0], &interval[5]);
    Interval newInt(4, 9);
    Solution s;
    vector<Interval> res = s.insert(intervals, newInt);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i].start << "\t" << res[i].end << endl;
    }
    cin.get();
    return 0;
}
