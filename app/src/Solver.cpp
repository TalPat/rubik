#include "Solver.hpp"

Solver::Solver(/* args */)
{
	maxIterations = 10;
}

Solver::~Solver()
{
}

void Solver::solve(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution)
{
	Cube checkSolvedCube(cubeState);
	if (iteration >= maxIterations)
		return;
	if (checkSolvedCube.isSolved(checkSolvedCube.getCubeState()))
	{
		std::cout << "solved" << std::endl;
		maxIterations = iteration;
		solution = foundSolution;
		return;
	}

	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			Cube activeCube(cubeState);
			std::string move;

			activeCube.rotate(static_cast<CubeSurface>(i), static_cast<Rotations>(j));
			switch (i)
			{
			case 0:
				move = "F";
				break;
			case 1:
				move = "R";
				break;
			case 2:
				move = "B";
				break;
			case 3:
				move = "L";
				break;
			case 4:
				move = "U";
				break;
			case 5:
				move = "D";
				break;

			default:
				break;
			}
			if (j == 1)
				move += "'";
			if (j == 2)
				move += "2";
			foundSolution.push_back(move);
			solve(iteration + 1, activeCube.getCubeState(), foundSolution);
			foundSolution.pop_back();
		}
	}
}

void Solver::solveCorners(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution)
{
	Cube checkSolvedCube(cubeState);
	std::vector<CubeFace> solved = checkSolvedCube.getSolvedState();
	
	if (iteration >= maxIterations)
		return;
	if (cubeState[0].squares[0] == solved[0].squares[0] &&
			cubeState[0].squares[2] == solved[0].squares[2] &&
			cubeState[0].squares[6] == solved[0].squares[6] &&
			cubeState[0].squares[8] == solved[0].squares[8] &&
			cubeState[1].squares[0] == solved[1].squares[0] &&
			cubeState[1].squares[2] == solved[1].squares[2] &&
			cubeState[1].squares[6] == solved[1].squares[6] &&
			cubeState[1].squares[8] == solved[1].squares[8] &&
			cubeState[2].squares[0] == solved[2].squares[0] &&
			cubeState[2].squares[2] == solved[2].squares[2] &&
			cubeState[2].squares[6] == solved[2].squares[6] &&
			cubeState[2].squares[8] == solved[2].squares[8] &&
			cubeState[3].squares[0] == solved[3].squares[0] &&
			cubeState[3].squares[2] == solved[3].squares[2] &&
			cubeState[3].squares[6] == solved[3].squares[6] &&
			cubeState[3].squares[8] == solved[3].squares[8] &&
			cubeState[4].squares[0] == solved[4].squares[0] &&
			cubeState[4].squares[2] == solved[4].squares[2] &&
			cubeState[4].squares[6] == solved[4].squares[6] &&
			cubeState[4].squares[8] == solved[4].squares[8] &&
			cubeState[5].squares[0] == solved[5].squares[0] &&
			cubeState[5].squares[2] == solved[5].squares[2] &&
			cubeState[5].squares[6] == solved[5].squares[6] &&
			cubeState[5].squares[8] == solved[5].squares[8]
	)
	{
		maxIterations = iteration;
		solution = foundSolution;
		return;
	}
	
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			Cube activeCube(cubeState);
			std::string move;

			activeCube.rotate(static_cast<CubeSurface>(i), static_cast<Rotations>(j));
			switch (i)
			{
			case 0:
				move = "F";
				break;
			case 1:
				move = "R";
				break;
			case 2:
				move = "B";
				break;
			case 3:
				move = "L";
				break;
			case 4:
				move = "U";
				break;
			case 5:
				move = "D";
				break;

			default:
				break;
			}
			if (j == 1)
				move += "'";
			if (j == 2)
				move += "2";
			foundSolution.push_back(move);
			solveCorners(iteration + 1, activeCube.getCubeState(), foundSolution);
			foundSolution.pop_back();
		}
	}
}

void Solver::solveWhiteCross(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution)
{
	Cube checkSolvedCube(cubeState);
	std::vector<CubeFace> solved = checkSolvedCube.getSolvedState();
	
	if (iteration >= maxIterations)
		return;
	if (cubeState[0].squares[7] == solved[0].squares[7] &&
			cubeState[1].squares[7] == solved[1].squares[7] &&
			cubeState[2].squares[7] == solved[2].squares[7] &&
			cubeState[3].squares[7] == solved[3].squares[7] &&
			cubeState[5].squares[1] == solved[5].squares[1] &&
			cubeState[5].squares[3] == solved[5].squares[3] &&
			cubeState[5].squares[5] == solved[5].squares[5] &&
			cubeState[5].squares[7] == solved[5].squares[7]
	)
	{
		maxIterations = iteration;
		solution = foundSolution;
		return;
	}
	
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			Cube activeCube(cubeState);
			std::string move;

			activeCube.rotate(static_cast<CubeSurface>(i), static_cast<Rotations>(j));
			switch (i)
			{
			case 0:
				move = "F";
				break;
			case 1:
				move = "R";
				break;
			case 2:
				move = "B";
				break;
			case 3:
				move = "L";
				break;
			case 4:
				move = "U";
				break;
			case 5:
				move = "D";
				break;

			default:
				break;
			}
			if (j == 1)
				move += "'";
			if (j == 2)
				move += "2";
			foundSolution.push_back(move);
			solveWhiteCross(iteration + 1, activeCube.getCubeState(), foundSolution);
			foundSolution.pop_back();
		}
	}
}

void Solver::solveWhiteCorners(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution)
{
	Cube checkSolvedCube(cubeState);
	std::vector<CubeFace> solved = checkSolvedCube.getSolvedState();
	
	if (iteration >= maxIterations)
		return;
	if (cubeState[0].squares[7] == solved[0].squares[7] &&
			cubeState[1].squares[7] == solved[1].squares[7] &&
			cubeState[2].squares[7] == solved[2].squares[7] &&
			cubeState[3].squares[7] == solved[3].squares[7] &&
			cubeState[5].squares[1] == solved[5].squares[1] &&
			cubeState[5].squares[3] == solved[5].squares[3] &&
			cubeState[5].squares[5] == solved[5].squares[5] &&
			cubeState[5].squares[7] == solved[5].squares[7] &&

			cubeState[5].squares[0] == solved[5].squares[0] &&
			cubeState[5].squares[2] == solved[5].squares[2] &&
			cubeState[5].squares[6] == solved[5].squares[6] &&
			cubeState[5].squares[8] == solved[5].squares[8] &&

			cubeState[0].squares[6] == solved[0].squares[6] &&
			cubeState[0].squares[8] == solved[0].squares[8] &&
			cubeState[1].squares[6] == solved[1].squares[6] &&
			cubeState[1].squares[8] == solved[1].squares[8] &&
			cubeState[2].squares[6] == solved[2].squares[6] &&
			cubeState[2].squares[8] == solved[2].squares[8] &&
			cubeState[3].squares[6] == solved[3].squares[6] &&
			cubeState[3].squares[8] == solved[3].squares[8]
	)
	{
		maxIterations = iteration;
		solution = foundSolution;
		return;
	}
	
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			Cube activeCube(cubeState);
			std::string move;

			activeCube.rotate(static_cast<CubeSurface>(i), static_cast<Rotations>(j));
			switch (i)
			{
			case 0:
				move = "F";
				break;
			case 1:
				move = "R";
				break;
			case 2:
				move = "B";
				break;
			case 3:
				move = "L";
				break;
			case 4:
				move = "U";
				break;
			case 5:
				move = "D";
				break;

			default:
				break;
			}
			if (j == 1)
				move += "'";
			if (j == 2)
				move += "2";
			foundSolution.push_back(move);
			solveWhiteCorners(iteration + 1, activeCube.getCubeState(), foundSolution);
			foundSolution.pop_back();
		}
	}
}

void Solver::printSolution(void)
{
	for (auto move : solution)
	{
		std::cout << move << std::endl;
	}
}
