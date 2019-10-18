#ifndef RUBIK_HPP
#define RUBIK_HPP

#include "Lexer.hpp"
#include "Cube.hpp"
#include "Solver.hpp"

class Rubik
{
private:
	Solver solver;
	Cube cube;
	std::string input;
	Lexer lexer;
	std::vector<std::string> tokens;
public:
	Rubik(char* str);
	~Rubik();

	bool validTokens(void);
	void execute(std::vector<std::string> instructions);
	void solve(void);

	std::vector<std::string> getTokens();
};

#endif
