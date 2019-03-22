#pragma once
#include "Scene.h"
class TestScene1 :
	public Scene
{
private:
	Image * meme2;

public:
	TestScene1();
	~TestScene1();

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

};

