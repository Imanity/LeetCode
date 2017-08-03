#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compareStart(const Interval &i, const Interval &j) {
    return i.start < j.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compareStart);
        vector<Interval>::iterator i = intervals.begin();
        vector<Interval>::iterator j = intervals.begin();
        while (i != intervals.end()) {
            j = i + 1;
            if (j == intervals.end()) {
                break;
            }
            while (j != intervals.end()) {
                if ((*i).end >= (*j).start) {
                    (*i).end = (*j).end > (*i).end ? (*j).end : (*i).end;
                    j = intervals.erase(j);
                } else {
                    i = j;
                    break;
                }
            }
        }
        return intervals;
    }
};

int main() {
    Interval interval[] = { Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
    vector<Interval> intervals(&interval[0], &interval[4]);
    Solution s;
    vector<Interval> res = s.merge(intervals);
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i].start << "\t" << res[i].end << endl;
    }
    cin.get();
    return 0;
}
