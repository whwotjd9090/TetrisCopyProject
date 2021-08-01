#pragma once
#ifndef TETROMINO_HPP_INCLUDED
#define TETROMINO_HPP_INCLUDED
#include "TetrisConstant.hpp"
#include "WindowConsoleControl.hpp"
#include <iostream>
#include <utility>

class Tetromino
{
private:
	std::pair<int, int> position;
	BLOCKSHAPE shape;
	ROTATE rotation;
	WINDOW_CONSOLE_COLOR color;

	/* Real move method */
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();
	/**/

public:
	/* Constructor */
	Tetromino(const BLOCKSHAPE _shape);
	Tetromino(const BLOCKSHAPE _shape, const ROTATE _rotation);
	Tetromino(const std::pair<int, int> _position, const BLOCKSHAPE _shape);
	Tetromino(const std::pair<int, int> _position, const BLOCKSHAPE _shape, const ROTATE _rotation);
	/**/

	/* Property position */
	std::pair<int, int> GetPosition() const;
	void SetPosition(const std::pair<int, int> _position);
	void Move(const MOVE _direction);
	/**/

	/* Property shape */
	BLOCKSHAPE GetShape() const;
	void SetShape(const BLOCKSHAPE _shape);
	/**/

	/* Property rotation */
	ROTATE GetRotation() const;
	void SetRotation(const ROTATE _rotation);
	void RotationClockwise();
	void RotationCounterclockwise();
	/**/

	/* Property color */
	WINDOW_CONSOLE_COLOR GetColor() const;
	void SetColor(const WINDOW_CONSOLE_COLOR _color);
	/**/
	
	/* Abstract method */
	virtual void Draw() = 0;
	virtual void UnDraw() = 0;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) = 0;
	/**/
};

// брбсбрбр
class TetrominoI : public Tetromino
{
public:
	TetrominoI();
	TetrominoI(const std::pair<int, int> _position);
	TetrominoI(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

// брбр
// бсбр
class TetrominoO : public Tetromino
{
public:
	TetrominoO();
	TetrominoO(const std::pair<int, int> _position);
	TetrominoO(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

//  бр
// брбсбр
class TetrominoT : public Tetromino
{
public:
	TetrominoT();
	TetrominoT(const std::pair<int, int> _position);
	TetrominoT(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

//  брбр
// брбс
class TetrominoS : public Tetromino
{
public:
	TetrominoS();
	TetrominoS(const std::pair<int, int> _position);
	TetrominoS(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

// брбр
//  бсбр
class TetrominoZ : public Tetromino
{
public:
	TetrominoZ();
	TetrominoZ(const std::pair<int, int> _position);
	TetrominoZ(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

// бр
// брбсбр
class TetrominoJ : public Tetromino
{
public:
	TetrominoJ();
	TetrominoJ(const std::pair<int, int> _position);
	TetrominoJ(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

//   бр
// брбсбр
class TetrominoL : public Tetromino
{
public:
	TetrominoL();
	TetrominoL(const std::pair<int, int> _position);
	TetrominoL(const std::pair<int, int> _position, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

class TetrominoGhost : public Tetromino
{
public:
	TetrominoGhost(const BLOCKSHAPE _shape);
	TetrominoGhost(const BLOCKSHAPE _shape, const ROTATE _rotation);
	TetrominoGhost(const std::pair<int, int> _position, const BLOCKSHAPE _shape);
	TetrominoGhost(const std::pair<int, int> _position, const BLOCKSHAPE _shape, const ROTATE _rotation);

	virtual void Draw() override;
	virtual void UnDraw() override;
	virtual void Rotate(const ROTATE isClockwise, const std::array<bool, 5> result) override;
};

#endif