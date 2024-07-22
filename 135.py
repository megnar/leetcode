"""There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
"""


from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        lenght = len(ratings)
        candies_left = [1] * lenght
        candies_right = [1] * lenght
        for i in range(lenght - 1):
            if ratings[i + 1] > ratings[i]: 
                candies_left[i + 1] = candies_left[i] + 1
        for i in range(lenght - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies_right[i] = candies_right[i + 1] + 1
        
        result = 0

        for i in range(lenght):
            result += max(candies_left[i], candies_right[i])

        return result
               

if __name__ == '__main__':
    A = [1,0,2]
    sol = Solution()
    print(sol.candy(A))

    A = [1,2,2]
    sol = Solution()
    print(sol.candy(A))