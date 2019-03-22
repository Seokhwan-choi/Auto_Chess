#include "stdafx.h"
#include "GameInterface.h"

#include "GameObject.h"

/**********************************************************
## IGameObject ##
***********************************************************/
IGameObject::IGameObject(const GameObject * const pObject)
	:iGameObject(pObject)
{
}

/**********************************************************
## IUpdate ##
***********************************************************/
IUpdate::IUpdate(const GameObject *const pObject)
	:IGameObject(pObject)
{
	//_SceneManager->GetUpdatePool()->RequestUpdate(iGameObject);
}

IUpdate::~IUpdate()
{
	this->RemoveUpdate();
}

void IUpdate::RemoveUpdate()
{
	//_SceneManager->GetRenderPool()->RequestUpdate(iGameObject);
}

/**********************************************************
## IRender ##
***********************************************************/

IRender::IRender(const GameObject *const pObject)
	:IGameObject(pObject)
{
	//_SceneManager->GetUpdatePool()->RequestUpdate(iGameObject);
}

IRender::~IRender()
{
	this->RemoveRender();
}

void IRender::RemoveRender()
{
	//_SceneManager->GetRenderPool()->RemoveRender(iGameObject);
}

