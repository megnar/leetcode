class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n < 2:
            return
        index = 0
        while n >= 2:
            for i in range(n - 1):
                first = matrix[0 + index][i + index]
                second = matrix[i + index][n - 1 + index]
                third = matrix[n - 1 + index][n - 1 - i + index]
                forth = matrix[n - 1 - i + index][0 + index]
                matrix[0 + index][i + index] = forth
                matrix[i + index][n - 1 + index] = first
                matrix[n - 1 + index][n - 1 - i + index] = second
                matrix[n - 1 - i + index][0 + index] = third
            n -= 2
            index += 1