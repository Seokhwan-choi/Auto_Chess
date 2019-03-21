#pragma once
class GameObject
{
protected:
	string mName;
	Vector2 mSize;
	Vector2 mPosition;
	Figure::FloatRect mRect;
	bool mIsActive;
	Pivot::Enum mPivot;

private:
	GameObject(const GameObject& gameobject) {}
public:
	
	void SetSize(const Vector2& size);
	void SetPosition(const Vector2& position);
	void SetPivot(const Pivot::Enum pivot);
	void SetName(const string& name) { mName = name; }
	void SetIsActive(const bool& IsActive) { mIsActive = IsActive; }

	Vector2 GetSize() const { return mSize; }
	Vector2 GetPosition() const { return mPosition; }
	bool GetIsActive() const { return mIsActive; }
	Pivot::Enum GetPivot() const { return mPivot; }
	Figure::FloatRect GetRect() const { return mRect; }

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	GameObject();
	~GameObject();
};

