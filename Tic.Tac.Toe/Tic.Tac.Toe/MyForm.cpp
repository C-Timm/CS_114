#include "MyForm.h"

using namespace Tic_Tac_Toe;
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Tic_Tac_Toe::MyForm form;
	Application::Run(%form);
}

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	
	

	int x = 75;
	int y = 75;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i, j] = gcnew Button;
			grid[i, j]->Location = Point(x, y);
			grid[i, j]->Parent = this;
			grid[i, j]->Size = (Drawing::Size(100, 100));
			grid[i, j]->Text = "";
			grid[i, j]->Click += gcnew System::EventHandler(this, &MyForm::Clicked);
			this->Controls->Add(grid[i, j]);
			grid[i, j]->Font = (gcnew System::Drawing::Font(L"Microsoft Bell MT", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			x += 125;
		}
		x = 75;
		y += 125;
	}
	MessageBox::Show("Click OK to play tic-tac-toe. \n\n  X goes first");

}

System::Void MyForm::Clicked(System::Object^ sender, System::EventArgs^ e)
{

	Button^ button = dynamic_cast<Button^>(sender);

	if (button->Text == "")
	{
		if (toggle.t == true)   //toggles between X and O
		{
			toggle.t = !toggle.t;
			button->Text = "X";
		}

		else
		{
			toggle.t = !toggle.t;
			button->Text = "O";
		}
	}
	turn++;
	refereesDecision();
}


//the "referee" checks to see if anyone won or if there is a tie
void MyForm::refereesDecision()
{
	int turn = turn;

	if (ref->checkWinner("X"))
	{
		MessageBox::Show("Congratulations X has Won!");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				grid[i, j]->Enabled = false;
			}
		}
		Application::Restart();
	}

	if (ref->checkWinner("O"))
	{
		MessageBox::Show("Congratulations O has Won!");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				grid[i, j]->Enabled = false;
			}
		}
		Application::Restart();

	}
	else if (ref->checkTie(turn))
	{
		MessageBox::Show("It's a Tie");
		Application::Restart();

	}

}
