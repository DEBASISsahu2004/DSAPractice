class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> re;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } else {
                re.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        re.push_back({start, end});

        return re;

        // ---> brute force

        // vector<vector<int>> re;
        // sort(intervals.begin(), intervals.end());
        // int n = intervals.size();

        // for (int i = 0; i < n; i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];

        //     if(!re.empty() && end <= re.back()[1]) continue;

        //     for(int j=i+1; j<n; j++){
        //         if(intervals[j][0] <= end){
        //             end = max(end, intervals[j][1]);
        //         }else{
        //             break;
        //         }
        //     }
        //     re.push_back({start, end});
        // }
        // return re;
    }
};