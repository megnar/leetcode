"""Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]
Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Example 3:

Input: s = ")("
Output: [""]
"""


from typing import List

class Solution:
    set_res = set()
    def removeInvalidParentheses(self, s:str) -> List[str]:
        self.set_res = set()
        l, r = 0, 0
        for c in s:
            if c == "(":
                l += 1
            elif c == ")":
                if l > 0:
                    l -= 1
                else:
                    r += 1
        self.addInSet(s, 0, l, r)
        res = list(self.set_res)
        if len(res) == 0:
            res.append("")
        return res
            
            

    def addInSet(self, s: str, index: int, left: int, right: int):
        lenght = len(s)
        if left == 0 and right == 0 and self.isValid(s):
            self.set_res.add(s)
            return

        if index > len(s) - 1:
            return

        char = s[index]
        self.addInSet(s, index + 1, left, right)
        if char == "(":
            if left != 0:
                s = s[:index] + s[index + 1:]
                print(s, index, left - 1, right)
                self.addInSet(s, index, left - 1, right)
        elif char == ")":
            if right != 0:
                s = s[:index] + s[index + 1:]
                self.addInSet(s, index, left, right - 1)


    def isValid(self, s:str) -> bool:
        l, r = 0, 0
        for i in s:
            if i == "(":
                l += 1
            elif i == ")":
                if l > 0:
                    l -= 1
                else: 
                    return False
        if l == 0:
            return True
        else: 
            return False

