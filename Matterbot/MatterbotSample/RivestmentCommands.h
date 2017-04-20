#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct RivestmentCommands : ICommand {
		std::wstring registration { 0 };
		std::wstring get_name() override {
			return L"rivestment";
		}

		std::wstring get_help() override {
			return L"`rivestment register [name]`: This will register you as the user name you provide.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			registration = command_text;
			if (command_text == L"register izzy")
			{
				return L"rivestment register izzy";
			}
			else if (command_text == L"challenge")
			{
				return L"rivestment challenge";
			}
			else if (command_text == L"quit")
			{
				return L"rivestment quit";
			}
			else
			{
				return L"command not found.";
			}
		}
	};
}