class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        for(int i = 0;i<n;i++){
            if(intervals[i][0]>newInterval[0]){
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        if(intervals.size()==n) intervals.push_back(newInterval);
        int i = 0;
        while(i<intervals.size()-1){
            if(intervals[i+1][0]<=intervals[i][1]){
                intervals[i][0] = min(intervals[i][0],intervals[i+1][0]);
                intervals[i][1] = max(intervals[i][1],intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
            }
            else i++;
        }

        return intervals;
    }
};