// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "./ad08_04_target.h"
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
/*TEST_F(fixtureName, sample)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
}*/


//============================================================================//
// b. quick sort 01
//============================================================================//
TEST_F(fixtureName, msort01)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int n = 8;
  int *a = (int *)malloc(n * sizeof(int));
  int left = 0;
  a[0] = 55;
  a[1] = 13;
  a[2] = 3;
  a[3] = 45;
  a[4] = 74;
  a[5] = 87;
  a[6] = 46;
  a[7] = 30;
  msort(a, left, n);
  EXPECT_EQ(a[0], 3);
  EXPECT_EQ(a[1], 13);
  EXPECT_EQ(a[2], 30);
  EXPECT_EQ(a[3], 45);
  EXPECT_EQ(a[4], 46);
  EXPECT_EQ(a[5], 55);
  EXPECT_EQ(a[6], 74);
  EXPECT_EQ(a[7], 87);
  free(a);
}
TEST_F(fixtureName, msort2)
{
  int n = 7;
  int *a = (int *)malloc(n * sizeof(int));
  int left = 0;
  a[0] = 5;
  a[1] = 4;
  a[2] = 6;
  a[3] = 1;
  a[4] = 2;
  a[5] = 7;
  a[6] = 3;
  msort(a, left, n);
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(a[1], 2);
  EXPECT_EQ(a[2], 3);
  EXPECT_EQ(a[3], 4);
  EXPECT_EQ(a[4], 5);
  EXPECT_EQ(a[5], 6);
  EXPECT_EQ(a[6], 7);
  free(a);
}
//============================================================================//
// c. msort 03
//============================================================================//
TEST_F(fixtureName, insert)
{
  int n = 10;
  int *a = (int *)malloc(n * sizeof(int));
  int left = 0;
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
  msort(a, left, n);
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
}
