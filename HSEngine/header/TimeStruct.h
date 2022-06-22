#pragma once
#include <iostream>
#include <windows.h>

//추상화
//불필요한 정보는 숨기고 중요한 정보만 표현해서 공통 속성이나 기능을 묶어 이름을 붙이는 것

//캡슐화
//특성의 모음을 클래스라는 캡슐에 분류해서 코드를 재수정 없이 재활용 하려는 것

//상속성
//부모클래스의 속성과 기능을 그대로 이어받아 사용할 수 있게 하고 기능의 일부분을 변경도 가능 한 것

//다형성
//하나의 변수명, 함수명 등이 상황에 따라 다른 의미로 해석 될 수 있는 것 
 
//시간계산을 위한 변수집합 구조체
struct TimeStruct {
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	LARGE_INTEGER myFrequency;
	double elapsedTime;
} typedef TimeStruct;
