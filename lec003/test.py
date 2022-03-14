import unittest  # 標準モジュールを読み込みます
import chapter3  # テスト対象のファイルを読み込みます

class TestA(unittest.TestCase):  # クラスを派生させて自分用のクラスを作ります
    def test_1(self):
      self.assertEqual(chapter3.Solution.calcString(self, '125'), 176)
      self.assertEqual(chapter3.Solution.calcString(self, '123'), 168)

if __name__ == '__main__':
    unittest.main()