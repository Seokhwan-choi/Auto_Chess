#pragma once
/****************************************************************************
## D2DRenderer ##
@@ Author : 유동현 , Date : 2019.03.22
*****************************************************************************/
using namespace Figure;


// 트리거 자료형
typedef struct Trigger
{
	Condition condition;
	Action action;
	// 함수 연산자를 통해 사용 가능
	bool operator()()
	{
		if (condition)
		{
			action;
			return true;
		}
		return false;
	}
};

class InterfaceUi
{
private:
	Figure::FloatRect window;
	Trigger mTrigger;
	InterfaceUi* mParent;
	vector<InterfaceUi>mChild; // 필요하다면 사용
public:
	InterfaceUi() = default;
	virtual ~InterfaceUi() = default;

	//------------------------------------------------------
	// 복사 및 대입 연산자 차단
	// 오직 하나 하나 정의해서 사용
	InterfaceUi(const InterfaceUi&) = delete;
	const InterfaceUi& operator=(const InterfaceUi&) = delete;
	
	//------------------------------------------------------
	// 새로운 조건형을 재정의하여 사용할 수 있도록 제공.
	
	/** 새로운 조건형을 정의하여 사용 */
	virtual void DefineNewCondition(Condition condition) { mTrigger.condition = condition; }
	/** 새로운 실행형을 정의하여 사용 */
	virtual void DefineNewAction(Action action) { mTrigger.action = action; }

};

