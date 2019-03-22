#include "stdafx.h"
#include "ObjPool.h"

#include "GameObject.h"

void ObjPool::AddObject(GameObject* gameobject)
{
	mObjectPool.push_back(gameobject);
}

void ObjPool::DeleteObject(GameObject * const pObject)
{
	for (UINT i = 0; i < mObjectPool.size(); ++i)
	{
		if (mObjectPool[i] == pObject)
		{
			mObjectPool[i]->Release();
			SafeDelete(mObjectPool[i]);
			mObjectPool.erase(mObjectPool.begin() + i);
			break;
		}
	}
}

GameObject * const ObjPool::FindObject(const string & name)
{
	for (UINT i = 0; i < mObjectPool.size(); ++i)
	{
		if (mObjectPool[i]->GetName() == name)
		{
			return mObjectPool[i];
		}
	}
	return nullptr;
}

vector<class GameObject*> ObjPool::FindObjects(const string & name)
{
	vector<GameObject*> result;
	for (UINT i = 0; i < mObjectPool.size(); ++i)
	{
		if (mObjectPool[i]->GetName() == name)
			result.push_back(mObjectPool[i]);
	}
	return result;
}

const vector<class GameObject*>* const ObjPool::GetObjectPool()
{
	return &mObjectPool;
}

void ObjPool::Release()
{
	for (UINT i = 0; i < mObjectPool.size(); ++i)
	{
		mObjectPool[i]->Release();
		SafeDelete(mObjectPool[i]);
	}
	mObjectPool.clear();
}

ObjPool::ObjPool()
{

}


ObjPool::~ObjPool()
{
	Release();
}
