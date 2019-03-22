#pragma once
/****************************************************************************
## SceneManager ##
@@ Author : 전우현,신한영 , Date : 2019.03.22
*****************************************************************************/

class SceneManager final : public SingletonBase<SceneManager>
{
private:
	map<string,class Scene*> scenePool;					//스트링이 키 값인 씬 풀
	map<string,class Scene*>::iterator scenePooliter;	//씬메니저 풀의 이터레이터

	class Scene* currentScene;

public:

	SceneManager() {};
	virtual ~SceneManager() {};

	void AddScene(const string st, Scene* sc);

	void SetCurrentScene(const string st);

	void Update();

	void Render();

	void Release();

	void SwapScene(const string st);


	
};

#define _SceneManager SceneManager::Get()