#pragma once
class SceneManager
{
private:
	map<string,class Scene*> scenePool;					//스트링이 키 값인 씬 풀
	map<string,class Scene*>::iterator scenePooliter;	//씬메니저 풀의 이터레이터

	class Scene* currentScene;

public:
	void AddScene(const string st, Scene* sc);

	void SetCurrentScene(const string st);

	void Update();

	void Render();

	void Release();

	void SwapScene(const string st);


	SceneManager();
	~SceneManager();
};

