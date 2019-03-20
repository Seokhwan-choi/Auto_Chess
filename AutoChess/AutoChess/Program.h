#pragma once
/****************************************************************************
## Program ##
@@ Author : ±Ç¼ø¿ì , Date : 2019.03.20
*****************************************************************************/
class Program
{
private:
	class Image* mImage;
	class Image* mFrameImage;
public:
	Program();
	~Program();

	void Init();
	void Release();
	void Update();
	void Render();
};

