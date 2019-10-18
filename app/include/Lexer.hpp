#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <string>
#include <iostream>

class Lexer
{
private:
	/* data */
public:
	Lexer(/* args */);
	~Lexer();

	std::vector<std::string> lex(std::string input);
};

#endif
