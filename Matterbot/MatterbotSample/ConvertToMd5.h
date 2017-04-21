#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Md5.h"
#include <vector>
#include <map>


namespace lospi
{
	struct ConvertToMd5 : ICommand {
		std::wstring get_name() override {
			return L"convert";
		}

		std::wstring get_help() override {
			return L"`convert [MESSAGE]`: `convert` will convert your input to an Md5 hash.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			//std::map<Md5Digest, std::vector<char>> * create_table();
				
			//std::string alpha = "josh";
			//std::string myPwd = "1b9y0s";
			//std::string password{ 0 };
			//std::map < Md5Digest, std::vector<char>> theMap;
			
			//for (int i = 0; i < 11; i++)
			//{
				//Combinator c(alpha, (i));
				//while (c.has_next())
				//{
					//auto combo = c.next();
					//copy(myPwd.begin(), myPwd.end(), back_inserter(password));
					//std::string password(combo.data() + myPwd);
					//theMap.emplace(compute_md5(password.c_str(), password.size()), combo);		
				//}
			//}
			

			//std::string inputString = (wstring_to_string(command_text)+myPwd);
			//auto hash = compute_md5(inputString.c_str(), inputString.size());
			//auto stringOfHash = get_str_from_md5(hash);
	
			return command_text;
		}
	};
}