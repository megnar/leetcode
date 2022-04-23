
class Solution {
public:
    
    
    string smallestSubsequence(string s) {
    int n = s.size();
    vector<int> cnt(26), used(26);
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']++;
    }
    string ans = ""; 
    for (int i = 0; i < n; ++i) {
        cnt[s[i] - 'a']--;
        if (used[s[i] - 'a'] == 0) {
            while (!ans.empty() && s[i] < ans.back() && cnt[ans.back() - 'a'] > 0) {
                 
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            used[s[i] - 'a'] = 1; 
        }
    }
    return ans; 

}
};
