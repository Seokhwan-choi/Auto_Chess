#pragma once
#include "GameObject.h"

/****************************************************************************
## ObjPool ##
@@ Author : �ּ�ȯ,���ѿ�,ä�κ�,������ , Date : 2019.03.22
*****************************************************************************/

class ObjPool
{
private:
	vector<GameObject*> mObjectPool;


private:
	//map<ObjectType, vector<GameObject*>> mPool;
	//map<ObjectType, vector<GameObject*>>::iterator mPoolIter;
	void Release();

public:

	void AddObject(GameObject* gameobject);

	

	ObjPool();
	~ObjPool();
};

