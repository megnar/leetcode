
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> stack_; // first is height second is index
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int lastindex = i; 
            while (!stack_.empty() && stack_.top().first > heights[i]) {
                lastindex = stack_.top().second; 
                ans = max(ans, stack_.top().first * (i - stack_.top().second));
                stack_.pop(); 
            }
            stack_.push(make_pair(heights[i], lastindex)); 
        }
        while(!stack_.empty()) {
            ans = max(ans, stack_.top().first * (n - stack_.top().second));
            stack_.pop();
        }
        return ans; 
    }
};
