#include<Windows.h>
#ifdef _DEBUG
#include<iostream>
#endif

using namespace std;

//@brief  �R���\�[����ʂɃt�H�[�}�b�g�t���������\��
//@param format�t�H�[�}�b�g(%d�Ƃ�%f�Ȃǂ�)
//@param �ϒ�����
//@remarks ���̊֐��̓f�o�b�O�p�B�f�o�b�O���ɂ������삵�Ȃ�

void DebugOutputFormatString(const char* format, ...)
{
#ifdef _DEBUG
	va_list valist;
	va_start(valist, format);
	printf(format, valist);
	va_end(valist);
#endif // _DEBUG

}

#ifdef _DEBUG
int main()
{
#else
int WINAPI
WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
#endif // _DEBUG


	DebugOutputFormatString("Show window test.");
	getchar();
	return 0;
}


//�����Ȃ���΂����Ȃ��֐�
LRESULT
WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//�E�B���h�E���j�����ꂽ��Ă΂��
	if (msg == WM_DESTROY)
	{
		PostQuitMessage(0);//os�ɑ΂��āu�������̃A�v���͏I���v�Ɠ`����
		return 0;
	}
	return

		DefWindowProc(hwnd, msg, wparam, lparam);//����̏������s��
}