class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        num_rooms = len(rooms)
        visited = [False for _ in range(num_rooms)]
        stack = [0]
        while len(stack) > 0:
            index = stack.pop()
            if visited[index] == False:
                visited[index] = True
                stack.extend(rooms[index])
        
        if all(element == True for element in visited):
            return True
        else:
            return False