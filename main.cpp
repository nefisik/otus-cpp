#include "lib.h"

#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "build 0.0."
              << version_patch() << std::endl
			  << "Hello, World!" << std::endl;

	return 0;
}
