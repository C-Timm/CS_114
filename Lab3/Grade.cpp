#include "stdafx.h"
#include "Grade.h"


Grade::Grade()
{
	this->quiz1 = quiz1;
	this->quiz2 = quiz2;
	this->midterm = midterm;
	this->finalexam = finalexam;
}

void Grade::Q1(int quiz1)
{
	quiz1 * 0.125;
}

void Grade::Q2(int quiz2)
{
	quiz2 * 0.125;
}

void Grade::mid(int midterm)
{
	midterm * 0.25;
}

void Grade::fin(int finalexam)
{
	finalexam * 0.50;
	
}

int Grade::get_Q1()
{
	return this->quiz1;
}

int Grade::get_Q2() 
{
	return this->quiz2;
}

int Grade::get_Midterm()
{
	return this->midterm;
}

int Grade::get_Finalexam()
{
	return this->finalexam;
}

