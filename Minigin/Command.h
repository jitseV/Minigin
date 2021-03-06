#pragma once
#include "GameObject.h"

using namespace dae;
class Command
{
public:
	Command() = default;
	virtual ~Command() = default;
	virtual void execute(GameObject* gameObject) = 0;
private:

};
