class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> reslt(n, 0); 
        reslt[0] = 0;
        for (int i = 0; i < n; ++i){
            if (nums[i] == 0 || i == n - 1)
                continue; 
            for (int j = i + 1; j <= i + nums[i] && j < n; ++j){
                if (reslt[j] == 0)
                    reslt[j] = reslt[i] + 1;
                reslt[j] = min(reslt[j], reslt[i] + 1);
            }
        }
        for (auto i : reslt)
            cout << i << " ";
        return reslt[n - 1];
    }
};
