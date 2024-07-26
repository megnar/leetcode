"""Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
"""

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        stor_t = {}
        stor_s = {}
        for char in t:
            if stor_t.get(char) is not None:
                stor_t[char] += 1
            else:
                stor_t[char] = 1

        minimal = len(s) + 1
        left_ans = 0
        right_ans = 0
        left_current = 0
        right_current = 0

        for char in s:
            right_current += 1
            if stor_s.get(char) is not None:
                stor_s[char] += 1
            else:
                stor_s[char] = 1

            while self.dictContains(stor_t, stor_s):
                if right_current - left_current < minimal:
                    minimal = right_current - left_current
                    left_ans = left_current
                    right_ans = right_current
                
                char2 = s[left_current]
                if stor_s[char2] == 1:
                    stor_s.pop(char2)
                else: 
                    stor_s[char2] -= 1
                left_current += 1
        
        if minimal == len(s) + 1:
            return ""
        else:
            return s[left_ans:right_ans]

    def dictContains(self, dict_t, dict_s) -> bool:
        for k, v in dict_t.items():
            if dict_s.get(k) is not None and dict_s.get(k) >= v:
                continue
            else:
                return False
        return True
    
if __name__ == '__main__':
    sol = Solution()
    print(sol.minWindow("ADOBECODEBANC", "ABC"))  # Output: ["255.255.11.135","255.255.111.35"]

