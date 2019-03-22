#pragma once
/****************************************************************************
## ObjPool ##
@@ Author : 최석환,신한영,채민병,전우현 , Date : 2019.03.22
*****************************************************************************/

class Scene
{
	ObjPool mOsPool;		//오브젝트 풀
	RenderPool mRdPool;		//오브젝트 랜더 glue
	UpdatePool uPdPool;		//업데이트풀, 업데이트 필요한 애들을 등록해주자! addpool() 이 있다.

public:



	Scene() {}
	virtual ~Scene();
	
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();
};

