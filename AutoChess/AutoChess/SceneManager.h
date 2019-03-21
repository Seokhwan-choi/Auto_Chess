#pragma once
class SceneManager
{
private:
	map<string,class Scene*> scenePool;					//��Ʈ���� Ű ���� �� Ǯ
	map<string,class Scene*>::iterator scenePooliter;	//���޴��� Ǯ�� ���ͷ�����

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

