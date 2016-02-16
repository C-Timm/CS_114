#pragma once

class Grade
{
public:
	Grade();
	void Q1(int quiz1);
	void Q2(int quiz2);
	void mid(int midterm);
	void fin(int finalexam);
	int get_Q1();
	int get_Q2();
	int get_Midterm();
	int get_Finalexam();
	
private:
	int quiz1;
	int quiz2;
	int midterm;
	int finalexam;
};

