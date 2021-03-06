#pragma once
#include "Command.h"
#include <iostream>

class JumpCommand :
	public Command
{
public:
	JumpCommand() = default;
	virtual ~JumpCommand() override = default;
	virtual void execute(GameObject* gameObject) override;
private:

};

