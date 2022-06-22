#pragma once

//렌더링 주체에 대한 인터페이스
class RenderingMachine
{
public:
	virtual void InitRenderer() = 0;
	virtual void ReadyRenderer() = 0;
	virtual void FinishRenderer() = 0;
};