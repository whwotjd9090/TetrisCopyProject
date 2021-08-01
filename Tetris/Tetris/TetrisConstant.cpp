#include "TetrisConstant.hpp"

std::pair<int, int> PositionToDrawPosition(std::pair<int, int> _position)
{
	return std::make_pair(_position.first * BLOCK_SIZE_X + STAGE_FIELD_LEFT, _position.second + STAGE_FIELD_TOP);
}
std::pair<int, int> DrawPositionToPosition(std::pair<int, int> _draw_position)
{
	return {(_draw_position.first - STAGE_FIELD_LEFT) / 2, _draw_position.second - STAGE_FIELD_TOP};
}