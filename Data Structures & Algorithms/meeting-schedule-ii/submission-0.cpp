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
    int minMeetingRooms(vector<Interval>& intervals) {
        int rooms = 0;
        int curr=0;
        vector<int> start, end;
        for(auto interval: intervals)
        {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i=0, j=0;
        while(i<start.size())
        {
            if(start[i]<end[j]) 
            {
                curr++;
                i++;
            }
            else if(start[i]>end[j])
            {
                curr--;
                j++;
            }
            else
            {
                i++; j++;
            }
            rooms = max(rooms, curr);
        }

        return rooms;
    }
};
