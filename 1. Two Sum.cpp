class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> set_; 
        vector<int> ans(2, -1);
        
        
        for (int i = 0; i < nums.size(); ++i){
            auto it = set_.find(target - nums[i]);
            if (it != set_.end()){
                int flag = 0;
                for (int j = 0; j < nums.size(); ++j){
                    if (nums[j] == *it && i != j){
                        ans[0] = i;
                        ans[1] = j;
                        flag = 1; 
                    }
                    if (flag == 1){
                        return ans;
                    }
                }
                
            }
            set_.insert(nums[i]);
        }
        return ans;
        
    }
};
