#pragma once

class IGameObject
{
public:
	const class GameObject*const iGameObject;
public:
	IGameObject() = delete;
	const IGameObject& operator=(const IGameObject& i) = delete;
public:
	explicit IGameObject(const class GameObject* const pObject);
	virtual ~IGameObject() {}
};

class IUpdate : public IGameObject
{
public:
	IUpdate() = delete;
	const IUpdate& operator = (const IUpdate& i) = delete;
public:
	explicit IUpdate(const class GameObject*const pObject);
	virtual ~IUpdate();

	virtual void Update() = 0;
protected:
	void RemoveUpdate();
};

class IRender : public IGameObject
{
public:
	IRender() = delete;
	const IRender& operator = (const IRender& i) = delete; 
public:
	explicit IRender(const class GameObject*const pObject);
	virtual ~IRender();

	virtual void Render() = 0;
protected:
	void RemoveRender();
};