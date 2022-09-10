class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if (a[0] < b[0]){
            return true;
        }
        else
            return false; 
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare); 
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> output; 
        for (int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] <= end)
                end = max(end, intervals[i][1]);
            else{
                vector<int> add(2);
                add[0] = start; 
                add[1] = max(end, intervals[i - 1][1]); 
                output.push_back(add); 
                start = intervals[i][0]; 
                end = intervals[i][1];
            }
        }
        vector<int> add(2);
        add[0] = start; 
        add[1] = max(end ,intervals[intervals.size() - 1][1]); 
        output.push_back(add); 
        return output; 

        
    }
};
