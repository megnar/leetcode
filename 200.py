class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0
        m = len(grid)
        n = len(grid[0])
        visited = [[False for _ in range(n)] for _ in range(m)]
        for first_index in range(m):
            for second_index in range(n):
                if not visited[first_index][second_index]:
                    if grid[first_index][second_index] == "1":
                        result += 1
                        stack = [[first_index, second_index]]
                        while len(stack) > 0:
                            ind1, ind2 = stack.pop()
                            if visited[ind1][ind2] == False and grid[ind1][ind2]  == "1":
                                visited[ind1][ind2] = True
                                if ind1 > 0 and grid[ind1 - 1][ind2]:
                                    stack.append([ind1 - 1, ind2])
                                if ind1 < m - 1 and grid[ind1 + 1][ind2]:
                                    stack.append([ind1 + 1, ind2])
                                if ind2 > 0 and grid[ind1][ind2 - 1]:
                                    stack.append([ind1, ind2 - 1])
                                if ind2 < n - 1 and grid[ind1][ind2 + 1]:
                                    stack.append([ind1, ind2 + 1])
                    else:
                        visited[first_index][second_index] = True
        return result
