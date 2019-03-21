#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{

}


GameObject::~GameObject()
{

}

void GameObject::SetSize(const Vector2 & size)
{
	mSize = size;
	mRect = Figure::RectMakePivot(mPosition, mSize, mPivot);
}

void GameObject::SetPosition(const Vector2 & position)
{
	mPosition = position;
	mRect = Figure::RectMakePivot(mPosition, mSize, mPivot);
}

void GameObject::SetPivot(const Pivot::Enum& pivot)
{
	mPivot = pivot;
	mRect = Figure::RectMakePivot(mPosition, mSize, mPivot);
}
