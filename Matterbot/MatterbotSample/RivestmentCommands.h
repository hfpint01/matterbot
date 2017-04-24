#pragma once
#include "Matterbot.h"
#include "RivestmentGetChallenges.h"

namespace lospi
{
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
			

			if (command_text == L"register izzy")
			{
				return L"rivestment register izzy";
			}
			else if (command_text == L"challenge")
			{
				return L"rivestment challenge";
			}
			else if (command_text == L"scraps")
			{
				return L"rivestment scraps";
			}
			else if (command_text == L"password")
			{
				return L"rivestment password";
			}
			else if (command_text == L"quit")
			{
				return L"rivestment quit";
			}
			else if (command_text == L"trying")
			{
				for (int i = 0; i < challenges.size(); i++)
				{
					auto challengString = challenges[i];
					auto result = theMap[get_md5_from_str(string_to_wstring(challengString))];
					std::wstring solution(result.begin(), result.end());
					return L"rivestment try " + solution;
				}
			}
			else if (command_text == L"rivestment try")
			{
				return L"rivestment try [variable]";
			}
			else
			{
				return L"command not found.";
			}
		}
	};
}