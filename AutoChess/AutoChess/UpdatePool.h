#pragma once

/****************************************************************************
## UpdatePool ##
@@ Author : 최석환,신한영,채민병,전우현 , Date : 2019.03.22
*****************************************************************************/

class UpdatePool
{
private:
	vector<GameObject*>	uPool;
	vector<GameObject*>::iterator uPooliter;


public:
	UpdatePool();
	~UpdatePool();

	void AddPool(GameObject*);	//읍데이트 풀에 게임 오브젝트 추가 진짜 별거없습니다.
	void Release();				//업데이트 풀을 비워버립니다!
	void update();				//풀내의 게임오브젝트 들을 전부 읍데이트 합니다.
};

