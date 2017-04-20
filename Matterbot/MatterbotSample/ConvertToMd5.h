#pragma once
#include "Matterbot.h"
#include "Md5Utilities.h"
#include "Md5.h"

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
			
			std::string inputString = wstring_to_string(command_text);
			auto hash = compute_md5(inputString.c_str(), inputString.size());
			auto stringOfHash = get_str_from_md5(hash);

			return stringOfHash;
		}
	};
}