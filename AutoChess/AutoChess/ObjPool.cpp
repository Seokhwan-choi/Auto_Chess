#include "stdafx.h"
#include "ObjPool.h"


void ObjPool::AddObject(GameObject* gameobject)
{
	mObjectPool.push_back(gameobject);
}

void ObjPool::Release()
{
	for (auto& objp : mObjectPool)
	{
		objp->Release();
		SafeDelete(objp);
	}
}

ObjPool::ObjPool()
{

}


ObjPool::~ObjPool()
{
	Release();
}
