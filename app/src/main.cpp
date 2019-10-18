#include <iostream>
#include "Rubik.hpp"

int main(int argv, char **args)
{
	if (argv > 1)
	{
		Rubik rubik(args[1]);
		rubik.validTokens();
		rubik.execute(rubik.getTokens());
		rubik.solve();
	} else
	{
		std::cout << "invalid input" << std::endl;
	}
	
	return (0);
}