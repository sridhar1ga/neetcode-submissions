/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compartor(Interval& a, Interval& b)
    {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compartor);

        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i-1].end>intervals[i].start) return false;
        }

        return true;
    }
};
