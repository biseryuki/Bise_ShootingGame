#include "DxLib.h"
#include"SceneManager.h"
#include"GameMainScene.h"
#include "KeyManager.h"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_COLOR_BIT_16 16


/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // タイトルを test に変更
    SetMainWindowText("");

    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

    ////エンド画像データの読み込み
    //if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;

    //if (ranking.ReadRanking() == -1)  return  -1;    //ランキングデータの読み込み

    SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SetFontSize(20);		// 文字サイズを設定

    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()) );

   /* SceneManager sceneMng((AbstractScene*)new Title());*/

    // ゲームループ
    while (ProcessMessage() == 0) {

        ClearDrawScreen();		// 画面の初期化

        KeyManager::Update();
        if (KeyManager::OnMousePressed(MOUSE_INPUT_LEFT))
        {
            DrawFormatString(200, 200, 0xffffff,"あああ");
        }
      

        sceneMng.Update();      //シーンの更新処理
        sceneMng.Draw();        //シーンの描画処理
        if (sceneMng.ChangeScene() == nullptr)      //シーンの変更処理
        {
            DxLib_End();	// DXライブラリ使用の終了処理
            return 0;	// ソフトの終了
        }

        ScreenFlip();			// 裏画面の内容を表画面に反映

    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}