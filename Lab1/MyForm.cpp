#include "MyForm.h"
using namespace Lab1;
using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab1::MyForm form;
	Application::Run(%form);
}

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	g = pictureBox1->CreateGraphics();
	bmp = gcnew Bitmap(L"sharkLogo.bmp");
	seeImage = false;
}
   //On Off button
System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (seeImage)
	{
		g->Clear(Color::White);
	}
	else 
	{
		g->DrawImage(bmp, 0, 0);
	}
	DrawGrid();
	seeImage = !seeImage;
}

//Grid Method
void MyForm::DrawGrid()
{
	System::Drawing::Point pt1, pt2;
	Pen^ pen = gcnew Pen(Color::Teal);
	int size = 35;
	int w = pictureBox1->Width;
	int h = pictureBox1->Height;
	int x = size;
	int y = size;

	while (y < h)
	{
		pt1 = Point(0, y);
		pt2 = Point(w, y);
		g->DrawLine(pen, pt1, pt2);
		y += size;
	}
	while (x < w)
	{
		pt1 = Point(x, 0);
		pt2 = Point(x, h);
		g->DrawLine(pen, pt1, pt2);
		x += size;
	}
}
