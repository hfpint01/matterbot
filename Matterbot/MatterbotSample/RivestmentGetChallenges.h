#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <vector>
#include <map>

namespace lospi
{
	std::map < Md5Digest, std::vector<char>> theMap;
	std::vector<std::string> challenges;
	
	struct RivestmentGetChallanges : ICommand {
		explicit RivestmentGetChallanges(std::shared_ptr<Matterbot> bot) : bot{ bot } {}
	
		std::wstring solString;
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges`: This captures MD5's and stores them in an array.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			//split text into challenge list
			while (command_text.size())
			{
				std::stringstream ss;
				std::string text = wstring_to_string(command_text);
				ss.str(text);
				std::string item;
				challenges.clear();

				while (std::getline(ss, item, ' '))
				{
					challenges.push_back(item);
				}

				_sleep(1000);

				tryHashes();
				
				bot->post_message(L"rivestment try " + (solString));
				
				_sleep(1000);
				bot->post_message(L"rivestment challenge 200");
				return L"";
			}
			
		}

		void tryHashes() {
	
			std::vector<std::wstring> solutionArray;
			solutionArray.clear();
			std::wstring solution;
			
			//bot->post_message(L"izzy rivestment challenge");

			for (int i = 0; i < challenges.size(); i++)
			{
				auto challengString = challenges[i];
				auto result = theMap[get_md5_from_str(string_to_wstring(challengString))];
				std::wstring solution(result.begin(), result.end());
				solutionArray.emplace_back(solution);
			}
			solString.clear();
			for (int i = 0; i < solutionArray.size(); i++)
			{

				solString += solutionArray[i] + L" ";
			}
			solString.pop_back();
		}

	private:
		std::shared_ptr<Matterbot> bot;
	};
}