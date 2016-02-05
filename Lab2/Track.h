#pragma once
class Track
{
public:
	Track();
	void setPos(int x, int y);
	int GetX();
	int GetY();

private:
	int x;
	int y;
};
