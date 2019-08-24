// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "ad05_02_target.h"
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

struct node {
  struct node *left;
  struct node *right;
  char ope;
  double num;
  double result;
};

// 成功するテストケース。細かい説明はGoogleTestのマニュアルを見てね。
TEST_F(fixtureName, sample)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
}

//============================================================================//
// a.行きがけ順
//============================================================================//
TEST_F(fixtureName, preorder1)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //==========================================//
  // ope
  // LOAD   = 0x4c
  // ADD(+) = 0x41
  // SUB(-) = 0x53
  // MUT(x) = 0x4d
  // DIV(/) = 0x44
  //==========================================//
  double result = 0;
  struct node* n1 = (struct node*)malloc(sizeof(struct node) * 1);
  n1->num = 0;
  n1->ope = MUT;
  struct node* n2 = (struct node*)malloc(sizeof(struct node) * 1);
  n2->num = 0;
  n2->ope = ADD;
  struct node* n3 = (struct node*)malloc(sizeof(struct node) * 1);
  n3->num = 3;
  n3->ope = LOAD;
  struct node* n4 = (struct node*)malloc(sizeof(struct node) * 1);
  n4->num = 4;
  n4->ope = LOAD;
  struct node* n5 = (struct node*)malloc(sizeof(struct node) * 1);
  n5->num = 0;
  n5->ope = SUB;
  struct node* n6 = (struct node*)malloc(sizeof(struct node) * 1);
  n6->num = 6;
  n6->ope = LOAD;
  struct node* n7 = (struct node*)malloc(sizeof(struct node) * 1);
  n7->num = 7;
  n7->ope = LOAD;
  // 二分木構造を生成する処理
  n2->left = n3;
  n2->right = n4;
  n5->left = n6;
  n5->right = n7;
  n1->left = n2;
  n1->right = n5;
  // CASE01
  preorder(n1);
  EXPECT_EQ(n1->num, -7);
  // CASE02
  n6->num = 0;
  n6->ope = ADD;
  struct node* n8 = (struct node*)malloc(sizeof(struct node) * 1);
  n8->num = 4;
  n8->ope = LOAD;
  struct node* n9 = (struct node*)malloc(sizeof(struct node) * 1);
  n9->num = 5;
  n9->ope = LOAD;
  //　ポイントを付け替える処理
  n6->left = n8;
  n6->right = n9;
  preorder(n1);
  EXPECT_EQ(n1->num, 14);
  // 領域を解放する処理
  dest(n1);
}

//============================================================================//
// b.通りがけ順
//============================================================================//
TEST_F(fixtureName, inorder)
{
  // 値を読み出す時には room1 という下請け関数を呼びます。
  // この関数は、人数 i が負のときは 0 を返し、それ以外はroomprice[i] を返します。
}

//============================================================================//
// c. 帰りがけ順
//============================================================================//
TEST_F(fixtureName, postorder)
{

}
