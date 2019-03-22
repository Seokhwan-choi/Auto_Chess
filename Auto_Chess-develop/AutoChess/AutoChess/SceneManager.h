#pragma once
/****************************************************************************
## SceneManager ##
@@ Author : ������,���ѿ� , Date : 2019.03.22
*****************************************************************************/

class SceneManager final : public SingletonBase<SceneManager>
{
private:
	map<string,class Scene*> scenePool;					//��Ʈ���� Ű ���� �� Ǯ
	map<string,class Scene*>::iterator scenePooliter;	//���޴��� Ǯ�� ���ͷ�����

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