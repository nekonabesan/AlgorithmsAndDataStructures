// テストケース記述ファイル
#include "gtest/gtest.h" // googleTestを使用するおまじないはこれだけでOK
// テスト対象関数を呼び出せるようにするのだが
// extern "C"がないとCと解釈されない、意外とハマりがち。
extern "C" {
  #include "ad05_01_target.h"
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
  char label;
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
TEST_F(fixtureName, preorder)
{
  //initialize では先のアルゴリズムによって roomprice を順に初期化しています
  //int *roomprice = (int *)malloc(rmax * sizeof(int));
  //int *roomsel = (int *)malloc(rmax * sizeof(int));
  struct node* n1 = (struct node*)malloc(sizeof(struct node) * 1);
  n1->label = 0x31;
  struct node* n2 = (struct node*)malloc(sizeof(struct node) * 1);
  n2->label = 0x32;
  struct node* n3 = (struct node*)malloc(sizeof(struct node) * 1);
  n3->label = 0x33;
  struct node* n4 = (struct node*)malloc(sizeof(struct node) * 1);
  n4->label = 0x34;
  struct node* n5 = (struct node*)malloc(sizeof(struct node) * 1);
  n5->label = 0x35;
  struct node* n6 = (struct node*)malloc(sizeof(struct node) * 1);
  n6->label = 0x36;
  struct node* n7 = (struct node*)malloc(sizeof(struct node) * 1);
  n7->label = 0x37;
  //
  n2->left = n3;
  n2->right = n4;
  n5->left = n6;
  n5->right = n7;
  n1->left = n2;
  n1->right = n5;
  preorder(n1);
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
