#pragma once
/****************************************************************************
## Program ##
@@ Author : �Ǽ��� , Date : 2019.03.20
*****************************************************************************/
class Program
{
private:
	class Transform* mRoot; 
	class Transform* mChild;
public:
	Program();
	~Program();

	void Init();
	void Release();
	void Update();
	void Render();
};

