#include "Track.h"

Track::Track()
{
	this->x = 0;
	this->y = 0;
}
void Track::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Track::GetX()
{
	return this->x;
}
int Track::GetY()
{
	return this->y;
}


