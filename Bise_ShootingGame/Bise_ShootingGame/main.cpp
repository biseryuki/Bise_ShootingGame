#include "DxLib.h"
#include"SceneManager.h"
#include"GameMainScene.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // �^�C�g���� test �ɕύX
    SetMainWindowText("");

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    ////�G���h�摜�f�[�^�̓ǂݍ���
    //if ((g_EndImage = LoadGraph("images/End.bmp")) == -1) return -1;

    //if (ranking.ReadRanking() == -1)  return  -1;    //�����L���O�f�[�^�̓ǂݍ���

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()) );

   /* SceneManager sceneMng((AbstractScene*)new Title());*/

    // �Q�[�����[�v
    while (ProcessMessage() == 0) {

        ClearDrawScreen();		// ��ʂ̏�����

        sceneMng.Update();      //�V�[���̍X�V����
        sceneMng.Draw();        //�V�[���̕`�揈��
        if (sceneMng.ChangeScene() != nullptr)      //�V�[���̕ύX����
        {
            DxLib_End();	// DX���C�u�����g�p�̏I������
            return 0;	// �\�t�g�̏I��
        }

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}