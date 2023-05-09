#include<Windows.h>
#ifdef _DEBUG
#include<iostream>
#endif

using namespace std;

//@brief  コンソール画面にフォーマット付き文字列を表示
//@param formatフォーマット(%dとか%fなどの)
//@param 可変長引数
//@remarks この関数はデバッグ用。デバッグ時にしか動作しない

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


//書かなければいけない関数
LRESULT
WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//ウィンドウが破棄されたら呼ばれる
	if (msg == WM_DESTROY)
	{
		PostQuitMessage(0);//osに対して「もうこのアプリは終わる」と伝える
		return 0;
	}
	return

		DefWindowProc(hwnd, msg, wparam, lparam);//既定の処理を行う
}