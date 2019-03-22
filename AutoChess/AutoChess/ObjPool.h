#pragma once
#include "GameObject.h"

/****************************************************************************
## ObjPool ##
@@ Author : 최석환,신한영,채민병,전우현 , Date : 2019.03.22
*****************************************************************************/

class ObjPool final
{
	BlockAssign(ObjPool)
private:
	vector<class GameObject*> mObjectPool;
public:
	void AddObject(class GameObject*const gameobject);
	void DeleteObject(class GameObject*const pObject);

	class GameObject*const FindObject(const string& name);
	vector<class GameObject*> FindObjects(const string& name);
	const vector<class GameObject*>*const GetObjectPool();
	
	ObjPool();
	virtual ~ObjPool();

	void Release();
};

