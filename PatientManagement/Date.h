#pragma once
// Definition of class Date in date.h 
#ifndef DATE1_H
#define DATE1_H
#include <iostream>
#include <string>
using namespace std;

class Date {
	friend ostream &operator<<(ostream &, const Date &); // allows easy output to a ostream

public:
	Date(int m = 1, int d = 1, int y = 1900); // constructor, note the default values
	void setDate(int, int, int); // set the date
	void operator+=(int &);  // Does not return anything
	bool leapYear() const;   // is the year for the date object a leap year?
	bool endOfMonth() const; // is the date of the object the last day of the month?
	int getMonth() const; 		// Get the month integer
	int getDay() const;			// Get the day
	int getYear() const; 			// Get the year
	string getMonthString() const;  // Get string name of month
	Date &operator=(Date d);
private:
	int month;
	int day;
	int year;

	static const int days[];         // array of days per month
	static const string monthName[]; // array of month names
	void helpIncrement();            // utility function
};

#endif