#pragma once
/**********************************************************************
## Transform ## 
@@ Author : �Ǽ��� , Date : 2019.03.21 

��ǥ �� ������, ��Ʈ ����
�� Transform�� ���������� �����ϰ� ����(�� ����� �����Ƿ� ������ ���� �ȳ־���)
************************************************************************/
class Transform final
{
private:
	Vector2 mWorldPosition;
	Vector2 mLocalPosition;
	Vector2 mSize;
	Pivot::Enum mPivot; 
	Figure::FloatRect mRect; 

	Transform* mParent; 
	Transform* mFirstChild;
	Transform* mNextSibling;
private:
	Transform(const Transform& t) {}
	Transform operator=(const Transform& t ) {}
public:
	Transform();
	Transform(const Vector2& pos, const Vector2& size, const Pivot::Enum& pivot = Pivot::LeftTop);
	virtual ~Transform();

	void AddChild( Transform*const pChild);
	void AttachTo( Transform*const pParent);
	void ReleaseParent();
	void DestroyHiararchy();

	void SetWorldPosition(const Vector2& position);
	void SetLocalPosition(const Vector2& position);
	void SetWorldX(const float& x);
	void SetWorldY(const float& y);
	void SetLocalX(const float& x);
	void SetLocalY(const float& y);
	void SetSize(const Vector2& size);
	void SetSizeX(const float& x);
	void SetSizeY(const float& y);
	void Move(const Vector2& moveValue);

	void Render(const D2DRenderer::DefaultBrush& brush,const bool& bRelativeCamera = false);

	const Vector2& GetWorldPosition()const { return this->mWorldPosition; }
	const Vector2& GetLocalPosition()const { return this->mLocalPosition; }
	const Vector2& GetSize()const { return this->mSize; }
	const Pivot::Enum& GetPivot()const { return this->mPivot; }
	const Figure::FloatRect& GetFloatRect()const { return this->mRect; }

	Transform*const GetParent()const { return this->mParent; }
	Transform*const GetFirstChild()const { return this->mFirstChild; }
private:
	void UpdateTransform(); 
};
