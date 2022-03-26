import unittest  # 標準モジュールを読み込みます
import chapter4  # テスト対象のファイルを読み込みます

class TestA(unittest.TestCase):  # クラスを派生させて自分用のクラスを作ります
    #def test_1(self):
    #  self.assertEqual(chapter4.Solution.divSum01(self, 14, [3, 2, 6, 5]), True)

    #def test_2(self):
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 4), 1)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 5), 2)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 6), 4)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 7), 7)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 8), 13)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 9), 24)
    #  self.assertEqual(chapter4.Solution.divSum_4_1(self, 10), 44)
    
    #def test_3(self):
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 4), 1)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 5), 2)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 6), 4)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 7), 7)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 8), 13)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 9), 24)
    #  self.assertEqual(chapter4.Solution.divSum_4_2(self, 10), 44)

    #def test_5(self):
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 0), 0)
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 3), 0)
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 5), 0)
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 7), 0)
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 9), 0)
    #  self.assertEqual(chapter4.Solution.sum4_5(self, 753), 6)

    def test_6(self):
      self.assertEqual(chapter4.Solution.divSum02(self, 14, [3, 2, 6, 5]), True)

if __name__ == '__main__':
    unittest.main()