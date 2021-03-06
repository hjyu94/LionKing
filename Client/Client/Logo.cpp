#include "stdafx.h"
#include "Logo.h"

#include "Player.h"
#include "Giraffe.h"

CLogo::CLogo()
{
}


CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	CBitmapMgr::Get_Instance()->InsertBmp(L"../Image/Logo/Logo_1.bmp", L"Logo_1");
	CBitmapMgr::Get_Instance()->InsertBmp(L"../Image/Logo/Logo_2.bmp", L"Logo_2");
	m_dwIntro = GetTickCount();
}

void CLogo::Update()
{
}

void CLogo::LateUpdate()
{
	// ## 치트키
	// 1 누르면 스테이지 1 시작
	if (CKeyMgr::Get_Instance()->KeyDown(VK_NUMPAD1))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE);
	}

	// 2 누르면 스테이지 2 시작
	if (CKeyMgr::Get_Instance()->KeyDown(VK_NUMPAD2))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_STAGE_2);
	}

	// L 누르면 라인 에디터 시작
	if (CKeyMgr::Get_Instance()->KeyDown('L'))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_LINE_EDIT);
	}

	// T 누르면 stage2 라인 에디터 시작
	if (CKeyMgr::Get_Instance()->KeyDown('T'))
	{
		CSceneMgr::Get_Instance()->SceneChange(CSceneMgr::SCENE_LINE_EDIT_2);
	}
	
	
}

void CLogo::Render(HDC hDC)
{
	HDC hMemDC = nullptr;

	if (m_dwIntro + 2000 > GetTickCount())
	{
		hMemDC = CBitmapMgr::Get_Instance()->FindImage(L"Logo_1");
	}
	else
	{
		hMemDC = CBitmapMgr::Get_Instance()->FindImage(L"Logo_2");
	}

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CLogo::Release()
{
}
