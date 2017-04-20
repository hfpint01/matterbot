#pragma once
#include "Matterbot.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include <vector>
namespace lospi
{
	struct RivestmentGetChallanges : ICommand {
		
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges`: This captures MD5's and stores them in an array.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			
			std::vector<std::string> challenges;
			
			//split text into challenge list
			std::stringstream ss;
			std::string text = wstring_to_string(command_text);
			ss.str(text);
			std::string item;
			while (std::getline(ss, item, ' '))
			{
				challenges.push_back(item);
			}
			int i{ 0 };

			while (challenges[i] != "\0")
			{
				std::cout << "element in array: " << challenges[i] << "\n";
				i++;
			}
			return L"MD5's captured.";
			
		}
	};
}