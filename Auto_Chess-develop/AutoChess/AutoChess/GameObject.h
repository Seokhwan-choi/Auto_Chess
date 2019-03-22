#pragma once
class GameObject
{
protected:
	string mName;
	Vector2 mSize;
	Vector2 mPosition;
	Figure::FloatRect mRect;
	bool mIsActive;
	ObjectType mType;
	Pivot::Enum mPivot;
private:
	GameObject(const GameObject& gameobject) {}
public:
	void SetSize(const Vector2& size);
	void SetPosition(const Vector2& position);
	void SetPivot(const Pivot::Enum& pivot);
	void SetName(const string& name) { mName = name; }
	void SetIsActive(const bool& IsActive) { mIsActive = IsActive; }
	void SetType(const ObjectType& Type) { mType = Type; }

	const string& GetName()const { return mName; }
	const Vector2& GetSize() const { return mSize; }
	const Vector2& GetPosition() const { return mPosition; }
	const bool& GetIsActive() const { return mIsActive; }
	const Pivot::Enum& GetPivot() const { return mPivot; }
	const Figure::FloatRect& GetRect() const { return mRect; }
	const ObjectType& GetType() { return mType; }

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

	GameObject();
	virtual ~GameObject();
};

