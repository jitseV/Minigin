#pragma once
#include "Command.h"
#include <iostream>

class FartCommand :
	public Command
{
public:
	FartCommand() = default;
	virtual ~FartCommand() override = default;
	virtual void execute(GameObject* gameObject) override;
private:

};

