#pragma once

class Scene
{
	//objpool
public:
	Scene() {}
	virtual ~Scene();
	
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

	virtual string Changescene();
};

