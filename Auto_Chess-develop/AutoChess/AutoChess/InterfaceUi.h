#pragma once
/****************************************************************************
## D2DRenderer ##
@@ Author : ������ , Date : 2019.03.22
*****************************************************************************/
using namespace Figure;


// Ʈ���� �ڷ���
typedef struct Trigger
{
	Condition condition;
	Action action;
	// �Լ� �����ڸ� ���� ��� ����
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
	vector<InterfaceUi>mChild; // �ʿ��ϴٸ� ���
public:
	InterfaceUi() = default;
	virtual ~InterfaceUi() = default;

	//------------------------------------------------------
	// ���� �� ���� ������ ����
	// ���� �ϳ� �ϳ� �����ؼ� ���
	InterfaceUi(const InterfaceUi&) = delete;
	const InterfaceUi& operator=(const InterfaceUi&) = delete;
	
	//------------------------------------------------------
	// ���ο� �������� �������Ͽ� ����� �� �ֵ��� ����.
	
	/** ���ο� �������� �����Ͽ� ��� */
	virtual void DefineNewCondition(Condition condition) { mTrigger.condition = condition; }
	/** ���ο� �������� �����Ͽ� ��� */
	virtual void DefineNewAction(Action action) { mTrigger.action = action; }

};

