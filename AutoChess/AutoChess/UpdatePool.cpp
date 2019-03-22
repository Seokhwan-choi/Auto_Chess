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
	uPool.clear();
}

void UpdatePool::update()
{
	for (UINT i = 0; i < uPool.size(); i++)
	{
		uPool[i]->Update();
	}
}
