#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct JokesCommand : ICommand {
		std::wstring get_name() override {
			return L"joke";
		}

		std::wstring get_help() override {
			return L"`joke [#]`: `Enter a number 1-10 and it will print a joke. ";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {
			
			
			if (command_text == L"1")
				return L"C://dos\nC://dos.run\nrun.dos.run";
			else if (command_text == L"2")
				return L"Bugs come in through open Windows.";
			else if (command_text == L"3")
				return L"Mac users swear by their Mac. PC users swear at their PC.";
			else if (command_text == L"4")
				return L"Computers are like air conditioners: they stop working when you open Windows.";
			else if (command_text == L"5")
				return L"Failure is not an option. It comes bundled with your Microsoft product.";
			else if (command_text == L"6")
				return L"If at first you don’t succeed; call it version 1.0.";
			else if (command_text == L"7")
				return L"My software never has bugs. It just develops random features.";
			else if (command_text == L"8")
				return L"Programming today is a race between software engineers striving to build bigger and better idiot-proof programs,\nand the Universe trying to produce bigger and better idiots. So far, the Universe is winning.";
			else if (command_text == L"9")
				return L"The more I C, the less I see.";
			else if (command_text==L"10")
				return L"If brute force doesn’t solve your problems, then you aren’t using enough.";
			else return L"Try again";
		}	
	};


	
}