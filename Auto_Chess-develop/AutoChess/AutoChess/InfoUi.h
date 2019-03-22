#pragma once

// 조건문과 실행문
typedef bool(*Condition)();
typedef void(*Action)();

// 상속 인터페이스
#include "InterfaceUi.h"
// UI 구현 객체
#include "Button.h"
#include "Title.h"
// UI 팩토리
#include "FactoryUi.h"
// UI 매니저
#include "UiManager.h"