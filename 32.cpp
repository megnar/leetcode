/*Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> res(n, 0); 
        stack<int> st;
        for(int i = 0; i < n ; ++i){
            if (s[i] == '('){
                st.emplace(i); 
            }
            else if(!st.empty()){
                int j = st.top(); 
                res[i] = res[j] = 1; 
                st.pop(); 
            }
        }
        int maxx = 0; 
        int sum = 0;
        for (int i = 0; i < n; ++i){
            if(res[i] == 1){
                sum += 1; 
            }
            else
                sum = 0;
            maxx = max(maxx, sum); 
            
        }
        return maxx;
    }
};
