#pragma once
/****************************************************************************
## Singletonbase ##
@@ Author : �Ǽ��� , Date : 2019.03.20

dynamicSingleton�� �ƴϹǷ� ���� ���� �� ���� ���־�� ��. 
./System/Window/Window.h�� private CreateManager���� �������
*****************************************************************************/
template <typename T>
class Singletonbase
{
protected:
	static T* mInstance;

	Singletonbase() {};
	virtual ~Singletonbase() {};
public:
	static T* Get(void);
	static void Create(void);
	static void Delete(void);
};

template <typename T>
T* Singletonbase<T>::mInstance = nullptr;

template <typename T>
T* Singletonbase<T>::Get(void)
{
	return Singletonbase<T>::mInstance;
}

template<typename T>
inline void Singletonbase<T>::Create(void)
{
	if (Singletonbase<T>::mInstance == nullptr)
	{
		Singletonbase<T>::mInstance = new T;
	}
}

template<typename T>
inline void Singletonbase<T>::Delete(void)
{
	if (Singletonbase<T>::mInstance)
	{
		delete Singletonbase<T>::mInstance;
		Singletonbase<T>::mInstance = nullptr;
	}
}



