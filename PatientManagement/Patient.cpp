#include <iostream>
#include <string>
#include "Patient.h"

using namespace std;
Patient::Patient()
{
	(*this).setFirstName("John");
	(*this).setLastName("Jones");
	(*this).setID("JonesJohn1998");
	(*this).setBirthDate(Date());
	(*this).setPrimaryDoctorID(0);
}
// Constructor
Patient::Patient(const char * first, const char * last, const char * ID, Date birthdate, const int DocID)
{
	this->setFirstName(first);
	this->setLastName(last);
	this->setID(ID);
	this->setBirthDate(birthdate);
	this->setPrimaryDoctorID(DocID);
}


Patient & Patient::setFirstName(const char * first)
{
	if (strlen(first) > 14)
	{
		strncpy_s(firstName, first, 14);
	}
	else
	{
		strcpy_s(firstName, first);
	}
	return(*this);
}

Patient & Patient::setLastName(const char * last) {
	if (strlen(last) > 14)
	{
		strncpy_s(lastName, last, 14);
	}
	else
	{
		strcpy_s(lastName, last);
	}
	return(*this);
}

Patient & Patient::setID(const char * idNumber)
{
	if (strlen(idNumber) > 32)
	{
		strncpy_s(ID, idNumber, 32);
	}
	else
	{
		strcpy_s(ID, idNumber);
	}
	return(*this);

}

Patient & Patient::setBirthDate(Date bd)
{
	Date birthdaycheck = (bd.getMonth(), bd.getDay(), bd.getYear());
	(*this).birthdate = birthdaycheck;
	return(*this);
}

Patient & Patient::setPrimaryDoctorID(const int DoctorID)
{

	primaryDoctorID = DoctorID;
	return(*this);
}

const char * Patient::getFirstName()
{
	return firstName;
}

const char * Patient::getLastName()
{
	return lastName;
}
const char * Patient::getID()
{
	return ID;
}

Date Patient::getBirthDate()
{
	return birthdate;
}

int Patient::getPrimaryDoctorID()
{
	return primaryDoctorID;
}

Patient & Patient::operator=(Patient second)
{
	strcpy_s(firstName, second.firstName);
	strcpy_s(lastName, second.lastName);
	strcpy_s(ID, second.ID);
	birthdate = (second.birthdate);
	primaryDoctorID = (second.primaryDoctorID);
	for (int i = 0; i < second.currentCountOfProcedures; i++)
	{
		(*this).record[i] = second.record[i];
	}
	(*this).currentCountOfProcedures = second.currentCountOfProcedures;
	return (*this);
}

bool Patient::enterProcedure(Date procedureDate, int procedureID, int procedureProviderID)
{
	if (currentCountOfProcedures < 500)
	{
		record[currentCountOfProcedures].dateOfProcedure = procedureDate;
		record[currentCountOfProcedures].procedureID = procedureID;
		record[currentCountOfProcedures].procedureProviderID = procedureProviderID;
		currentCountOfProcedures++;
		return true;
	}
	return false;
}

void Patient::printAllProcedures()
{
	for (int i = 0; i < currentCountOfProcedures; i++)
	{
		cout << "Procedure: " << record[i].procedureID << " Date: " << record[i].dateOfProcedure << " Provider: " << record[i].procedureProviderID << endl;
	}
}

