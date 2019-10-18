#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <vector>

enum CubeColor
{
	blue,
	red,
	green,
	orange,
	yellow,
	white
};

enum CubeSurface
{
	front,
	right,
	back,
	left,
	up,
	down
};

enum Rotations
{
	clockwise,
	anticlock,
	twice
};

struct CubeFace
{
	std::vector<CubeColor> squares;
};


// Cube format:

// 0 1 2
// 3 Y 4
// 5 6 7
// _____
// 0 1 2 | 0 1 2 | 0 1 2 | 0 1 2
// 3 B 4 | 3 R 4 | 3 G 4 | 3 O 4
// 5 6 7 | 5 6 7 | 5 6 7 | 5 6 7
// -----
// 0 1 2
// 3 W 4
// 5 6 7

// Up 
// Up 
// Up 
// _________
// Front | Right | Back  | Left 
// Front | Right | Back  | Left 
// Front | Right | Back  | Left 
// ---------
// Down 
// Down 
// Down 

class Cube
{
private:
	std::vector<CubeFace> faces;
	std::vector<CubeFace> complete;

	void rotateFace(CubeSurface face);

	void rotateFront(Rotations rotation);
	void rotateRight(Rotations rotation);
	void rotateBack(Rotations rotation);
	void rotateLeft(Rotations rotation);
	void rotateUp(Rotations rotation);
	void rotateDown(Rotations rotation);
public:
	Cube(/* args */);
	Cube(std::vector<CubeFace> cubeState);
	~Cube();

	std::vector<CubeFace> getCubeState(void);
	std::vector<CubeFace> getSolvedState(void);

	void rotate(CubeSurface surface, Rotations rotation);
	bool isSolved(std::vector<CubeFace> cubeState);
	void printCube(void);
};

#endif
