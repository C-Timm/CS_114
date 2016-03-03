#include "referee.h"

referee::referee(array< Button^, 2> ^ grid)
{
	this->grid = grid;
}

bool referee::Vert(String^ player)
{
	for (int i = 0; i < 3; i++) {
		if (grid[i, 0]->Text == player)
		if (grid[i, 1]->Text == player)
		if (grid[i, 2]->Text == player)
			return true;

	}
	return false;
}
bool referee::Horiz(String^ player)
{
	for (int i = 0; i < 3; i++) {
		if (grid[0, i]->Text == player)
		if (grid[1, i]->Text == player)
		if (grid[2, i]->Text == player)
			return true;

	}
	return false;
}
bool referee::across(String^ player)
{
	if (grid[0, 0]->Text == player || grid[0, 2]->Text == player) {
		if (grid[1, 1]->Text == player) {
			if (grid[0, 0]->Text == player && grid[2, 2]->Text == player)
			{
				return true;
			}
			else if (grid[0, 2]->Text == player && grid[2, 0]->Text == player)
			{
				return true;
			}
		}
	}

	return false;
};

bool referee::checkTie(int turn)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i, j]->Text == "" || turn > 9)
			{
				return false;
			}
		}
	}
	return true;

}
bool referee::checkWinner(String^ player)
{
	if (across(player))
	{
		return true;
	}
	else if (Horiz(player))
	{
		return true;
	}
	else if (Vert(player))
	{
		return true;
	}
	return false;
}

