class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.length();
        int s2 = word2.length(); 
        vector<vector<int>> mass(s1 + 1, vector<int>(s2 + 1)); 
        for (int i = 1; i <= s1; ++i){
            mass[i][0] = mass[i - 1][0] + 1;
        }
        for (int i = 1; i <= s2; ++i){
            mass[0][i] = mass[0][i - 1] + 1;
        }
        for (int i = 1; i <= s1; ++i){
            for (int j = 1; j <= s2; ++j){
                int flag = (word1[i - 1] == word2[j - 1] ? 0 : 1);
                mass[i][j] = min(mass[i][j - 1] + 1,
                                 min(mass[i - 1][j] + 1,
                                     mass[i - 1][j - 1] + flag));
                
            }
        }
        return mass[s1][s2]; 
    }
    
};
