#ifndef Patient_h
#define Patient_h
#include "Date.h"
#include <string>
#include <iostream>

struct procedure
{
	Date dateOfProcedure;
	int procedureID;
	int procedureProviderID;
};

class Patient {
public:
	Patient();
	Patient(const char *, const char *, const char *, Date, int);
	//Put in default values just as in Date class
	//Use the set functions so input values are checked  
	Patient & setID(const char *);  //check if length of name string is < 32.
									// if not, shorten to 32 letters.

	Patient & setFirstName(const char *); //check if length of name string is < 
										  // 15, if not, shorten to 14 letters.
	Patient & setLastName(const char *);  //check if length of name string is < 
										  // 15, if not, shorten to 14 letters.
	Patient & setBirthDate(Date);
	Patient & setPrimaryDoctorID(int);

	Patient & operator=(Patient second);
	const char * getID();
	const char * getFirstName();
	const char * getLastName();
	Date getBirthDate();
	int getPrimaryDoctorID();
	bool enterProcedure(Date procedureDate, int procedureID, int procedureProviderID);//tries to add a new entry to record array, returns true if added, false if cannot be added
	void printAllProcedures();
private:
	char ID[33];
	char firstName[15];
	char lastName[15];
	Date birthdate;
	int primaryDoctorID;
	procedure record[500];
	int currentCountOfProcedures = 0;  // keeps track of how many procedures have been recorded.  if it reaches 500, no new procedures can be entered.

};

#endif