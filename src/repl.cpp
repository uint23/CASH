#include "repl.hpp"
#include <cstring>
#include <string>
#include <vector>

std::vector<char*>
parse_args(char *cmd)
{
	std::vector<char*> args;
	char *token = std::strtok(cmd, " \t\n");

	while (token != nullptr) {
		args.push_back(token);
		token = std::strtok(nullptr, " \t\n");
	}

	args.push_back(nullptr); // execvp expects a null-terminated array
	return args;}

void
run()
{
	std::string s_ps1 = SH_NAME;
	s_ps1 = "<" + s_ps1 + ">" + "$ ";

	const char *ps1 = s_ps1.c_str();
	char *cmd;

	for (;;) {
		cmd = readline(ps1);

		if (!cmd)
			break;

		if (std::strlen(cmd) == 0) {
			free(cmd);
			continue;
		}

		std::vector<char*> parsed_args = parse_args(cmd);

		for (char *arg : parsed_args)
			std::cout << arg << NL;

		free(cmd);
	}
}
