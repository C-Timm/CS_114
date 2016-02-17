/*
 * Grade.cpp
 *  Created on: Feb 17, 2016
 *      Author: C-Timm
 */

#include "Grade.h"
#include <iostream>
#include <iomanip>


Grade::Grade(StudentRecord* rec) {
	memcpy(&student, rec, sizeof(StudentRecord));
	percent();

}

Grade::~Grade()
{
}
void Grade::percent()
{
	//quizzes
	gradePercent = (float)((((student.quiz1 + student.quiz2)/ 2.0f) /10.0f)*0.25f);
	//Midterm
	gradePercent += (float)((student.midterm /100.0f)*0.25f);
	//Final
	gradePercent += (float)((student.finalexam / 100.0f)*0.50f);

	gradePercent *= 100.0f;

}

float Grade::getGrade()
{
	return gradePercent;
}

void Grade::Letter()
{
	if (gradePercent >= 90.0f)
	{
		gradeLetter = 'A';
		cout << "Final Grade: " << gradeLetter << endl;
	}
	else if (gradePercent >= 80.0f){
		gradeLetter = 'B';
		cout << "Final Grade: " << gradeLetter << endl;
	}
	else if (gradePercent >= 70.0f){
		gradeLetter = 'C';
		cout << "Final Grade: " << gradeLetter << endl;
	}
	else if (gradePercent >= 60.0f){
		gradeLetter = 'D';
		cout << "Final Grade: " << gradeLetter << endl;
	}
	else
	{
		gradeLetter = 'F';
		cout << "Final Grade: " << gradeLetter << endl;
	}

}



