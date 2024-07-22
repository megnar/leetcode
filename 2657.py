from typing import List


class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        lenght_ar = len(A)
        map_of_chars = {}
        result_list = []
        current_num = 0
        for i in range(lenght_ar):
            if A[i] in map_of_chars:
                current_num += 1
            else: 
                map_of_chars[A[i]] = 1
            
            if B[i] in map_of_chars:
                current_num += 1
            else:
                map_of_chars[B[i]] = 1
            
            result_list.append(current_num)
        
        return result_list
        

if __name__ == '__main__':
    A = [1,3,2,4]
    B = [3,1,2,4]

    sol = Solution()
    print(sol.findThePrefixCommonArray(A, B))