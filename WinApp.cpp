#include "WinApp.h"
#include <Windows.h>

LRESULT WinApp::WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	//メッセージで分岐
	switch (msg) {
	case WM_DESTROY: //ウィンドウが破棄された
		PostQuitMessage(0); //OSに対して、アプリの終了を伝える
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam); //標準の処理を行う
}

bool WinApp::ProcessMessage()
{
	MSG msg{};//メッセージ
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&msg);//キー入力メッセージの処理
		DispatchMessage(&msg);//プロシージャーにメッセージを送る
	}

	if (msg.message == WM_QUIT) {
		return true;
	}

	return false;
}

void WinApp::Initialize()
{
	//ウィンドウサイズ

	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProc;    //ウィンドウプロシージャを設定
	w.lpszClassName = L"DirectXGame";       //ウィンドクラス名
	w.hInstance = GetModuleHandle(nullptr); //ウィンドハンドル
	w.hCursor = LoadCursor(NULL, IDC_ARROW);//カーソル指定

	//ウィンドクラスを05に登録する
	RegisterClassEx(&w);
	//ウィンドサイズ{X座標　Y座標　横幅　縦幅}
	RECT wrc = { 0, 0, WIN_WIDTH, WIN_HEIGHT };
	//自動でサイズを補正する
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	//ウィンドウオブジェクトの生成
	/*HWND*/ hwnd = CreateWindow(w.lpszClassName,//クラス名
		L"DirectXGame",//タイトルバーの文字
		WS_OVERLAPPEDWINDOW,//標準的なウィンドウスタイル
		CW_USEDEFAULT,//標準X座標 (05に任せる)
		CW_USEDEFAULT,//標準Y座標 (05に任せる)
		wrc.right - wrc.left,//ウィンドウ横幅
		wrc.bottom - wrc.top,//ウィンドウ縦幅
		nullptr,
		nullptr,
		w.hInstance,
		nullptr);
	//ウィンドウを表示状態にする
	ShowWindow(hwnd, SW_SHOW);
}

void WinApp::Update()
{
}

void WinApp::Finalize()
{
	//ウィンドウクラスを登録解除
	UnregisterClass(w.lpszClassName, w.hInstance);
}
