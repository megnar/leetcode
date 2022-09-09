class Solution {
public:
    bool iseq(vector<int> have, vector<int> need){
        for (int i = 0; i < 26; ++i){
            if (have[i] != need[i])
                return false;
        }
        return true; 
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false; 
        vector<int> have(50, 0); 
        vector<int> need(50, 0); 
        for (int i = 0; i < s1.size(); ++i){
            need[s1[i] - 'a']++; 
        }
        
        for (int i = 0; i < s1.size(); ++i){
            have[s2[i] - 'a']++;
        }
        if (iseq(have, need))
            return true; 
        for (int j = s1.size(); j < s2.size(); ++j){
            have[s2[j] - 'a']++;
            have[s2[j - s1.size()] - 'a']--;
            if (iseq(have, need))
                return true;
        }
        return false;
    }
};
