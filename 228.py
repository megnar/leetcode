from typing import Optional, List

"""You are given a sorted unique integer array nums.

A range [a,b] is the set of all integers from a to b (inclusive).

Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b"""

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = []
        if len(nums) == 0:
            return []
        left_bound = 0
        prev_elem = nums[0]
        for i in range(1, len(nums)):
            if nums[i] - prev_elem > 1:
                if i - left_bound > 1:
                    res_str = f"{nums[left_bound]}->{nums[i - 1]}"
                else: 
                    res_str = f"{nums[left_bound]}"
                result.append(res_str)
                left_bound = i
            prev_elem = nums[i]
        i = len(nums) - 1
        if i - left_bound > 0:
            res_str = f"{nums[left_bound]}->{nums[i]}"
        else: 
            res_str = f"{nums[left_bound]}"
        result.append(res_str)
        return result