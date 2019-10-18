#include "Lexer.hpp"

Lexer::Lexer(/* args */)
{
}

Lexer::~Lexer()
{
}

std::vector<std::string> Lexer::lex(std::string input)
{
	std::vector<std::string> tokens;
	std::string targets(" ");
	unsigned int pos = 0;

	while (pos < input.size())
	{
		if (targets.find(input[pos]) != std::string::npos)
		{
			if (pos == 0)
			{
				tokens.push_back(input.substr(0, 1));
				input.erase(0, 1);
			} else
			{
				tokens.push_back(input.substr(0, pos));
				input.erase(0, pos);
				pos = 0;
			}
		} else
		{
			pos++;
		}
	}
	int i = 0;
	while (i < tokens.size())
	{
		if (tokens[i] == " ")
		{
			tokens.erase(tokens.begin() + i);
		} else
		{
			i++;
		}
		
	}
	if (input.size() > 0)
		tokens.push_back(input);
	return (tokens);
}
