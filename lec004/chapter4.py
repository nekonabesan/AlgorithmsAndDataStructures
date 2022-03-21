class Solution(object):
  # Code 4.9
  def func01(self, i, w, a):
    if (i == 0):
      if (w == 0):
        return True
      else:
        return False

    # a[i - 1]を選ばない場合
    if (Solution.func01(self, i - 1, w, a)):
      return True

    # a[i - 1]を選ぶ場合
    if (Solution.func01(self, i - 1, w - a[i - 1], a)):
      return True

    return False

  # Code 4.9
  def divSum01(self, w, a):
    result = False
    if Solution.func01(self, len(a), w, a):
      result =  True
    return result

  # Code 4.1
  def tri(self, n):
    if n == 0:
      return 0
    elif n == 1:
      return 0
    elif n == 2:
      return 1

    return Solution.tri(self, n - 3) + Solution.tri(self, n - 2) + Solution.tri(self, n - 1)

  # Code 4.1
  def divSum_4_1(self, n):
    return Solution.tri(self, n - 1)

  memo = []

  # Code 4.2
  def tri_02(self, n):
    if n == 0:
      return Solution.memo[0]
    elif n == 1:
      return Solution.memo[1]
    elif n == 2:
      return Solution.memo[2]

    if (Solution.memo[n] != -1):
      return Solution.memo[n]

    return Solution.tri_02(self, n - 3) + Solution.tri_02(self, n - 2) + Solution.tri_02(self, n - 1)
  
  # Code 4.2
  def divSum_4_2(self, n):
    Solution.memo = [-1] * n
    Solution.memo[0] = 0
    Solution.memo[1] = 0
    Solution.memo[2] = 1
    return Solution.tri_02(self, n - 1)

  counter = 0

  # Code 4.5
  # N: 入力
  # cur: 現在の値
  # use: 7, 5, 3 のうちどれを使ったか
  # counter: 答え
  def func4_5(n, cur, use):
    if cur > n:
      return None
    
    if use == 0b111:
      Solution.counter += 1
    
    # 7 を付け加える
    Solution.func4_5(n, cur * 10 + 7, use | 0b001)

    # 5 を付け加える
    Solution.func4_5(n, cur * 10 + 5, use | 0b010)

    # 3 を付け加える
    Solution.func4_5(n, cur * 10 + 3, use | 0b100)

  # Code 4.5
  def sum4_5(self, n):
    Solution.func4_5(n, 0, 0)
    return Solution.counter


