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
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(begin(intervals) , end(intervals) , [](const Interval&a ,  Interval&b){
            return b.start > a.start;
        });
        priority_queue<int , vector<int> , greater<int>> pq;
        for(auto& e : intervals){
            int s = e.start;
            int m = e.end;
            if(!pq.empty() && s >= pq.top()){
                pq.pop();
            }
            pq.push(m);
        }
        return pq.size();
    }
};
