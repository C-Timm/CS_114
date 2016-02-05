#include "MyForm.h"

using namespace Lab_2;
using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab_2::MyForm form;
	Application::Run(%form);
}

System::Void MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (seeImage)
	{
		g->Clear(Color::White);
	}
	else
	{
		DrawPic();
	}
	DrawGrid();
	seeImage = !seeImage;
}
System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	place = new Track();
	offset = 20;
	g = pictureBox1->CreateGraphics();
	//Loading bitmap image
	 bmp = gcnew Bitmap(L"sharkLogo.bmp");
	seeImage = false;
}

//Up
System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (seeImage)
	{
		place->setPos(place->GetX(), place->GetY() - offset);
		DrawPic();
	}
}
//Down
System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (seeImage) 
	{
		place->setPos(place->GetX(), place->GetY() + offset);
		DrawPic();
	}
}
//Right
System::Void MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
	if (seeImage)
	{
		place->setPos(place->GetX() + offset, place->GetY());
		DrawPic();
	}
}
//Left
	System::Void MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (seeImage)
		{
			place->setPos(place->GetX() - offset, place->GetY());
			DrawPic();
		}
	}
	//Methods

	//draws bitmap picture
	void MyForm::DrawPic()
	{
		g->DrawImage(bmp, place->GetX(), place->GetY());
		DrawGrid();

	}
	//draws grid
	void MyForm::DrawGrid()
	{
		int gridsize = 15;
		int w = pictureBox1->Width;
		int h = pictureBox1->Height;
		int x = gridsize;
		int y = gridsize;
		System::Drawing::Point pt1, pt2;
		Pen^ pen = gcnew Pen(Color::Teal);

		while (y < h) 
		{
			pt1 = Point(0, y);
			pt2 = Point(w, y);
			g->DrawLine(pen, pt1, pt2);
			y += gridsize;
		}
		while (x < w)
		{
			pt1 = Point(x, 0);
			pt2 = Point(x, h);
			g->DrawLine(pen, pt1, pt2);
			x += gridsize;
		}
}
