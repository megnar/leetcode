class Solution {
public:
   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> deq; // first index second value
        vector<int> ans; 
        for (int i = 0; i < nums.size(); ++i) {
            
            while (!deq.empty() && deq.front().second < nums[i]) {
                deq.pop_front();
            }
            if (!deq.empty() && deq.back().first <= i - k) {
                deq.pop_back();
            }
            deq.push_front({ i, nums[i]});
            if (i >= k - 1) {
                ans.push_back(deq.back().second); 
            }
        }
        return ans;
      
    }
};
