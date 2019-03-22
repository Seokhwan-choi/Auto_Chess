#pragma once

/****************************************************************************
## UpdatePool ##
@@ Author : �ּ�ȯ,���ѿ�,ä�κ�,������ , Date : 2019.03.22
*****************************************************************************/

class UpdatePool
{
private:
	vector<GameObject*>	uPool;
	vector<GameObject*>::iterator uPooliter;


public:
	UpdatePool();
	~UpdatePool();

	void AddPool(GameObject*);	//������Ʈ Ǯ�� ���� ������Ʈ �߰� ��¥ ���ž����ϴ�.
	void Release();				//������Ʈ Ǯ�� ��������ϴ�!
	void update();				//Ǯ���� ���ӿ�����Ʈ ���� ���� ������Ʈ �մϴ�.
};

