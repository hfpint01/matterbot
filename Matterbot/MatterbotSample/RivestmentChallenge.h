#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct RivestmentChallenge : ICommand {
		std::wstring get_name() override {
			return L"rivestment challenge";
		}

		std::wstring get_help() override {
			return L"`rivestment challenge`: This will echo a challenge command to get the list of MD5 hashes.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			return command_text;
		}
	};
}