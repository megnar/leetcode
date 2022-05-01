

class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        vector<vector<int>> history(n, vector<int> (m) );
        vector<pair<int, int>> numbers(n * m); 
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
            {
                numbers[i * m + j].first = matrix[i][j]; 
                numbers[i * m + j].second = i * m + j;
            }
                
            
        }
        
        sort(numbers.rbegin(), numbers.rend()); 
        for (int k = 0; k < m * n; ++k){
            int i = numbers[k].second / m; 
            int j = numbers[k].second % m; 
            if (i > 0 && matrix[i - 1][j] < matrix[i][j])
                history[i - 1][j] = max(history[i - 1][j], history[i][j] + 1);
            
            if (j > 0 && matrix[i][j - 1] < matrix[i][j])
                history[i][j - 1] = max(history[i][j - 1], history[i][j] + 1);
            
            if (i < n - 1 && matrix[i + 1][j] < matrix[i][j])
                history[i + 1][j] = max(history[i + 1][j], history[i][j] + 1);
            
            if (j < m - 1 && matrix[i][j + 1] < matrix[i][j])
                history[i][j + 1] = max(history[i][j + 1], history[i][j] + 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                
                ans = max(ans, history[i][j]);
            }
        }
        return ans + 1;
    }
};
