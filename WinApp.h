#pragma once
#include <Windows.h>
//WindowsAPI
class WinApp
{
public:
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

	//getter
	HWND GetHwnd() const { return hwnd; }

	HINSTANCE GetHInstance() const { return w.hInstance; }

	bool ProcessMessage();

	// �E�B���h�E����
	static const int WIN_WIDTH = 1280;
	// �E�B���h�E�c��
	static const int WIN_HEIGHT = 720;
public: //�����o�֐�
	//������
	void Initialize();

	//�X�V
	void Update();

	//�I��
	void Finalize();
private:
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;

	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};

};