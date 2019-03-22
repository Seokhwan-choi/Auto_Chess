#pragma once
/****************************************************************************
## SceneManager ##
@@ Author : ������,���ѿ� , Date : 2019.03.22
*****************************************************************************/

class SceneManager
{
public:
	SceneManager &Get()
	{
		static SceneManager instance;
		return instance;
	}

private:
	map<string,class Scene*> scenePool;					//��Ʈ���� Ű ���� �� Ǯ
	map<string,class Scene*>::iterator scenePooliter;	//���޴��� Ǯ�� ���ͷ�����

	class Scene* currentScene;
	SceneManager();
	~SceneManager();
public:
	void AddScene(const string st, Scene* sc);

	void SetCurrentScene(const string st);

	void Update();

	void Render();

	void Release();

	void SwapScene(const string st);


	
};

#define _SceneManager SceneManager::Get()