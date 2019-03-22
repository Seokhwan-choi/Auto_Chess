#pragma once
/****************************************************************************
## Program ##
@@ Author : �Ǽ��� , Date : 2019.03.20
*****************************************************************************/

class Program
{
private:
	class Transform* mRoot; 
	class Transform* mTarget;

	vector<class Transform*> mTransformList;


public:
	Program();
	~Program();

	void Init();
	void Release();
	void Update();
	void Render();
};

