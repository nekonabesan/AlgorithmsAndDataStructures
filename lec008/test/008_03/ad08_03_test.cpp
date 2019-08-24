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
/*TEST_F(fixtureName, sample)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
}*/

//============================================================================//
// b. separator
//============================================================================//
TEST_F(fixtureName, separator1)
{
  int *b = separator(10);
  EXPECT_EQ(10, b[4]);
  EXPECT_EQ(5, b[3]);
  EXPECT_EQ(2, b[2]);
  EXPECT_EQ(1, b[1]);
  EXPECT_EQ(0, b[0]);
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
  int *b = separator(7);
  EXPECT_EQ(3, b[2]);
  EXPECT_EQ(1, b[1]);
  EXPECT_EQ(0, b[0]);
  free(b);
}

//============================================================================//
// b. quick merge 01
//============================================================================//
TEST_F(fixtureName, merge01)
{
  int *a = (int *)malloc(8 * sizeof(int));
  int left = 0;
  int mid = 1;
  int right = 2;
  a[0] = 55;
  a[1] = 13;
  a[2] = 3;
  a[3] = 45;
  a[4] = 74;
  a[5] = 87;
  a[6] = 46;
  a[7] = 30;
  // case 01
  merge(a, left, mid, right);
  EXPECT_EQ(13, a[0]);
  EXPECT_EQ(55, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(45, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(46, a[6]);
  EXPECT_EQ(30, a[7]);
  // case 02
  left = 2;
  mid = 3;
  right = 4;
  merge(a, left, mid, right);
  EXPECT_EQ(13, a[0]);
  EXPECT_EQ(55, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(45, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(46, a[6]);
  EXPECT_EQ(30, a[7]);
  // case 03
  left = 0;
  mid = 2;
  right = 4;
  merge(a, left, mid, right);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(46, a[6]);
  EXPECT_EQ(30, a[7]);
  // case 04
  left = 4;
  mid = 5;
  right = 6;
  merge(a, left, mid, right);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(46, a[6]);
  EXPECT_EQ(30, a[7]);
  // case 05
  left = 6;
  mid = 7;
  right = 8;
  merge(a, left, mid, right);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(74, a[4]);
  EXPECT_EQ(87, a[5]);
  EXPECT_EQ(30, a[6]);
  EXPECT_EQ(46, a[7]);
  // case 06
  left = 4;
  mid = 6;
  right = 8;
  merge(a, left, mid, right);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(45, a[2]);
  EXPECT_EQ(55, a[3]);
  EXPECT_EQ(30, a[4]);
  EXPECT_EQ(46, a[5]);
  EXPECT_EQ(74, a[6]);
  EXPECT_EQ(87, a[7]);
  // case 07
  left = 0;
  mid = 4;
  right = 8;
  merge(a, left, mid, right);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(13, a[1]);
  EXPECT_EQ(30, a[2]);
  EXPECT_EQ(45, a[3]);
  EXPECT_EQ(46, a[4]);
  EXPECT_EQ(55, a[5]);
  EXPECT_EQ(74, a[6]);
  EXPECT_EQ(87, a[7]);
  // free
  free(a);
}

//============================================================================//
// b. quick merge 02
//============================================================================//
TEST_F(fixtureName, merge02)
{
  int *a = (int *)malloc(7 * sizeof(int));
  int left = 0;
  int mid = 1;
  int right = 2;
  a[0] = 7;
  a[1] = 6;
  a[2] = 5;
  a[3] = 4;
  a[4] = 3;
  a[5] = 2;
  a[6] = 1;
  // case 01
  merge(a, left, mid, right);
  EXPECT_EQ(6, a[0]);
  EXPECT_EQ(7, a[1]);
  EXPECT_EQ(5, a[2]);
  EXPECT_EQ(4, a[3]);
  EXPECT_EQ(3, a[4]);
  EXPECT_EQ(2, a[5]);
  EXPECT_EQ(1, a[6]);
  // case 02
  left = 2;
  mid = 3;
  right = 4;
  merge(a, left, mid, right);
  EXPECT_EQ(6, a[0]);
  EXPECT_EQ(7, a[1]);
  EXPECT_EQ(4, a[2]);
  EXPECT_EQ(5, a[3]);
  EXPECT_EQ(3, a[4]);
  EXPECT_EQ(2, a[5]);
  EXPECT_EQ(1, a[6]);
  // case 03
  left = 0;
  mid = 2;
  right = 4;
  merge(a, left, mid, right);
  EXPECT_EQ(4, a[0]);
  EXPECT_EQ(5, a[1]);
  EXPECT_EQ(6, a[2]);
  EXPECT_EQ(7, a[3]);
  EXPECT_EQ(3, a[4]);
  EXPECT_EQ(2, a[5]);
  EXPECT_EQ(1, a[6]);
  // case 04
  left = 4;
  mid = 5;
  right = 6;
  merge(a, left, mid, right);
  EXPECT_EQ(4, a[0]);
  EXPECT_EQ(5, a[1]);
  EXPECT_EQ(6, a[2]);
  EXPECT_EQ(7, a[3]);
  EXPECT_EQ(2, a[4]);
  EXPECT_EQ(3, a[5]);
  EXPECT_EQ(1, a[6]);
  // case 06
  left = 4;
  mid = 6;
  right = 8;
  merge(a, left, mid, right);
  EXPECT_EQ(4, a[0]);
  EXPECT_EQ(5, a[1]);
  EXPECT_EQ(6, a[2]);
  EXPECT_EQ(7, a[3]);
  EXPECT_EQ(1, a[4]);
  EXPECT_EQ(2, a[5]);
  EXPECT_EQ(3, a[6]);
  // case 07
  left = 0;
  mid = 4;
  right = 8;
  merge(a, left, mid, right);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
  EXPECT_EQ(5, a[4]);
  EXPECT_EQ(6, a[5]);
  EXPECT_EQ(7, a[6]);
  //  free(a);
}


//============================================================================//
// b. qsort 01
//============================================================================//
TEST_F(fixtureName, msort01)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
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
  msort(a, 10);
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
//============================================================================//
// b. qsort 02
//============================================================================//
TEST_F(fixtureName, msort02)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(7 * sizeof(int));
  a[0] = 7;
  a[1] = 6;
  a[2] = 5;
  a[3] = 4;
  a[4] = 3;
  a[5] = 2;
  a[6] = 1;
  msort(a, 7);
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
// b. qsort 01
//============================================================================//
TEST_F(fixtureName, msort03)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(18 * sizeof(int));
  a[0] = 18;
  a[1] = 17;
  a[2] = 16;
  a[3] = 15;
  a[4] = 14;
  a[5] = 13;
  a[6] = 12;
  a[7] = 11;
  a[8] = 10;
  a[9] = 9;
  a[10] = 8;
  a[11] = 7;
  a[12] = 6;
  a[13] = 5;
  a[14] = 4;
  a[15] = 3;
  a[16] = 2;
  a[17] = 1;
  msort(a, 18);
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(a[1], 2);
  EXPECT_EQ(a[2], 3);
  EXPECT_EQ(a[3], 4);
  EXPECT_EQ(a[4], 5);
  EXPECT_EQ(a[5], 6);
  EXPECT_EQ(a[6], 7);
  EXPECT_EQ(a[7], 8);
  EXPECT_EQ(a[8], 9);
  EXPECT_EQ(a[9], 10);
  EXPECT_EQ(a[10], 11);
  EXPECT_EQ(a[11], 12);
  EXPECT_EQ(a[12], 13);
  EXPECT_EQ(a[13], 14);
  EXPECT_EQ(a[14], 15);
  EXPECT_EQ(a[15], 16);
  EXPECT_EQ(a[16], 17);
  EXPECT_EQ(a[17], 18);
  free(a);
}
//============================================================================//
// b. qsort 01
//============================================================================//
TEST_F(fixtureName, msort04)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(21 * sizeof(int));
  a[0] = 20;
  a[1] = 1;
  a[2] = 18;
  a[3] = 5;
  a[4] = 16;
  a[5] = 17;
  a[6] = 15;
  a[7] = 3;
  a[8] = 13;
  a[9] = 12;
  a[10] = 11;
  a[11] = 10;
  a[12] = 21;
  a[13] = 2;
  a[14] = 7;
  a[15] = 6;
  a[16] = 19;
  a[17] = 4;
  a[18] = 14;
  a[19] = 9;
  a[20] = 8;
  msort(a, 21);
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(a[1], 2);
  EXPECT_EQ(a[2], 3);
  EXPECT_EQ(a[3], 4);
  EXPECT_EQ(a[4], 5);
  EXPECT_EQ(a[5], 6);
  EXPECT_EQ(a[6], 7);
  EXPECT_EQ(a[7], 8);
  EXPECT_EQ(a[8], 9);
  EXPECT_EQ(a[9], 10);
  EXPECT_EQ(a[10], 11);
  EXPECT_EQ(a[11], 12);
  EXPECT_EQ(a[12], 13);
  EXPECT_EQ(a[13], 14);
  EXPECT_EQ(a[14], 15);
  EXPECT_EQ(a[15], 16);
  EXPECT_EQ(a[16], 17);
  EXPECT_EQ(a[17], 18);
  EXPECT_EQ(a[18], 19);
  EXPECT_EQ(a[19], 20);
  EXPECT_EQ(a[20], 21);
  free(a);
}
TEST_F(fixtureName, msort05)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
  int *a = (int *)malloc(7 * sizeof(int));
  a[0] = 1;
  a[1] = 5;
  a[2] = 2;
  a[3] = 3;
  a[4] = 2;
  a[5] = 4;
  a[6] = 4;
  msort(a, 7);
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(a[1], 2);
  EXPECT_EQ(a[2], 2);
  EXPECT_EQ(a[3], 3);
  EXPECT_EQ(a[4], 4);
  EXPECT_EQ(a[5], 4);
  EXPECT_EQ(a[6], 5);
  free(a);
}
