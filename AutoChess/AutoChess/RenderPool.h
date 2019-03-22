#pragma once
class RenderPool
{
	BlockAssign(RenderPool)
public:
	enum class Layer
	{
		Tile,		//Ÿ����
		BackSfx,	//�򸮴� ����Ʈ
		Object,		//�̰Ž� ü���� & �������� ��������
		FrontSfx,	//�����ߴ� ����Ʈ
		UI,			//�̰Ž� UI
		End			//���Ѥ�
	};

private:
	unordered_map<Layer, vector<class GameObject*>> mRenderPool;
	typedef unordered_map<Layer, vector<class GameObject*>>::iterator RenderPoolIter;
private:
	friend class Scene;
	RenderPool() {};					//�������ε� �Ⱦ��Ű��ƿ�
	virtual ~RenderPool() {}
public:
	void Release();
	void Render();					//Ǯ�� �� ������Ʈ�鸸 ���� �����ݴϴ�!
	
	void RequestRender(const Layer& layer, class GameObject*const pObject);
	void RemoveRender(const Layer& layer, class GameObject*const pObject);

private:
	void Zorder();					//�̰Ž� z���� ���̾� ���� ���Ұ��� �������� �����մϴ�!
};

