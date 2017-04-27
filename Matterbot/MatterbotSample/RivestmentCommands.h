#pragma once
#include "Matterbot.h"
#include "RivestmentGetChallenges.h"
#include <vector>

namespace lospi
{
	int level = 0;
	struct RivestmentCommands : ICommand {
		

		std::wstring registration { 0 };
		std::wstring get_name() override {
			return L"rivestment";
		}

		std::wstring get_help() override {
			return L"`rivestment commands`";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			registration = command_text;
			
			
			
			if (command_text == L"register")
			{
				return L"rivestment register izzy";
			}
			else if (command_text == L"challenge")
			{
				return L"rivestment challenge";
			}
			else if (command_text == L"password")
			{
				return L"rivestment password";
			}
			else if (command_text == L"scraps")
			{
				return L"rivestment scraps 250";
			}
			//////////////////////////////////
			else if (command_text == L"level 1")
			{
				return L"rivestment level 1";
			}
			else if (command_text == L"level 2")
			{
				return L"rivestment level 2";
			}
			else if (command_text == L"level 3")
			{
				return L"rivestment level 3";
			}
			else if (command_text == L"level 4")
			{
				return L"rivestment level 4";
			}
			else if (command_text == L"level 5")
			{
				return L"I'm sorry. You've exceeded Izzy's laptop capabilities.";
			}
			////////////////////////////////
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