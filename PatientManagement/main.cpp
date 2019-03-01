/*
Christian Medina
Professor Geldiyev
Classes Project
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"
#include "Date.h"
using namespace std;

void mainmenu(char &, int &, int &, Patient(&all)[20], Patient(&chk)[10], Date);


string stringconversion(char id[100]);


int main() {
	int month = 9;
	int day = 9;
	int year = 9;
	cout << "Please enter today's date:" << endl;
	cout << "Month: " << endl;
	cin >> month;
	cout << endl << "Day: " << endl;
	cin >> day;
	cout << endl << "Year: " << endl;
	cin >> year;
	Date today;
	today.setDate(month, day, year); //Check date
	cout << "The date is set to: " << today.getMonthString() << " " << today.getDay() << " " << today.getYear() << endl;
	ifstream filein("CurrentPatients.dat", ifstream::binary);
	Patient all[20];
	Patient checkin[10];
	int allpt = 0;
	int chkpt = 0;
	filein.read(reinterpret_cast<char*>(&allpt), sizeof(allpt));
	for (int i = 0; i < allpt; i++)
	{
		filein.read(reinterpret_cast<char*>(&(all[i])), sizeof(all[i]));
	}
	filein.close();
	char select = '0';
	while (select != 'q' && select != 'Q' || chkpt != 0)
	{
		mainmenu(select, allpt, chkpt, all, checkin, today);
	}
	return 0;
}



void mainmenu(char & dec, int & allreg, int & check, Patient(&allqueue)[20], Patient(&chkin)[10], Date today)
{
	int birthmonth;
	int birthday;
	int birthyear;
	char ID[100];
	int docID;

	char first[50];
	char last[50];
	Patient temp;
	Date birthdate;
	string pick;


	cout << "N. New patient" << endl;
	cout << "R. Returning patient" << endl;
	cout << "O. Remove patient from queue" << endl;
	cout << "I. Show information on patient" << endl;
	cout << "P. Display all patients" << endl;
	cout << "Q. Quit (only when none in queue)" << endl;
	cin >> dec;
	switch (dec) {
	case 'n':
	case 'N':
		if (allreg == 20)
		{
			cout << "Error: unable to add more patients. (20)" << endl;
			break;
		}
		else if (check == 10)
		{
			cout << "Error: cannot add new patient, queue is full." << endl;
			break;
		}
		else
		{
			cout << "First name:" << endl;
			cin >> first;
			cout << "Last name." << endl;
			cin >> last;
			cout << "Date of birth:" << endl;
			cout << "MM: " << endl;
			cin >> birthmonth;
			cout << endl << "DD: " << endl;
			cin >> birthday;
			cout << endl << "YYYY: " << endl;
			cin >> birthyear;
			birthdate.setDate(birthmonth, birthday, birthyear);
			cout << endl << "Enter Doctor ID:" << endl;
			cin >> docID;

			strncpy_s(ID, last, 14);
			strncat_s(ID, first, 14);
			char tempYear[5];
			sprintf_s(tempYear, "%d", birthdate.getYear());
			strcat_s(ID, tempYear);
			Patient temp(first, last, ID, birthdate, docID);
			allqueue[allreg] = temp;
			allreg++;
			chkin[check] = temp;
			check += 1;
			cout << "Patient added." << endl;
			break;
		}
	case 'r':
	case 'R':
		cout << "Please enter returning patient's ID." << endl;
		cin >> ID;
		for (int i = 0; i < allreg; i++)
		{
			pick = stringconversion(ID);
			if (pick == allqueue[i].getID())
			{
				cout << "Patient found and checked in." << endl;
				chkin[check] = allqueue[i];
				check++;
				break;
			}
			else if (i == (allreg - 1))
			{
				cout << "Patient not found, please check the ID and try again or add a new patient." << endl;
			}
		}
		break;
	case 'O':
	case 'o':
		if (check == 0)
		{
			cout << "There are no patients in the office." << endl;
			break;
		}
		cout << "Enter patient ID to check out." << endl;
		cin >> ID;
		pick = stringconversion(ID);
		for (int i = 0; i <= check; i++)
		{
			if (pick == chkin[i].getID())
			{
				cout << "Enter procedure ID: " << endl;
				Patient temp = chkin[i];
				chkin[i] = chkin[check - 1];
				chkin[check - 1] = temp;
				int procID = 0;
				int provID = 0;
				cin >> procID;
				cout << "Enter Doctor ID:" << endl;
				cin >> provID;
				if (chkin[check - 1].enterProcedure(today, procID, provID))
				{
					cout << "Checkout complete." << endl;
				}
				else {
					cout << "Error: patient has too many procedures, not saved." << endl;
				}
				for (int j = 0; j < allreg; j++)
				{
					if (pick == allqueue[j].getID())
					{
						allqueue[j] = chkin[check - 1];
						check--;
						break;
					}
				}
			}
			else if (i == (check - 1))
			{
				cout << "Patient not found, double check ID or use checkin (O)" << endl;
				break;
			}
		}
		break;
	case 'I':
	case 'i':
		cout << "Enter patient ID:" << endl;
		cin >> ID;
		pick = stringconversion(ID);
		for (int i = 0; i < allreg; i++)
		{
			if (pick == allqueue[i].getID())
			{
				cout << endl << allqueue[i].getFirstName() << " " << allqueue[i].getLastName() << endl;
				cout << endl << "Patient ID: " << allqueue[i].getID() << endl;
				cout << endl << "Prescriber: " << allqueue[i].getPrimaryDoctorID() << endl;
				cout << endl << "Past procedures: " << endl;
				allqueue[i].printAllProcedures();
				break;
			}
			else if (i == (allreg - 1))
			{
				cout << "Patient not found. Try again or add new." << endl;
			}
		}
		break;
	case 'P':
	case 'p':
		if (allreg == (0))
		{
			cout << "There are no patients registered." << endl;
			break;
		}
		cout << "Current Patients: " << allreg << endl;
		for (int i = 0; i < allreg; i++)
		{
			cout << endl << allqueue[i].getFirstName() << " " << allqueue[i].getLastName() << endl;
			cout << endl << "Patient ID: " << allqueue[i].getID() << endl;
			cout << endl << "Doctor: " << allqueue[i].getPrimaryDoctorID() << endl;
		}
		break;
	case 'q':
	case 'Q':
		if (check != 0)
		{
			cout << "Error: cannot quit, patients are still in the queue." << endl;
			cout << "Waitlist: " << check << endl;
			for (int i = 0; i < check; i++)
			{
				cout << endl << chkin[i].getFirstName() << " " << chkin[i].getLastName() << endl;
				cout << endl << "Patient ID: " << chkin[i].getID() << endl;
				cout << endl << "Doctor: " << chkin[i].getPrimaryDoctorID() << endl;
			}
			break;
		}
		else
		{
			cout << "Saving." << endl;
			ofstream output("CurrentPatients.dat", ifstream::binary);
			output.write(reinterpret_cast<char*>(&allreg), sizeof(allreg));
			for (int i = 0; i < allreg; i++)
			{
				output.write(reinterpret_cast<char*>(&allqueue[i]), sizeof(allqueue[i]));
			}
			output.close();
			break;
		}
	default:
		cout << endl << "Invalid. Try again." << endl;
	}
}

string stringconversion(char ID[100])
{
	return string(ID);
}

