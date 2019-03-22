#pragma once
class RenderPool
{
	BlockAssign(RenderPool)
public:
	enum class Layer
	{
		Tile,		//타일임
		BackSfx,	//깔리는 이팩트
		Object,		//이거슨 체스말 & 나무같은 지형지물
		FrontSfx,	//위에뜨는 이팩트
		UI,			//이거슨 UI
		End			//끄ㅡㅌ
	};

private:
	unordered_map<Layer, vector<class GameObject*>> mRenderPool;
	typedef unordered_map<Layer, vector<class GameObject*>>::iterator RenderPoolIter;
private:
	friend class Scene;
	RenderPool() {};					//생성자인데 안쓸거같아요
	virtual ~RenderPool() {}
public:
	void Release();
	void Render();					//풀에 들어간 오브젝트들만 랜더 돌려줍니다!
	
	void RequestRender(const Layer& layer, class GameObject*const pObject);
	void RemoveRender(const Layer& layer, class GameObject*const pObject);

private:
	void Zorder();					//이거슨 z오더 레이어 별로 바텀값을 바탕으로 정렬합니다!
};

