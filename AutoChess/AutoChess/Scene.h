#pragma once
/****************************************************************************
## ObjPool ##
@@ Author : �ּ�ȯ,���ѿ�,ä�κ�,������ , Date : 2019.03.22
*****************************************************************************/

class Scene
{
	ObjPool mOsPool;		//������Ʈ Ǯ
	RenderPool mRdPool;		//������Ʈ ���� glue
	UpdatePool uPdPool;		//������ƮǮ, ������Ʈ �ʿ��� �ֵ��� ���������! addpool() �� �ִ�.

public:



	Scene() {}
	virtual ~Scene();
	
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

