from typing import Optional, List

"""Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

"""

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        length = len(nums)
        if length < 2:
            return 0
        result = 0
        left_bound = 0
        right_bound = 1
        count_ones = 0
        count_zeros = 0
        if nums[0] == 1:
            count_ones += 1
        else:
            count_zeros += 1
        
        for i in range(1, length):
            if nums[i] == 1:
                count_ones += 1
            else:
                count_zeros += 1
            right_bound += 1

            if count_zeros < 2:
                result = max(result, count_ones + count_zeros - 1)
            else:
                while count_zeros > 1:
                    if nums[left_bound] == 1:
                        count_ones -= 1
                    else:
                        count_zeros -= 1
                    left_bound += 1
        
        return result
                
            