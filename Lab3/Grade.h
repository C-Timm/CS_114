/*
 * Grade.h
 *  Created on: Feb 17, 2016
 *      Author: C-Timm
 */

#ifndef Grade_h_
#define Grade_h_
#include <math.h>
#include "StudentRecord.h"

using namespace std;

class Grade
{
public:
	Grade(StudentRecord* rec);
	~Grade();
	void Letter();
	float getGrade();
	void percent();
private:
	StudentRecord student;
	float gradePercent;
	char gradeLetter;
};
#endif


