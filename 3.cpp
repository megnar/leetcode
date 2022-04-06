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

int lengthOfLongestSubstring(string s) {
    vector<int> mass(500, -1);
    int maxlength = 0;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (mass[s[i]] == -1) {
            mass[s[i]] = i;
        }
        else if (mass[s[i]] < j) {
            mass[s[i]] = i;
        }
        else {
            j = mass[s[i]] + 1;
            mass[s[i]] = i;
        }
        maxlength = max(maxlength, i - j + 1);
    }
    return maxlength;
}