#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Homework2;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Homework2::MyForm form;
	Application::Run(%form);
}


System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e){
	g = pictureBox1->CreateGraphics();
	

}

System::Void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e){
	readPoints();
	Drawimagegrid();
	Grid();
	

}
//Draw 
void MyForm::Grid(){
	System::Drawing::Point pt1, pt2;
	Pen^ pen = gcnew Pen(Color::Teal);
	int gsize = 50;
	int w = pictureBox1->Width;
	int h = pictureBox1->Height;
	int x = gsize;
	int y = gsize;

	while (y < h){
		pt1 = Point(0, y);
		pt2 = Point(w, y);
		g->DrawLine(pen, pt1, pt2);
		y += gsize;
	}
	while (x < w){
		pt1 = Point(x, 0);
		pt2 = Point(x, h);
		g->DrawLine(pen, pt1, pt2);
		x += gsize;
	}
}
void MyForm::Drawimagegrid(){
	g->Clear(Color::White);
	for (int i = 0; i < 9; i++) {
		for (int t = 0; t < 9; t++) {
			if (picCords[i, t]) {
				bmp = gcnew Bitmap(L"sharkLogo.bmp");
				g->DrawImage(bmp, i * 50, t * 50);
			}
		}
	}
}
void MyForm::readPoints() {
	delete picCords;
	picCords = gcnew array<bool, 2>(9, 9) {
		{false},{false},{false},
		{false},{false},{false},
		{false},{false},{false},
	};
	using namespace std;
	ifstream in;
	ofstream out;
	string InputFileName = "location.txt";
	in.open(InputFileName);
	string reader;

	while (!in.eof()) {
		getline(in, reader);
		int x, y;
		bool get = getPoints(reader, x, y);
		if (!get)
			break;
		if (x < 10 && y < 10 && x > 0 && y > 0)
			picCords[x - 1, y - 1] = true;
	}
	in.close();
}

bool MyForm::getPoints(std::string s, int& y1, int& x1) {
	using namespace std;
	string::iterator iter;
	string x[2];
	int index = 0;
	for (iter = s.begin(); iter != s.end(); iter++) {
		if (*iter != ' ')
			x[index] = x[index] + *iter;
		else
			index++;

		if (index > 1)
			break;
	}
	//checks if we have all everything, returns false if we dont

	if (index < 1)
	return false;
	x1 = std::stoi(x[0]);
	y1 = std::stoi(x[1]);
	
	return true;
}
