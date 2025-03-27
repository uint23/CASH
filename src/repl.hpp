#pragma once

#include <iostream>
#include <vector>

#include "readline/readline.h"
#include "readline/history.h"

#define NL		"\n"
#define VERSION "0.1.0"
#define SH_NAME "CA$H"

std::vector<char*> parse_args(char *cmd);
void run();

