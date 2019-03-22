#pragma once
#include "Scene.h"
class TestScene : public Scene
{
private:
	Image * meme;

public:
	TestScene();
	~TestScene();


	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();


};

