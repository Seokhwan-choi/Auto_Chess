#include "stdafx.h"
#include "RenderPool.h"


void RenderPool::Release()
{
	RenderPoolIter iter = mRenderPool.begin();
	for (; iter != mRenderPool.end(); ++iter)
	{
		iter->second.clear();
	}
}

void RenderPool::Render()
{
	RenderPoolIter iter = mRenderPool.begin();
	for (; iter != mRenderPool.end(); ++iter)
	{
		for (UINT i = 0; i < iter->second.size(); ++i)
		{
			if (iter->second[i]->GetIsActive() == true)
				iter->second[i]->Render();
		}
	}
}

void RenderPool::RequestRender(const Layer & layer, GameObject * const pObject)
{
	mRenderPool[layer].push_back(pObject);
}

void RenderPool::RemoveRender(const Layer & layer, GameObject * const pObject)
{
	for (UINT i = 0; i < mRenderPool[layer].size(); i++)
	{
		if (mRenderPool[layer][i] == pObject)
		{
			mRenderPool[layer].erase(mRenderPool[layer].begin() + i);
			break;
		}
	}
}

void RenderPool::Zorder()
{
}
