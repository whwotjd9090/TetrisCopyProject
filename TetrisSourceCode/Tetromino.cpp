#include "Tetromino.hpp"

/* Real move method */
void Tetromino::MoveUp()
{
	position.second = position.second - 1;
}
void Tetromino::MoveRight()
{
	position.first = position.first + 1;
}
void Tetromino::MoveLeft()
{
	position.first = position.first - 1;
}
void Tetromino::MoveDown()
{
	position.second = position.second + 1;
}
/**/

/* Tetromino Constructor */
Tetromino::Tetromino(const BLOCKSHAPE _shape) : Tetromino({0, 0}, _shape, ROTATE::SPAWN) {}
Tetromino::Tetromino(const BLOCKSHAPE _shape, const ROTATE _rotation) : Tetromino({0, 0}, _shape, _rotation) {}
Tetromino::Tetromino(const std::pair<int, int> _position, const BLOCKSHAPE _shape) : Tetromino(_position, _shape, ROTATE::SPAWN) {}
Tetromino::Tetromino(const std::pair<int, int> _position, const BLOCKSHAPE _shape, const ROTATE _rotation) : position(_position), shape(_shape), rotation(_rotation)
{
	switch(_shape)
	{
	case BLOCKSHAPE::I: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_I); break;
	case BLOCKSHAPE::O: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_O); break;
	case BLOCKSHAPE::T: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_T); break;
	case BLOCKSHAPE::S: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_S); break;
	case BLOCKSHAPE::Z: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_Z); break;
	case BLOCKSHAPE::J: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_J); break;
	case BLOCKSHAPE::L: color = static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_L); break;
	}
}
/**/

/* Property position */
std::pair<int, int> Tetromino::GetPosition() const
{
	return position;
}
void Tetromino::SetPosition(const std::pair<int, int> _position)
{
	position = _position;
}
void Tetromino::Move(const MOVE _direction)
{
	switch(_direction)
	{
		case MOVE::UP: MoveUp(); break;
		case MOVE::RIGHT: MoveRight(); break;
		case MOVE::DOWN: MoveDown(); break;
		case MOVE::LEFT: MoveLeft(); break;
	}
}
/**/

/* Property shape */
BLOCKSHAPE Tetromino::GetShape() const
{
	return shape;
}
void Tetromino::SetShape(const BLOCKSHAPE _shape)
{
	shape = _shape;
}
/**/

/* Property rotation */
ROTATE Tetromino::GetRotation() const
{
	return rotation;
}
void Tetromino::SetRotation(const ROTATE _rotation)
{
	rotation = _rotation;
}
void Tetromino::RotationClockwise()
{
	rotation = static_cast<ROTATE>((static_cast<int>(GetRotation()) + 1) % 4);
}
void Tetromino::RotationCounterclockwise()
{
	rotation = static_cast<ROTATE>((static_cast<int>(GetRotation()) + 3) % 4);
}
/**/

/* Property color */
WINDOW_CONSOLE_COLOR Tetromino::GetColor() const
{
	return color;
}
void Tetromino::SetColor(const WINDOW_CONSOLE_COLOR _color)
{
	color = _color;
}
/**/

/* I block Class */
TetrominoI::TetrominoI() : TetrominoI({0, 0}, ROTATE::SPAWN) {}
TetrominoI::TetrominoI(const std::pair<int, int> _position) : TetrominoI(_position, ROTATE::SPAWN) {}
TetrominoI::TetrominoI(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::I, _rotation) {}

void TetrominoI::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 4, draw_position.second); std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 2); std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 4, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 2); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "бс";
		break;
	}
}
void TetrominoI::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 4, draw_position.second); std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 2); std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 4, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 2); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "  ";
		break;
	}
}
void TetrominoI::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			Move(MOVE::UP);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			Move(MOVE::LEFT);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			Move(MOVE::RIGHT);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			Move(MOVE::UP);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			Move(MOVE::DOWN);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			Move(MOVE::RIGHT);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			Move(MOVE::LEFT);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			Move(MOVE::DOWN);

			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_I_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_I_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* O block Class */
TetrominoO::TetrominoO() : TetrominoO({0, 0}, ROTATE::SPAWN) {}
TetrominoO::TetrominoO(const std::pair<int, int> _position) : TetrominoO(_position, ROTATE::SPAWN) {}
TetrominoO::TetrominoO(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::O, _rotation) {}

void TetrominoO::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
	WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
	WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
	WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "бс";
}
void TetrominoO::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
	WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
	WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
	WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "  ";
}
void TetrominoO::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}
}
/**/

/* T block Class */
TetrominoT::TetrominoT() : TetrominoT({0, 0}, ROTATE::SPAWN) {}
TetrominoT::TetrominoT(const std::pair<int, int> _position) : TetrominoT(_position, ROTATE::SPAWN) {}
TetrominoT::TetrominoT(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::T, _rotation) {}

void TetrominoT::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "бс";
		break;
	}
}
void TetrominoT::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout<< "  ";
		break;
	}
}
void TetrominoT::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* S block Class */
TetrominoS::TetrominoS() : TetrominoS({0, 0}, ROTATE::SPAWN) {}
TetrominoS::TetrominoS(const std::pair<int, int> _position) : TetrominoS(_position, ROTATE::SPAWN) {}
TetrominoS::TetrominoS(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::S, _rotation) {}

void TetrominoS::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		break;
	}
}
void TetrominoS::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		break;
	}
}
void TetrominoS::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* Z block Class */
TetrominoZ::TetrominoZ() : TetrominoZ({0, 0}, ROTATE::SPAWN) {}
TetrominoZ::TetrominoZ(const std::pair<int, int> _position) : TetrominoZ(_position, ROTATE::SPAWN) {}
TetrominoZ::TetrominoZ(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::Z, _rotation) {}

void TetrominoZ::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "бс";
		break;
	}
}
void TetrominoZ::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "  ";
		break;
	}
}
void TetrominoZ::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* J block Class */
TetrominoJ::TetrominoJ() : TetrominoJ({0, 0}, ROTATE::SPAWN) {}
TetrominoJ::TetrominoJ(const std::pair<int, int> _position) : TetrominoJ(_position, ROTATE::SPAWN) {}
TetrominoJ::TetrominoJ(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::J, _rotation) {}

void TetrominoJ::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "бс";
		break;
	}
}
void TetrominoJ::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "  ";
		break;
	}
}
void TetrominoJ::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* L block Class */
TetrominoL::TetrominoL() : TetrominoL({0, 0}, ROTATE::SPAWN) {}
TetrominoL::TetrominoL(const std::pair<int, int> _position) : TetrominoL(_position, ROTATE::SPAWN) {}
TetrominoL::TetrominoL(const std::pair<int, int> _position, const ROTATE _rotation) : Tetromino(_position, BLOCKSHAPE::L, _rotation) {}

void TetrominoL::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(GetColor(), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "бс";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "бс";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "бс";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "бс";
		break;
	}
}
void TetrominoL::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout<< "  ";
		break;

	case ROTATE::RIGHT:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::TWICE:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout<< "  ";
		break;

	case ROTATE::LEFT:
		WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout<< "  ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout<< "  ";
		break;
	}
}
void TetrominoL::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
	switch(isClockwise)
	{
	case ROTATE::CLOCKWISE: RotationClockwise(); break;
	case ROTATE::COUNTERCLOCKWISE: RotationCounterclockwise(); break;
	}

	switch(GetRotation())
	{
	case ROTATE::SPAWN:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(7).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(7).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(2).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(2).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::RIGHT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(0).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(0).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(4).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(4).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::TWICE:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(3).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(3).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(6).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(6).at(i).at(1)
								});
					break;
				}
			}
		}
		break;

	case ROTATE::LEFT:
		if(isClockwise == ROTATE::CLOCKWISE)
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(5).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(5).at(i).at(1)
								});
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < SRS_TEST_COUNT; i++)
			{
				if(result.at(i))
				{
					SetPosition({
						GetPosition().first + BLOCK_JLSTZ_SRS.at(1).at(i).at(0),
						GetPosition().second - BLOCK_JLSTZ_SRS.at(1).at(i).at(1)
								});
					break;
				}
			}
		}
		break;
	}
}
/**/

/* Ghost Block class */
TetrominoGhost::TetrominoGhost(const BLOCKSHAPE _shape) : TetrominoGhost({0, 0}, _shape, ROTATE::SPAWN) {};
TetrominoGhost::TetrominoGhost(const BLOCKSHAPE _shape, const ROTATE _rotation) : TetrominoGhost({0, 0}, _shape, _rotation) {};
TetrominoGhost::TetrominoGhost(const std::pair<int, int> _position, const BLOCKSHAPE _shape) : TetrominoGhost(_position, _shape, ROTATE::SPAWN) {};
TetrominoGhost::TetrominoGhost(const std::pair<int, int> _position, const BLOCKSHAPE _shape, const ROTATE _rotation) : Tetromino(_position, _shape, _rotation) {};

void TetrominoGhost::Draw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	WindowConsoleControl::SETTEXTCOLOR(static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_GHOST), static_cast<WINDOW_CONSOLE_COLOR>(CONSOLE_COLOR_BACKGROUND));

	switch(GetShape())
	{
	case BLOCKSHAPE::I:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 4, draw_position.second); std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 2); std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 4, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 2); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << "в╞";
			break;
		}
		break;

	case BLOCKSHAPE::O:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << "в╞";
		break;

	case BLOCKSHAPE::T:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << "в╞";
			break;
		}
		break;

	case BLOCKSHAPE::S:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			break;
		}
		break;

	case BLOCKSHAPE::Z:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << "в╞";
			break;
		}
		break;

	case BLOCKSHAPE::J:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << "в╞";
			break;
		}
		break;

	case BLOCKSHAPE::L:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << "в╞";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << "в╞";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << "в╞";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << "в╞";
			break;
		}
		break;
	}
}
void TetrominoGhost::UnDraw()
{
	auto draw_position = PositionToDrawPosition(GetPosition());

	switch(GetShape())
	{
	case BLOCKSHAPE::I:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 4, draw_position.second); std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 2); std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 4, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 2); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << " ";
			break;
		}
		break;

	case BLOCKSHAPE::O:
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
		WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
		WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << " ";
		break;

	case BLOCKSHAPE::T:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1); std::cout << " ";
			break;
		}
		break;

	case BLOCKSHAPE::S:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			break;
		}
		break;

	case BLOCKSHAPE::Z:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << " ";
			break;
		}
		break;

	case BLOCKSHAPE::J:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << " ";
			break;
		}
		break;

	case BLOCKSHAPE::L:
		switch(GetRotation())
		{
		case ROTATE::SPAWN:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second - 1); std::cout << " ";
			break;

		case ROTATE::RIGHT:
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::TWICE:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first + 2, draw_position.second);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second + 1); std::cout << " ";
			break;

		case ROTATE::LEFT:
			WindowConsoleControl::SETPOSITION(draw_position.first - 2, draw_position.second - 1); std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second - 1);     std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second);         std::cout << " ";
			WindowConsoleControl::SETPOSITION(draw_position.first, draw_position.second + 1);     std::cout << " ";
			break;
		}
		break;
	}
}
void TetrominoGhost::Rotate(const ROTATE isClockwise, const std::array<bool, 5> result)
{
}
/**/