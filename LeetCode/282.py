class Solution:
    def brute(self, op: str, index: int):
        if index == len(self.num):
            check = op.replace('+', '*').replace('-', '*').split('*')
            for s in check:
                if len(s) > 1 and s[0] == '0': return
            try:
                if eval(op) == self.target:
                    self.ans.append(op)
            finally: return
        else:
            self.brute(op + '+' + self.num[index], index+1)
            self.brute(op + '*' + self.num[index], index+1)
            self.brute(op + '-' + self.num[index], index+1)
            self.brute(op + self.num[index], index+1)
    
    def addOperators(self, num: str, target: int) -> List[str]:
        self.num = num
        self.target = target
        self.ans = []

        self.brute(num[0], 1)

        return self.ans