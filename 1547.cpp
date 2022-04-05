#define _CRT_SECURE_NO_WARNING

#include <iostream> 
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_set>
#include <cmath>
#include <string>
#include <sstream>
#include <numeric>
#include <list>
#include <thread>
#include <functional>
#include <cstdio>
using namespace std; 





int minCost(int n, vector<int>& cuts) {
	cuts.push_back(0);
	cuts.push_back(n);
	sort(cuts.begin(), cuts.end()); 
	int s = cuts.size();
	vector<vector<int>> dp(s, vector<int>(s, 100000000)); 
	for (int i = 0; i < s - 1; ++i) {
		dp[i][i + 1] = 0;
	}
	for (int j = 2; j < s; ++j) {
		for (int i = 0; i + j < s; ++i) {
			for (int k = 1; k < j; ++k) {
				dp[i][i + j] = min(dp[i][i + j], dp[i][i + j - k] + dp[i + j - k][i + j] + cuts[i + j] - cuts[i]);
			}
			
		}
	}
	
	return dp[0][s - 1];
	
}
/*
* 9 5
5 6 1 4 2
7 4
1 3 4 5

*/
int main() {
	//freopen("input.txt", "w", stdout);
	
		
	int n, k; 
	cin >> n >>  k; 
	vector<int> cuts(k); 
	for (auto &i : cuts)
		cin >> i; 
	cout << minCost(n, cuts); 
}

