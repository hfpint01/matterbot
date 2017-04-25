#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include "RivestmentGetChallenges.h"
#include <vector>
#include <map>



namespace lospi

{

	
	struct ScrapsCommand : ICommand {
		explicit ScrapsCommand(std::shared_ptr<RivestmentGetChallanges> challenges)
		{
			this->challenges = challenges;
		};

		std::wstring get_name() override { return L"scraps"; }


		std::wstring get_help() override { return L"`scraps`: `scraps` loads the hashes and begins crunching."; }

		std::wstring handle_command(const std::wstring& team, const std::wstring& channel,
			const std::wstring& user, const std::wstring& command_text) override {

			return challenges->handle_command(team, channel, user, command_text);

		};
	private:		
		std::shared_ptr<RivestmentGetChallanges> challenges;

	};

}