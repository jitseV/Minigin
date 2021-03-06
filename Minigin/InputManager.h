#pragma once
#include <XInput.h>
#include "Singleton.h"
#include "Command.h"
#include <map>

namespace dae
{
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		void SetCommandToButton(ControllerButton button, Command* pCommand);
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
	private:
		XINPUT_STATE m_CurrentState{};

		std::map<ControllerButton, Command*> m_pCommands;
	};

}
