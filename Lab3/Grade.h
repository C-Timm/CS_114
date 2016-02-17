/*
 * Grade.h
 *
 *  Created on: Feb 16, 2016
 *      Author: Bigtimetimmmy
 */

#pragma once
#include <string>
#include <iostream>

class Grade
{
	Grade();

	double quiz1 = 0;
	double quiz2 = 0;
	double midterm = 0;
	double finalexam = 0;
	double finalGrade = 0;


	void calcGrade()
	{
		double qTotal;
		double mTotal;
		double fTotal;

		qTotal = quiz1 + quiz2;
		qTotal /= 20;
		qTotal *= 0.25;

		mTotal = midterm;
		mTotal /= 100;
		mTotal *= 0.25;

		fTotal = finalexam;
		fTotal /= 100;
		fTotal *= 0.50;

		finalGrade = fTotal + mTotal + qTotal;

	}

public:


	double getGrade()
	{
	calcGrade();
	return finalGrade;
	}

	void inputGrade(double q1, double q2, double mid, double fin )
	{
		quiz1 = q1;
		quiz2 = q2;
		midterm = mid;
		finalexam = fin;


	}




};
