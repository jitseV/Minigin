#pragma once
#include "Command.h"
#include <iostream>

class FireCommand :
	public Command
{
public:
	FireCommand() = default;
	virtual ~FireCommand() override = default;
	virtual void execute(GameObject* gameObject) override;
private:

};

