#include "stdafx.h"
#include "RenderPool.h"


void RenderPool::Render()
{
}

void RenderPool::RequestRender(const Layer & layer, GameObject * const pObject)
{
	mRenderPool[layer].push_back(pObject);
}

void RenderPool::RemoveRender(const Layer & layer, GameObject * const pObject)
{
	for (int i = 0; i < mRenderPool[layer].size(); i++)
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
