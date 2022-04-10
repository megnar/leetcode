/*Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.*/

 


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> ans(nums.size() + 2); 
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] < nums.size() + 2 && nums[i] > 0){
                ans[nums[i]] += 1;
            }
                
        }
        for (int i = 1; i < nums.size() + 2; ++i){
            if (ans[i] == 0)
                return i; 
        }
        return 0;
    }
};
