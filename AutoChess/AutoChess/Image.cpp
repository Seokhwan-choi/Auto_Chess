#include "stdafx.h"
#include "Image.h"

/********************************************************************************
## Image ## 
@@ ID2D1Bitmap* bitmap : ImageManager���� ������ ��Ʈ��
@@ TagLoadImageInfo loadinfo : �̹��� ����(Ű��,���� ���) 

�������̹����� �ƴ� �̹��� Ŭ���� ����
*********************************************************************************/
Image::Image(ID2D1Bitmap * const bitmap, const TagLoadedImageInfo & loadinfo)
	:mBitmap(bitmap),mLoadInfo(loadinfo),mScale(1.f),mAlpha(1.f),mAngle(0.f),mMaxFrameX(1),mMaxFrameY(1)
{
	this->mSize.x = (float)this->mBitmap->GetPixelSize().width;
	this->mSize.y = (float)this->mBitmap->GetPixelSize().height;

	FrameRect rc;
	rc.x = 0;
	rc.y = 0;
	rc.width = mSize.x;
	rc.height = mSize.y;
	this->mFrameInfo.push_back(rc);

}
/********************************************************************************
## Image ##
@@ ID2D1Bitmap* bitmap : ImageManager���� ������ ��Ʈ��
@@ TagLoadImageInfo loadinfo : �̹��� ����(Ű��,���� ���)
@@ int maxFrameX : ���� ������ �� 
@@ int maxFrameY : ���� ������ �� 

������ �̹��� Ŭ���� ����
*********************************************************************************/
Image::Image( ID2D1Bitmap * bitmap, const TagLoadedImageInfo & loadinfo, const int & maxFrameX, const int & maxFrameY)
	:mBitmap(bitmap),mLoadInfo(loadinfo),mMaxFrameX(maxFrameX),mMaxFrameY(maxFrameY), mScale(1.f), mAlpha(1.f), mAngle(0.f)
{
	this->mSize.x = (float)mBitmap->GetPixelSize().width;
	this->mSize.y = (float)mBitmap->GetPixelSize().height;

	float frameX = mSize.x / (float)this->mMaxFrameX;
	float frameY = mSize.y / (float)this->mMaxFrameY;

	FrameRect rc;
	for (int j = 0; j < maxFrameY; ++j)
	{
		for (int i = 0; i < maxFrameX; ++i)
		{
			rc.x = (float)i * (frameX);
			rc.y = (float)j * (frameY);
			rc.width = frameX;
			rc.height = frameY;
			this->mFrameInfo.push_back(rc);
		}
	}
}
/********************************************************************************
## ~Image ##
��Ʈ�� ���� 
*********************************************************************************/
Image::~Image()
{
	SafeRelease(mBitmap);
}
/********************************************************************************
## Render ##
@@ int x : �׸� ��ǥ 
@@ int y : �׸� ��ǥ 
@@ Pivot::Enum pivot : �׸� �Ǻ� 
@@ bool isRelative : ī�޶� ���� ���� 
*********************************************************************************/
void Image::Render(const int& x,const int& y,const Pivot::Enum& pivot,const bool& isRelativePos)
{
	//�׸� ������ = ������ * ������
	this->mSize = mSize * mScale;
	//������ ��ǥ
	Vector2 renderPos = GetPivotPosition(x, y, pivot);

	if (isRelativePos)
	{
		//TODO ī�޶� ���� �߰� 	
	}
	//������ ��ǥ �������� ��Ʈ ����
	Figure::FloatRect renderRc(renderPos, mSize,Pivot::LeftTop);
	//Ŭ���ο��� 
	if (renderRc.left > (float)_WinSizeX || renderRc.right < 0.f ||
		renderRc.top > (float)_WinSizeY || renderRc.bottom < 0.f)
	{
		ResetRenderOption();
		return;
	}
	//ũ�� ������ ������� scale��� ���� 
	D2D1::Matrix3x2F scale = D2D1::Matrix3x2F::Scale(mScale,mScale);
	Vector2 offset(0, 0);
	//���η� ������ ���ΰ�
	if (mIsReverseAxisX)
	{
		scale = D2D1::Matrix3x2F::Scale(-mScale, mScale);
		offset.x = mSize.x;
	}
	//���η� ������ ���ΰ�
	if (mIsReverseAxisY)
	{
		scale = D2D1::Matrix3x2F::Scale(mScale,-mScale);
		offset.y = mSize.y;
	}
	//angle������ �������� ȸ�� ��� ���� 
	D2D1::Matrix3x2F rotation = D2D1::Matrix3x2F::Rotation(mAngle, D2D1::Point2F(mSize.x / 2.f, mSize.y / 2.f));
	//��ġ ������ offset���� ������� �̵� ��� ����
	D2D1::Matrix3x2F translation = D2D1::Matrix3x2F::Translation((renderPos.x + offset.x), (renderPos.y + offset.y));
	//������ ���� ���� 
	D2D1_RECT_F dxArea = D2D1::RectF(0.f, 0.f, mSize.x, mSize.y);
	//�̹����� ȭ�鿡 �׷��� ���� ����� ũ����� * ȸ����� * �̵���� 
	//����� ��ȯ��Ģ�� ������ �ȵǹǷ� �ݵ�� ���� ������ ���缭 ������ �־�� �Ѵ�. 
	_D2DRenderer->GetRenderTarget()->SetTransform(scale * rotation * translation);
	//������ ��û
	_D2DRenderer->GetRenderTarget()->DrawBitmap(mBitmap, dxArea, mAlpha);
	//�������� �����ٸ� �ɼǰ� �⺻���� ����
	this->ResetRenderOption();
}
/********************************************************************************
## FrameRender ##
@@ int x : �׸� ��ǥ 
@@ int y : �׸� ��ǥ 
@@ int frameX : ���� ������ 
@@ int frameY : ���� ������ 
@@ Pivot::Enum pivot : �׸� �Ǻ� 
@@ bool isRalative : ī�޶� ���� ���� 
*********************************************************************************/
void Image::FrameRender(const int& x,const int& y,const int& frameX,const int& frameY,const Pivot::Enum& pivot,const bool& isRelativePos)
{
	//�������� �ִ� �������� ����ٸ� �׸��� �ʴ´�. 
	if (frameX >= this->mMaxFrameX || frameY >= this->mMaxFrameY)
	{
		ResetRenderOption();
		return;
	}
	//���� �������ε��� 
	int frame = frameY * mMaxFrameX + frameX;
	//������ = ������ * ������ 
	this->mSize = mSize * mScale;
	//�׸� ��ǥ 
	Vector2 renderPos = GetPivotPosition(x, y, pivot);

	if (isRelativePos)
	{
		//TODOī�޶� ���� �߰�	
	}
	//ī�޶� Ŭ���� 
	Figure::FloatRect renderRc(renderPos, mSize, Pivot::LeftTop);
	if (renderRc.left > (float)_WinSizeX || renderRc.right < 0.f ||
		renderRc.top >(float)_WinSizeY || renderRc.bottom < 0.f)
	{
		ResetRenderOption();
		return;
	}
	//ũ�� ��� ���� 
	D2D1::Matrix3x2F scale = D2D1::Matrix3x2F::Scale(mScale, mScale);
	Vector2 offset(0.f, 0.f);
	if (mIsReverseAxisX)
	{
		scale = D2D1::Matrix3x2F::Scale(-mScale, mScale);
		offset.x = mSize.x;
	}
	if (mIsReverseAxisY)
	{
		scale = D2D1::Matrix3x2F::Scale(mScale,-mScale);
		offset.y = mSize.y;
	}
	//ȸ�� ��� ���� 
	D2D1::Matrix3x2F rotation = D2D1::Matrix3x2F::Rotation(mAngle, D2D1::Point2F(mSize.x / 2.f, mSize.y / 2.f));
	//�̵� ��� ���� 
	D2D1::Matrix3x2F translation = D2D1::Matrix3x2F::Translation((renderPos.x + offset.x), (renderPos.y + offset.y));
	//�׸� ���� ���� 
	D2D1_RECT_F dxArea = D2D1::RectF(0.0f, 0.0f, mSize.x, mSize.y);
	D2D1_RECT_F dxSrc = D2D1::RectF((float)mFrameInfo[frame].x, (float)mFrameInfo[frame].y,
		(float)(mFrameInfo[frame].x + mFrameInfo[frame].width),
		(float)(mFrameInfo[frame].y + mFrameInfo[frame].height));
	//������� ����
	_D2DRenderer->GetRenderTarget()->SetTransform(scale * rotation * translation);
	//������ ��û
	_D2DRenderer->GetRenderTarget()->DrawBitmap(mBitmap, dxArea, mAlpha,
		D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, &dxSrc);

	this->ResetRenderOption();
}
/********************************************************************************
## ResetRenderOption ##
�̹��� Ŭ���� ���� ���� �ɼǵ� ���� �ʱ�ȭ
*********************************************************************************/
void Image::ResetRenderOption()
{
	this->mAlpha = 1.0f;
	this->mScale = 1.0f;
	this->mSize.x = (float)mBitmap->GetPixelSize().width;
	this->mSize.y = (float)mBitmap->GetPixelSize().height;
	this->mIsReverseAxisX = this->mIsReverseAxisY = false;
}
/********************************************************************************
## GetPivotPosition ##
@@ int x : �׸� ��ǥ 
@@ int y : �׸� ��ǥ 
@@ Pivot::Enum pivot : �Ǻ� 

�Ǻ��� ũ�� ������� ��ǥ ��ȯ
*********************************************************************************/
Vector2 Image::GetPivotPosition(const int & x, const int & y, Pivot::Enum pivot)
{
	if (pivot == Pivot::LeftTop)
		return Vector2(x, y);

	Vector2 pos(x, y);

	switch (pivot)
	{
	case Pivot::Center:
		pos.x -= mSize.x * mScale * 0.5f;
		pos.y -= mSize.y * mScale * 0.5f;
		break;

	case Pivot::Bottom:
		pos.x -= mSize.x * mScale * 0.5f;
		pos.y -= mSize.y * mScale;
		break;
	}

	return pos;
}