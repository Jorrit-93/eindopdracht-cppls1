#pragma once

class IController
{
public:
	virtual ~IController() = default;

	virtual void enter() = 0;
	virtual void exit() = 0;
};