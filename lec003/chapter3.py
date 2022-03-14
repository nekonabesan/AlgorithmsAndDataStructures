from pickle import FALSE, TRUE


class Solution(object):
  def calcString(self, str):
    n = len(str)
    res = 0
    for bit in range(1 << (n - 1)):
      tmp = 0
      for i in range(n - 1):
        tmp *= 10
        tmp += (int(str[i]) - 0)

        if (bit and (i << 1)):
          res += tmp
          tmp = 0
      tmp *= 10
      tmp += (int(str[n - 1]) - 0)
      res += tmp

    return res
