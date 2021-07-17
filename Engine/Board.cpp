#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	
	const int off_x = x+borderwidth + borderpadding;
	const int off_y = y+borderwidth + borderpadding;

	gfx.DrawRectDim(loc.x * dimension + off_x + cellpadding, loc.y * dimension + off_y +cellpadding, dimension - cellpadding*2, dimension - cellpadding * 2, c);
}
 
int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard( const Location& loc) const
{
	return loc.x >=0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = top + (borderwidth + borderpadding) *2  + height * dimension;
	const int right = left + (borderwidth + borderpadding) * 2 + width * dimension;
	//top
	gfx.DrawRect(left, top, right, top + borderwidth, bordercolor);
	//left
	gfx.DrawRect(left, top+borderwidth, left+borderwidth, bottom - borderwidth, bordercolor);
	//bottom
	gfx.DrawRect(left, bottom - borderwidth, right, bottom, bordercolor);
	//right
	gfx.DrawRect(right - borderwidth, top+borderwidth, right, bottom-borderwidth, bordercolor);
}
