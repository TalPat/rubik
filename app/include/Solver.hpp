#ifndef SOLVER_HPP
#define SOLVER_HPP

#include "Cube.hpp"

class Solver
{
private:
	std::vector<std::string> solution;
	int maxIterations;
public:
	Solver(/* args */);
	~Solver();

	void solve(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);
	void solveCorners(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);

	void solveWhiteCross(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);
	void solveWhiteCorners(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);
	void solveMiddle(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);
	void solveTopCross(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);
	void solveTopCorners(int iteration, std::vector<CubeFace> cubeState, std::vector<std::string> foundSolution);

	std::vector<std::string> getSolution(void);

	void printSolution(void);
};

#endif
