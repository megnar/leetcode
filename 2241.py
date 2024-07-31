from typing import List

class ATM:

    def __init__(self):
        self.current = [0]*5
        self.banknotes = {0 : 20, 1 : 50, 2 : 100, 3 : 200, 4 : 500}
        

    def deposit(self, banknotesCount: List[int]) -> None:
        for i in range(5):
            self.current[i] += banknotesCount[i]


    def withdraw(self, amount: int) -> List[int]:
        result = [0] * 5
        for i in range(4, -1, -1):
            banknote = self.banknotes[i]
            result[i] = min(amount // banknote, self.current[i])
            self.current[i] -= result[i]
            amount -= banknote * result[i]
        if amount != 0:
            for i in range(5):
                self.current[i] += result[i]
            return [-1]
        else:
            return result
       


if __name__ == '__main__':
    a = ATM()
    print(a.withdraw(600))