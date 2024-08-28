class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        left_bound_m = 0
        right_bound_m = m - 1 
        center_m = (left_bound_m + right_bound_m + 1) // 2
        while right_bound_m != left_bound_m:
            if matrix[center_m][0] > target:
                right_bound_m = center_m - 1
            else:
                left_bound_m = center_m
            center_m = (left_bound_m + right_bound_m + 1) // 2

        n = len(matrix[0])
        left_bound_n = 0
        right_bound_n = n - 1 
        center_n = (left_bound_n + right_bound_n + 1) // 2
        while right_bound_n != left_bound_n:
            if matrix[left_bound_m][center_n] > target:
                right_bound_n = center_n - 1
            else:
                left_bound_n = center_n
            center_n = (left_bound_n + right_bound_n + 1) // 2

        if matrix[left_bound_m][left_bound_n] == target:
            return True
        return False 