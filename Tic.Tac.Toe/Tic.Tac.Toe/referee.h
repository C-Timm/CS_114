#pragma once
#include <string>


using namespace System;
using namespace System::Windows::Forms;

ref class referee
{
	array<Button^, 2> ^grid = gcnew array<Button^, 2>(3, 3);

public:
	referee(array< Button^, 2> ^grid);
private:
	bool Vert(String^);
	bool Horiz(String^);
	bool across(String^);
public:
	
	bool checkTie(int);
	bool checkWinner(String^);

};

