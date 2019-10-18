#include "Cube.hpp"

Cube::Cube(/* args */)
{
	for (unsigned int i = 0; i < 6; i++)
	{
		CubeFace face;
		for (unsigned int j = 0; j < 9; j++)
		{
			face.squares.push_back(static_cast<CubeColor>(i));
		}
		faces.push_back(face);
		complete.push_back(face);
	}
}

Cube::Cube(std::vector<CubeFace> cubeState)
{
	for (unsigned int i = 0; i < 6; i++)
	{
		CubeFace face;
		for (unsigned int j = 0; j < 9; j++)
		{
			face.squares.push_back(static_cast<CubeColor>(i));
		}
		complete.push_back(face);
	}
	faces = cubeState;
}

Cube::~Cube()
{
}

void Cube::printCube(void)
{
	for (size_t j = 0; j < 6; j++)
	{
		for (size_t i = 0; i < 9; i++)
		{
			if (i % 3 == 0)
				std::cout << "\n";
			switch (faces[j].squares[i])
			{
			case blue:
				std::cout << "B ";
				break;
			case red:
				std::cout << "R ";
				break;
			case green:
				std::cout << "G ";
				break;
			case orange:
				std::cout << "O ";
				break;
			case yellow:
				std::cout << "Y ";
				break;
			case white:
				std::cout << "W ";
				break;
			}
		}

		std::cout << std::endl;
	}
}

void Cube::rotate(CubeSurface surface, Rotations rotation)
{
	switch (surface)
	{
	case front:
		rotateFront(rotation);
		break;
	case right:
		rotateRight(rotation);
		break;
	case back:
		rotateBack(rotation);
		break;
	case left:
		rotateLeft(rotation);
		break;
	case up:
		rotateUp(rotation);
		break;
	case down:
		rotateDown(rotation);
		break;

	default:
		break;
	}
}

void Cube::rotateFace(CubeSurface face)
{
	std::vector<CubeFace> buffer = faces;
	std::vector<int> rotMatrix{
			6, 2, -2,
			4, 0, -4,
			2, -2, -6};
	for (size_t i = 0; i < 9; i++)
	{
		faces[face].squares[i] = buffer[face].squares[i + rotMatrix[i]];
	}
}

void Cube::rotateFront(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(front);

	faces[up].squares[6] = buffer[left].squares[8];
	faces[up].squares[7] = buffer[left].squares[5];
	faces[up].squares[8] = buffer[left].squares[2];

	faces[right].squares[0] = buffer[up].squares[6];
	faces[right].squares[3] = buffer[up].squares[7];
	faces[right].squares[6] = buffer[up].squares[8];

	faces[down].squares[0] = buffer[right].squares[6];
	faces[down].squares[1] = buffer[right].squares[3];
	faces[down].squares[2] = buffer[right].squares[0];

	faces[left].squares[2] = buffer[down].squares[0];
	faces[left].squares[5] = buffer[down].squares[1];
	faces[left].squares[8] = buffer[down].squares[2];

	if (rotation == anticlock)
		rotateFront(twice);
	else if (rotation == twice)
		rotateFront(clockwise);
}

void Cube::rotateRight(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(right);

	faces[back].squares[0] = buffer[up].squares[8];
	faces[back].squares[3] = buffer[up].squares[5];
	faces[back].squares[6] = buffer[up].squares[2];

	faces[down].squares[2] = buffer[back].squares[6];
	faces[down].squares[5] = buffer[back].squares[3];
	faces[down].squares[8] = buffer[back].squares[0];

	faces[front].squares[2] = buffer[down].squares[2];
	faces[front].squares[5] = buffer[down].squares[5];
	faces[front].squares[8] = buffer[down].squares[8];

	faces[up].squares[2] = buffer[front].squares[2];
	faces[up].squares[5] = buffer[front].squares[5];
	faces[up].squares[8] = buffer[front].squares[8];

	if (rotation == anticlock)
		rotateRight(twice);
	else if (rotation == twice)
		rotateRight(clockwise);
}

void Cube::rotateBack(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(back);

	faces[up].squares[0] = buffer[right].squares[2];
	faces[up].squares[1] = buffer[right].squares[5];
	faces[up].squares[2] = buffer[right].squares[8];

	faces[left].squares[0] = buffer[up].squares[2];
	faces[left].squares[3] = buffer[up].squares[1];
	faces[left].squares[6] = buffer[up].squares[0];

	faces[down].squares[6] = buffer[left].squares[0];
	faces[down].squares[7] = buffer[left].squares[3];
	faces[down].squares[8] = buffer[left].squares[6];

	faces[right].squares[2] = buffer[down].squares[8];
	faces[right].squares[5] = buffer[down].squares[7];
	faces[right].squares[8] = buffer[down].squares[6];

	if (rotation == anticlock)
		rotateBack(twice);
	else if (rotation == twice)
		rotateBack(clockwise);
}

void Cube::rotateLeft(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(left);

	faces[up].squares[0] = buffer[back].squares[8];
	faces[up].squares[3] = buffer[back].squares[5];
	faces[up].squares[6] = buffer[back].squares[2];

	faces[back].squares[2] = buffer[down].squares[6];
	faces[back].squares[5] = buffer[down].squares[3];
	faces[back].squares[8] = buffer[down].squares[0];

	faces[down].squares[6] = buffer[front].squares[6];
	faces[down].squares[3] = buffer[front].squares[3];
	faces[down].squares[0] = buffer[front].squares[0];

	faces[front].squares[0] = buffer[up].squares[0];
	faces[front].squares[3] = buffer[up].squares[3];
	faces[front].squares[6] = buffer[up].squares[6];

	if (rotation == anticlock)
		rotateLeft(twice);
	else if (rotation == twice)
		rotateLeft(clockwise);
}

void Cube::rotateUp(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(up);

	faces[right].squares[0] = buffer[back].squares[0];
	faces[right].squares[1] = buffer[back].squares[1];
	faces[right].squares[2] = buffer[back].squares[2];

	faces[back].squares[0] = buffer[left].squares[0];
	faces[back].squares[1] = buffer[left].squares[1];
	faces[back].squares[2] = buffer[left].squares[2];

	faces[left].squares[0] = buffer[front].squares[0];
	faces[left].squares[1] = buffer[front].squares[1];
	faces[left].squares[2] = buffer[front].squares[2];

	faces[front].squares[0] = buffer[right].squares[0];
	faces[front].squares[1] = buffer[right].squares[1];
	faces[front].squares[2] = buffer[right].squares[2];

	if (rotation == anticlock)
		rotateUp(twice);
	else if (rotation == twice)
		rotateUp(clockwise);
}

void Cube::rotateDown(Rotations rotation)
{
	std::vector<CubeFace> buffer = faces;
	rotateFace(down);

	faces[left].squares[6] = buffer[back].squares[6];
	faces[left].squares[7] = buffer[back].squares[7];
	faces[left].squares[8] = buffer[back].squares[8];

	faces[back].squares[6] = buffer[right].squares[6];
	faces[back].squares[7] = buffer[right].squares[7];
	faces[back].squares[8] = buffer[right].squares[8];

	faces[right].squares[6] = buffer[front].squares[6];
	faces[right].squares[7] = buffer[front].squares[7];
	faces[right].squares[8] = buffer[front].squares[8];

	faces[front].squares[6] = buffer[left].squares[6];
	faces[front].squares[7] = buffer[left].squares[7];
	faces[front].squares[8] = buffer[left].squares[8];

	if (rotation == anticlock)
		rotateDown(twice);
	else if (rotation == twice)
		rotateDown(clockwise);
}

bool Cube::isSolved(std::vector<CubeFace> cubeState)
{
	for (size_t i = 0; i < 6; i++)
	{
		for (size_t j = 0; j < 9; j++)
		{
			if (cubeState[i].squares[j] != complete[i].squares[j])
			return (false);
		}
	}
	return (true);
}

std::vector<CubeFace> Cube::getCubeState(void)
{
	return (faces);
}

std::vector<CubeFace> Cube::getSolvedState(void)
{
	return (complete);
}
