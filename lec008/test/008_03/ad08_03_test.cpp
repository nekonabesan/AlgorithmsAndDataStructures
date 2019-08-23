// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "../ad08_01_target.h"
}

// fixtureNameはテストケース群をまとめるグループ名と考えればよい、任意の文字列
// それ以外のclass～testing::Testまではおまじないと考える
class fixtureName : public ::testing::Test {
protected:
    // fixtureNameでグループ化されたテストケースはそれぞれのテストケース実行前に
    // この関数を呼ぶ。共通の初期化処理を入れておくとテストコードがすっきりする
    virtual void SetUp(){
    }
    // SetUpと同様にテストケース実行後に呼ばれる関数。共通後始末を記述する。
    virtual void TearDown(){
    }
};

// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
TEST_F(fixtureName, sample)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
}

//============================================================================//
// b. separator
//============================================================================//
TEST_F(fixtureName, separator1)
{
  int *b = separator(10);
  EXPECT_EQ(10, b[4]);
  EXPECT_EQ(5, b[3]);
  EXPECT_EQ(3, b[2]);
  EXPECT_EQ(2, b[1]);
  EXPECT_EQ(1, b[0]);
  free(b);
}
TEST_F(fixtureName, separator2)
{
  int *b = separator(8);
  EXPECT_EQ(8, b[3]);
  EXPECT_EQ(4, b[2]);
  EXPECT_EQ(2, b[1]);
  EXPECT_EQ(1, b[0]);
  free(b);
}
TEST_F(fixtureName, separator3)
{
  int *b = separator(15);
  EXPECT_EQ(15, b[4]);
  EXPECT_EQ(8, b[3]);
  EXPECT_EQ(4, b[2]);
  EXPECT_EQ(2, b[1]);
  EXPECT_EQ(1, b[0]);
  free(b);
}

//============================================================================//
// b. quick merge 01
//============================================================================//
TEST_F(fixtureName, merge)
{
  int *a = (int *)malloc(8 * sizeof(int));
  int left = 0;
  int sep = 2;
  int n = 8;
  int end = 4;
  a[0] = 13;
  a[1] = 55;
  a[2] = 3;
  a[3] = 45;
  a[4] = 74;
  a[5] = 87;
  a[6] = 30;
  a[7] = 46;
  // case 01
  // void merge(int *a, int left, int sep, int n, int end)
  merge(a, left, sep, n, end);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(30, a[6]);
  EXPECT_EQ(46, a[7]);
  left = 4;
  end = 8;
  // case 02
  merge(a, left, sep, n, end);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(30, a[4]);
  EXPECT_EQ(46, a[5]);
  EXPECT_EQ(74, a[6]);
  EXPECT_EQ(87, a[7]);
  free(a);
}

//============================================================================//
// b. quick sort 01
//============================================================================//
TEST_F(fixtureName, msort)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(10 * sizeof(int));
  int *b = separator(10);
  a[0] = 20;
  a[1] = 6;
  a[2] = 55;
  a[3] = 74;
  a[4] = 3;
  a[5] = 45;
  a[6] = 13;
  a[7] = 87;
  a[8] = 46;
  a[9] = 30;
  /*msort(a, 1, 10);
  EXPECT_EQ(a[0], 6);
  EXPECT_EQ(a[1], 20);
  EXPECT_EQ(a[2], 55);
  EXPECT_EQ(a[3], 74);
  EXPECT_EQ(a[4], 3);
  EXPECT_EQ(a[5], 45);
  EXPECT_EQ(a[6], 13);
  EXPECT_EQ(a[7], 87);
  EXPECT_EQ(a[8], 30);
  EXPECT_EQ(a[9], 46);
  msort(a, 2, 10);
  EXPECT_EQ(a[0], 6);
  EXPECT_EQ(a[1], 20);
  EXPECT_EQ(a[2], 55);
  EXPECT_EQ(a[3], 74);
  EXPECT_EQ(a[4], 3);
  EXPECT_EQ(a[5], 45);
  EXPECT_EQ(a[6], 13);
  EXPECT_EQ(a[7], 87);
  EXPECT_EQ(a[8], 30);
  EXPECT_EQ(a[9], 46);
  msort(a, 3, 10);
  EXPECT_EQ(a[0], 6);
  EXPECT_EQ(a[1], 3);
  EXPECT_EQ(a[2], 45);
  EXPECT_EQ(a[3], 74);
  EXPECT_EQ(a[4], 20);
  EXPECT_EQ(a[5], 55);
  EXPECT_EQ(a[6], 13);
  EXPECT_EQ(a[7], 87);
  EXPECT_EQ(a[8], 30);
  EXPECT_EQ(a[9], 46);
  msort(a, 5, 10);
  EXPECT_EQ(a[0], 6);
  EXPECT_EQ(a[1], 3);
  EXPECT_EQ(a[2], 45);
  EXPECT_EQ(a[3], 30);
  EXPECT_EQ(a[4], 20);
  EXPECT_EQ(a[5], 55);
  EXPECT_EQ(a[6], 13);
  EXPECT_EQ(a[7], 87);
  EXPECT_EQ(a[8], 74);
  EXPECT_EQ(a[9], 46);*/
  free(a);
  free(b);
}
TEST_F(fixtureName, msort2)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(10 * sizeof(int));
  int *b = separator(10);
  /*a[0] = 55;
  a[1] = 13;
  a[2] = 3;
  a[3] = 45;
  a[4] = 74;
  a[5] = 87;
  a[6] = 46;
  a[7] = 30;
  msort(a, 1, 8);
  EXPECT_EQ(a[0], 13);
  EXPECT_EQ(a[1], 55);
  EXPECT_EQ(a[2], 3);
  EXPECT_EQ(a[3], 45);
  EXPECT_EQ(a[4], 74);
  EXPECT_EQ(a[5], 87);
  EXPECT_EQ(a[6], 30);
  EXPECT_EQ(a[7], 46);
  msort(a, 2, 8);
  EXPECT_EQ(a[0], 3);
  EXPECT_EQ(a[1], 13);
  EXPECT_EQ(a[2], 45);
  EXPECT_EQ(a[3], 55);
  EXPECT_EQ(a[4], 30);
  EXPECT_EQ(a[5], 46);
  EXPECT_EQ(a[6], 74);
  EXPECT_EQ(a[7], 87);*/
  /*msort(a, 2, 8);
  EXPECT_EQ(a[0], 3);
  EXPECT_EQ(a[1], 13);
  EXPECT_EQ(a[2], 30);
  EXPECT_EQ(a[3], 45);
  EXPECT_EQ(a[4], 46);
  EXPECT_EQ(a[5], 55);
  EXPECT_EQ(a[6], 74);
  EXPECT_EQ(a[7], 87);*/
  free(a);
  free(b);
}
//============================================================================//
// c. 帰りがけ順
//============================================================================//
/*TEST_F(fixtureName, insert)
{
  int *a = (int *)malloc(10 * sizeof(int));
  a[0] = 20;
  a[1] = 6;
  a[2] = 55;
  a[3] = 74;
  a[4] = 3;
  a[5] = 45;
  a[6] = 13;
  a[7] = 87;
  a[8] = 46;
  a[9] = 30;

  EXPECT_EQ(a[0], 3);
  EXPECT_EQ(a[1], 6);
  EXPECT_EQ(a[2], 13);
  EXPECT_EQ(a[3], 20);
  EXPECT_EQ(a[4], 30);
  EXPECT_EQ(a[5], 45);
  EXPECT_EQ(a[6], 46);
  EXPECT_EQ(a[7], 55);
  EXPECT_EQ(a[8], 74);
  EXPECT_EQ(a[9], 87);
  free(a);
}*/
