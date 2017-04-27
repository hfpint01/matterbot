#include "Matterbot.h"
#include <iostream>
#include <sstream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "ReverseCommand.h"
#include "WeatherCommand.h"
#include "JokesCommand.h"
#include "RivestmentCommands.h"
#include "RivestmentGetChallenges.h"
#include "RivestmentScraps.h"
#include "Md5.h"
#include "Md5Utilities.h"
#include "ConvertToMd5.h"

#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() 
{
  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"services/T4Z1QAKSS/B50N1HNQ7/w1d44getQsNq2zrlRPzD8Adp",
    outgoing_hook_route = L"http://127.0.0.1:2020/",
    outgoing_hook_token = L"XoLaKLa4THaZgv1nJNwMw33j",
    welcome_message = L"bot is running.";

  try {
    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
	bot->register_command(make_shared<JokesCommand>());
    bot->register_command(make_shared<RivestmentCommands>());
	bot->register_command(make_shared<RivestmentGetChallanges>(bot));
	auto challenges_ptr = make_shared<RivestmentGetChallanges>(bot);
	bot->register_command(challenges_ptr);
	bot->register_command(make_shared<RivestmentScraps>(bot, challenges_ptr));
	//bot->register_command(make_shared<ConvertToMd5>());
	//bot->register_command(make_shared<ReverseCommand>(bot));
	bot->register_command(make_shared<EchoCommand>());
	//bot->register_command(make_shared<WeatherCommand>());


    bot->post_message(welcome_message);

	std::map<Md5Digest, std::vector<char>> create_table();

	std::string alpha = "josh";
	std::string myPwd = "3x0zyc";
	std::string password{ 0 };
	
	for (int i = 0; i < 14; i++)
	{
		Combinator c(alpha, (i));
		while (c.has_next())
		{
			auto combo = c.next();
			copy(myPwd.begin(), myPwd.end(), back_inserter(combo));
			auto Md5 = compute_md5(combo.data(), combo.size());
			lospi::theMap.emplace(Md5,combo);
		}
	}
	bot->post_message(L"Table Complete");
	
    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { bot->post_message(console); }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }


}
