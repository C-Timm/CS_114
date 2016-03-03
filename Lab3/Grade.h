/*
 * Grade.h
 *  Created on: Feb 17, 2016
 *      Author: C-Timm
 */

#ifndef Grade.h
#define Grade.h
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


