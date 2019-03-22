#include "stdafx.h"
#include "UpdatePool.h"


UpdatePool::UpdatePool()
{
}


UpdatePool::~UpdatePool()
{
}

void UpdatePool::AddPool(GameObject * gp)
{
	uPool.push_back(gp);
}

void UpdatePool::Release()
{
	for (auto& upd : uPool)
	{
		upd->Release();
		SafeDelete(upd);
	}
	uPool.clear();
}

void UpdatePool::update()
{
	for (int i = 0; i < uPool.size(); i++)
	{
		uPool[i]->Update();
	}
}
