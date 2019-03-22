#pragma once
#include "GameObject.h"

/****************************************************************************
## ObjPool ##
@@ Author : 최석환,신한영,채민병,전우현 , Date : 2019.03.22
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

