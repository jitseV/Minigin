#pragma once
#include "Command.h"
#include <iostream>

class DuckCommand :
	public Command
{
public:
	DuckCommand() = default;
	virtual ~DuckCommand() override = default;
	virtual void execute(GameObject* gameObject) override;
private:
	
};

