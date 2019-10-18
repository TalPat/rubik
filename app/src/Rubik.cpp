#include "Rubik.hpp"

Rubik::Rubik(char *str)
{
	input = str;
	tokens = lexer.lex(input);
}

Rubik::~Rubik()
{
}

bool Rubik::validTokens(void)
{
	// must be 1 or 2 in length
	// first char must be either "FRLBUD"
	// second characer must be either "'2"
	std::string target1 = "FRBLUD";
	std::string target2 = "'2";
	for (std::string str : tokens)
	{
		if (str.length() == 0 ||
				str.length() > 2 ||
				target1.find(str[0]) == std::string::npos)
		{
			throw "";
		}
		if (str.length() == 2 &&
				target2.find(str[1]) == std::string::npos)
		{
			throw "";
		}
	}
}

void Rubik::execute(std::vector<std::string> instructions)
{
	CubeSurface surface;
	Rotations rotation;
	for (std::string str : instructions)
	{
		switch (str[0])
		{
		case 'F':
			surface = front;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;
		case 'R':
			surface = right;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;
		case 'B':
			surface = back;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;
		case 'L':
			surface = left;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;
		case 'U':
			surface = up;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;
		case 'D':
			surface = down;
			if (str.length() == 1)
			{
				rotation = clockwise;
			}
			else
			{
				if (str[1] == '2')
					rotation = twice;
				else
					rotation = anticlock;
			}
			break;

		default:
			throw "";
			break;
		}
		if (cube.isSolved(cube.getCubeState()))
		{
			std::cout << "Complete" << std::endl;
		}
		else
		{
			std::cout << "incomplete" << std::endl;
		}

		cube.rotate(surface, rotation);
	}
	cube.printCube();
}

void Rubik::solve(void)
{
	std::vector<std::string> solutionString;
	// solver.solve(0, cube.getCubeState(), solutionString);
	solver.solveWhiteCross(0, cube.getCubeState(), solutionString);
	solver.solveWhiteCorners(0, cube.getCubeState(), solutionString);
	solver.solveCorners(0, cube.getCubeState(), solutionString);
	solver.printSolution();
}

std::vector<std::string> Rubik::getTokens(void)
{
	return (tokens);
}
