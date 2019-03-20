#pragma once
#include <bitset>
#include "Singletonbase.h"
/****************************************************************************
## Input ##
@@ Author : �Ǽ��� , Date : 2019.03.20
*****************************************************************************/
class Input final : public Singletonbase<Input> 
{
	enum : int {KeyMax = 256};
private:
	//�ߺ� Ű ����� ���� ���� Ű�� ���� Ű ���� ���
	std::bitset<KeyMax> mKeyPast;
	std::bitset<KeyMax> mKeyCurrent;
	Vector2 mMousePosition;
public:
	Input();
	virtual ~Input();

	void Update();
	//�ѹ� ���ȴٸ�
	bool GetKeyDown(int key);
	//Ű���� ���� ���ٸ�
	bool GetKeyUp(int key);
	//Ű�� ������ �ִٸ�
	bool GetKey(int key);
	//��� Ű
	bool ToggleKey(int key);

	LRESULT InputProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	inline Vector2 GetMousePosition()const { return this->mMousePosition; }
	POINT GetMousePositionPoint();
};

#define _Input Input::Get()
