#include <iostream>
#include <stdlib.h>

#include "repl.hpp"

int
main(int ac, char *av[])
{
	if (ac == 1) {
		run();

	} else if (
			std::string(av[1]) == "-v" ||
			std::string(av[1]) == "--version") {
		std::cout << SH_NAME << " (Classy & Alacritious Shell) version: "
			<< VERSION << "\n\n🄯 uint 2025 <https://github.com/uint23/>\nwebsite <https://uint23.xyz/>" << NL;

	} else if (
			std::string(av[1]) == "-h" ||
			std::string(av[1]) == "--help") {
		std::cout << "Help yourself :)" << NL;
	}

	return 0;
}
