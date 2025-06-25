#include <iostream>
#include <limits>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
const string admin_name = "admin";
const string admin_pas = "admin123";
int total_students = 0;
int total_teachers = 0;
int std_index;
int teacher_index;
const int size = 100;
// Text Files
string StudentFile = "StudentRecord.txt";
string TeacherFile = "TeacherRecord.txt";
string MidMarksFile = "MidMarksRecord.txt";
string FinalMarksFile = "FinalMarksRecord.txt";
string PresentFile = "PresentRecord.txt";
string AbsentFile = "AbsentRecord.txt";
// Total Arrays
string arr_name[size];
string teacher_name[size];
string father_name[size];
string teacher_father_name[size];
string arr_address[size];
string teacher_address[size];
string qualification[size];
int arr_roll_no[size];
int arr_class[size];
string arr_contact[size];
string teacher_contact[size];
string teacher_id[size];
string std_username[size];
string teacher_username[size];
string std_pas[size];
string teacher_pas[size];
string subject[size];
int arr_present[size][size] = {0}; //{0} is initializer list which initailize all values to zero
int arr_absent[size][size] = {0};
float mid_marks[size][size];
float final_marks[size][size];
// Functions For Student
void StudentLoginMenu();
void MainMenuStudent();
void StudentPersonalDetails();
void ViewAttendence();
void ViewMarks();
// Functions For Teacher
void TeacherLoginMenu();
void MainMenuTeacher();
void TeacherPersonalDetails();
void MarkAttendence();
void MarkMarks();
void MidMarks();
void FinalMarks();
// Functions For Admin
void AdminLoginMenu();
void MainMenuAdmin();
void AddStudentRecord();
void DeleteStudentRecord();
void UpdateStudentRecord();
void ViewStudentRecord();
void AddTeacherRecord();
void ViewTeachersRecord();
void DeleteTeachersRecord();
// File Handling Functions
void StoreStudentRecord();
void StoreTeacherRecord();
void StoreMidMarks();
void StoreFinalMarks();
void StorePresentRecord();
void StoreAbsentRecord();
void ReadStudentRecord();
void ReadTeacherRecord();
void ReadMidMarks();
void ReadFinalMarks();
void ReadPresentRecord();
void ReadAbsentRecord();
// Header Function
void Header()
{
	system("cls");
	cout << "\n";
	cout << "                                     ##================================================================##" << endl;
	cout << "                                     ##                                                                ##" << endl;
	cout << "                                     ##                    School Management System                    ##" << endl;
	cout << "                                     ##                                                                ##" << endl;
	cout << "                                     ##================================================================##" << endl;
	cout << "\n\n";
}
// Functions For Student
void MainMenuStudent()
{
	cout << "  Main Menu >\n";
	cout << "  ----------------------------\n";
	cout << "  Select one of the following options number.....\n";
	cout << "  1. View Personal Details\n";
	cout << "  2. View Attendence\n";
	cout << "  3. View Marks\n";
	cout << "  4. Exit!\n";
	cout << "  Enter Option No:   ";
}
void StudentLoginMenu()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool login = false;
	string username;
	string password;
	for (int i = 0; i < 3; i++)
	{
		Header();
		cout << "  Login Menu >\n";
		cout << "  ------------------------------------\n";
		cout << "  Enter Username:   ";
		getline(cin, username);
		cout << "  Enter Password:   ";
		getline(cin, password);
		for (int j = 0; j < total_students; j++)
		{
			if (std_username[j] == username && std_pas[j] == password)
			{
				cout << "  Login Successfully...!";
				sleep(1);
				login = true;
				std_index = j;
				break;
			}
		}
		if (login)
		{
			break;
		}
		else if (i < 2)
		{
			cout << "  Wrong username/password...!" << endl;
			sleep(1);
		}
	}
	if (!login)
	{
		cout << "  Too many failed attempts exiting...!\n";
		sleep(2);
		return;
	}
	while (true)
	{
		Header();
		MainMenuStudent();
		int value;
		cin >> value;
		switch (value)
		{
		case 1:
			StudentPersonalDetails();
			break;
		case 2:
			ViewAttendence();
			break;
		case 3:
			ViewMarks();
			break;
		case 4:
			return;
		default:
			cout << "  Wrong Option...!\n";
			sleep(1);
		}
	}
}
void StudentPersonalDetails()
{
	Header();
	cout << "  Main Menu > Sub-Menu > ViewPersonalDetails\n";
	cout << "  -----------------------------------------------\n\n";
	cout << "  Personal Details:\n\n";
	cout << "  Student Name:            " << arr_name[std_index] << "\n";
	cout << "  Father Name:             " << father_name[std_index] << "\n";
	cout << "  Roll-No :                " << arr_roll_no[std_index] << "\n";
	cout << "  Class:                   " << arr_class[std_index] << "\n";
	cout << "  Contact No:              " << arr_contact[std_index] << "\n";
	cout << "  Address:                 " << arr_address[std_index] << "\n\n";
	cout << "  Login Details:\n\n";
	cout << "  Student Username:        " << std_username[std_index] << "\n";
	cout << "  Student Password:        " << std_pas[std_index] << "\n\n";
	cout << "  Press any key to exit...!";
	getche();
}
void ViewAttendence()
{
	Header();
	cout << "  Main Menu > Sub-Menu > ViewAttendence\n";
	cout << "  -----------------------------------------------\n";
	cout << "  Attendence:\n\n";
	for (int i = 0; i < total_teachers; i++)
	{
		cout << "  " << subject[i] << ":     " << arr_present[i][std_index] << " Lectures Present     " << arr_absent[i][std_index] << " Lectures Absent\n\n";
	}
	cout << "  Press any key to exit...!";
	getche();
}
void ViewMarks()
{
	int sum = 0, sum1 = 0;
	Header();
	cout << "  Main Menu > Sub-Menu > ViewMarks\n";
	cout << "  -----------------------------------------------\n\n";
	cout << "  Mid-Term Marks:\n\n";
	for (int row = 0; row < total_teachers; row++)
	{
		cout << "  " << subject[row] << " Marks:   " << mid_marks[row][std_index] << " / 50" << endl;
		sum = sum + mid_marks[row][std_index]; // obtained marks sum
		sum1 = sum1 + 50;					   // counting total marks
	}
	cout << "  Total Obtained Marks (out of " << sum1 << "):   " << sum << endl
		 << endl;
	cout << "  Final-Term Marks:\n\n";
	sum = 0, sum1 = 0;
	for (int row = 0; row < total_teachers; row++)
	{
		cout << "  " << subject[row] << " Marks:   " << final_marks[row][std_index] << " / 50" << endl;
		sum = sum + final_marks[row][std_index];
		sum1 = sum1 + 50;
	}
	cout << "  Total Obtained Marks (out of " << sum1 << "):   " << sum << endl
		 << endl;
	cout << "  Press any key to exit...!\n";
	getche();
}
// Functions For Teacher
void MainMenuTeacher()
{
	cout << "  Main Menu >\n";
	cout << "  ----------------------------\n";
	cout << "  Select one of the following options number.....\n";
	cout << "  1. View Personal Details\n";
	cout << "  2. Mark Attendence\n";
	cout << "  3. Mark Marks\n";
	cout << "  4. Exit!\n";
	cout << "  Enter Option No:   ";
}
void TeacherLoginMenu()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool login = false;
	string username;
	string password;
	for (int i = 0; i < 3; i++)
	{
		Header();
		cout << "  Login Menu >\n";
		cout << "  ------------------------------------\n";
		cout << "  Enter Username:   ";
		getline(cin, username);
		cout << "  Enter Password:   ";
		getline(cin, password);
		for (int j = 0; j < total_teachers; j++)
		{
			if (teacher_username[j] == username && teacher_pas[j] == password)
			{
				cout << "  Login Successfully...!";
				sleep(1);
				login = true;
				teacher_index = j;
				break;
			}
		}
		if (login)
		{
			break;
		}
		else if (i < 2)
		{
			cout << "  Wrong username/password...!" << endl;
			sleep(1);
		}
	}
	if (!login)
	{
		cout << "  Too many failed attempts exiting...!\n";
		sleep(2);
		return;
	}
	while (true)
	{
		Header();
		MainMenuTeacher();
		int value;
		cin >> value;
		switch (value)
		{
		case 1:
			TeacherPersonalDetails();
			break;
		case 2:
			MarkAttendence();
			break;
		case 3:
			MarkMarks();
			break;
		case 4:
			return;
		default:
			cout << "  Wrong Option...!\n";
			sleep(1);
		}
	}
}
void TeacherPersonalDetails()
{
	Header();
	cout << "  Main Menu > Sub-Menu > ViewPersonalDetails\n";
	cout << "  -----------------------------------------------\n\n";
	cout << "  Personal Details:\n\n";
	cout << "  Student Name:            " << teacher_name[teacher_index] << "\n";
	cout << "  Father Name:             " << teacher_father_name[teacher_index] << "\n";
	cout << "  Qualification:           " << qualification[teacher_index] << "\n";
	cout << "  Assign Subject:          " << subject[teacher_index] << "\n";
	cout << "  Contact No:              " << teacher_contact[teacher_index] << "\n";
	cout << "  Address:                 " << teacher_address[teacher_index] << "\n";
	cout << "  Teacher-ID:              " << teacher_id[teacher_index] << "\n\n";
	cout << "  Login Details:\n\n";
	cout << "  Student Username:        " << teacher_username[teacher_index] << "\n";
	cout << "  Student Password:        " << teacher_pas[teacher_index] << "\n\n";
	cout << "  Press any key to exit...!";
	getche();
}
void MarkAttendence()
{
	char ch;
	for (int i = 0; i < total_students; i++)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > MarkAttendence\n";
		cout << "  -----------------------------------------------\n\n";
		cout << "  Name:  " << arr_name[i] << "     Roll-No:   " << arr_roll_no[i] << endl;
		cout << "  Enter (P/p for present and A/a for absent):   ";
		cin >> ch;
		if (ch == 'P' || ch == 'p')
		{
			arr_present[teacher_index][i]++;
		}
		else if (ch == 'A' || ch == 'a')
		{
			arr_absent[teacher_index][i]++;
		}
	}
	StorePresentRecord();
	StoreAbsentRecord();
}
void StorePresentRecord()
{
	fstream File(PresentFile, ios::out);
	if (File.is_open())
	{
		for (int i = 0; i < total_teachers; i++)
		{
			for (int j = 0; j < total_students; j++)
			{
				File << arr_present[i][j] << ",";
			}
			File << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	File.close();
}
void ReadPresentRecord()
{
	string line;
	int row = 0, col = 0;
	string word = "";
	fstream Record(PresentFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ',')
					{
						arr_present[row][col] = stoi(word);
						col++;
						word = "";
					}
					else
					{
						word = word + line[i];
					}
				}
			}
			row++;
			col = 0;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void StoreAbsentRecord()
{
	fstream File(AbsentFile, ios::out);
	if (File.is_open())
	{
		for (int i = 0; i < total_teachers; i++)
		{
			for (int j = 0; j < total_students; j++)
			{
				File << arr_absent[i][j] << ",";
			}
			File << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	File.close();
}
void ReadAbsentRecord()
{
	string line;
	int row = 0, col = 0;
	string word = "";
	fstream Record(AbsentFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ',')
					{
						arr_absent[row][col] = stoi(word);
						col++;
						word = "";
					}
					else
					{
						word = word + line[i];
					}
				}
			}
			row++;
			col = 0;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void MarkMarks()
{
	int value;
	while (true)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > MarkMarks\n";
		cout << "  -----------------------------------------------\n";
		cout << "  1.Mid-Term Marks\n";
		cout << "  2.Final-Term Marks\n";
		cout << "  3.Exit!\n";
		cout << "  Enter Option No:   ";
		cin >> value;
		switch (value)
		{
		case 1:
			MidMarks();
			break;
		case 2:
			FinalMarks();
			break;
		case 3:
			return;
		default:
			cout << "  Wrong Option...!\n";
			sleep(1);
		}
	}
}
void MidMarks()
{
	for (int i = 0; i < total_students; i++)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > MarkMarks > Mid-Term Marks\n";
		cout << "  -----------------------------------------------\n";
		cout << "  Name:  " << arr_name[i] << "     Roll-No:   " << arr_roll_no[i] << endl;
		cout << "  Enter Mid-Term Marks (out of 50):   ";
		cin >> mid_marks[teacher_index][i]; // teacher index bcz store marks per subject row-wise
		StoreMidMarks();
	}
}
void StoreMidMarks()
{
	fstream Record(MidMarksFile, ios::out);
	if (Record.is_open())
	{
		for (int i = 0; i < total_teachers; i++)
		{
			for (int j = 0; j < total_students; j++)
			{
				Record << mid_marks[i][j] << ",";
			}
			Record << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void ReadMidMarks()
{
	string line;
	int row = 0, col = 0;
	string word = "";
	fstream Record(MidMarksFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ',')
					{
						mid_marks[row][col] = stof(word);
						col++;
						word = "";
					}
					else
					{
						word = word + line[i];
					}
				}
			}
			row++;
			col = 0;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void FinalMarks()
{
	for (int i = 0; i < total_students; i++)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > MarkMarks > Final-Term Marks\n";
		cout << "  -----------------------------------------------\n";
		cout << "  Name:  " << arr_name[i] << "     Roll-No:   " << arr_roll_no[i] << endl;
		cout << "  Enter Final-Term Marks (out of 50):   ";
		cin >> final_marks[teacher_index][i];
	}
	StoreFinalMarks();
}
void StoreFinalMarks()
{
	fstream Record(FinalMarksFile, ios::out);
	if (Record.is_open())
	{
		for (int i = 0; i < total_teachers; i++)
		{
			for (int j = 0; j < total_students; j++)
			{
				Record << final_marks[i][j] << ",";
			}
			Record << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void ReadFinalMarks()
{
	string line;
	int row = 0, col = 0;
	string word = "";
	fstream Record(FinalMarksFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{
				for (int i = 0; i < line.length(); i++)
				{
					if (line[i] == ',')
					{
						final_marks[row][col] = stof(word);
						col++;
						word = "";
					}
					else
					{
						word = word + line[i];
					}
				}
			}
			row++;
			col = 0;
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
// Functions For Admin
void MainMenuAdmin()
{
	cout << "  Main Menu >\n";
	cout << "  ----------------------------\n";
	cout << "  Select one of the following options number.....\n";
	cout << "  1. Add Student Record\n";
	cout << "  2. View Student Record\n";
	cout << "  3. Delete Student Record\n";
	cout << "  4. Update Student Record\n";
	cout << "  5. Add Teacher Record\n";
	cout << "  6. View Teachers Record\n";
	cout << "  7. Delete Teachers Record\n";
	cout << "  8. Exit!\n";
	cout << "  Enter Option No:   ";
}
void AdminLoginMenu()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	bool login = false;
	string name;
	string pas;
	for (int i = 0; i < 3; i++)
	{
		Header();
		cout << "  Login Menu >\n";
		cout << "  ------------------------------------\n";
		cout << "  Enter Username:   ";
		getline(cin, name);
		cout << "  Enter Password:   ";
		getline(cin, pas);
		if (name == admin_name && pas == admin_pas)
		{
			cout << "  Login Successfully...!";
			sleep(1);
			login = true;
			break;
		}
		else
		{
			if (i < 2)
			{
				cout << "  Wrong username/password...!" << endl;
				sleep(1);
			}
		}
	}
	if (!login)
	{
		cout << "  Too many failed attempts exiting...!\n";
		sleep(2);
		return;
	}
	while (true)
	{
		Header();
		MainMenuAdmin();
		int value;
		cin >> value;
		switch (value)
		{
		case 1:
			AddStudentRecord();
			break;
		case 2:
			ViewStudentRecord();
			break;
		case 3:
			DeleteStudentRecord();
			break;
		case 4:
			UpdateStudentRecord();
			break;
		case 5:
			AddTeacherRecord();
			break;
		case 6:
			ViewTeachersRecord();
			break;
		case 7:
			DeleteTeachersRecord();
			break;
		case 8:
			return;
		default:
			cout << "  Wrong Option...!\n";
			sleep(1);
		}
	}
}
void AddStudentRecord()
{
	Header();
	cout << "  Main Menu > Sub-Menu > AddStudentRecord\n";
	cout << "  -----------------------------------------------\n";
	int choice, a = 1;
	cout << "  How many students you want to enter:   ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = total_students; i < total_students + choice; i++)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > AddStudentRecord\n";
		cout << "  -----------------------------------------------\n";
		cout << "  Personal Details:\n\n";
		if (choice == 1)
		{
			cout << "  Enter Student Name:       ";
			getline(cin, arr_name[i]);
		}
		else
		{
			cout << "  Enter " << a << " Student Name:     ";
			getline(cin, arr_name[i]);
		}
		cout << "  Enter Father Name:        ";
		getline(cin, father_name[i]);
		cout << "  Enter Roll-No:            ";
		cin >> arr_roll_no[i];
		cout << "  Enter Class:              ";
		cin >> arr_class[i];
		cout << "  Enter Contact No:         ";
		cin >> arr_contact[i];
		cout << "  Enter Address:            ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, arr_address[i]);
		cout << "  \n  Login Details:\n\n";
		cout << "  Enter Student Username:   ";
		getline(cin, std_username[i]);
		cout << "  Enter Student Password:   ";
		getline(cin, std_pas[i]);
		a++;
	}
	a = 0;
	total_students += choice;
	StoreStudentRecord();
}
void StoreStudentRecord()
{
	fstream Record(StudentFile, ios::out);
	if (Record.is_open())
	{
		/*	Record << "Name:   "<<"Father Name:   "<<"Roll-No:   "<<"Class:   ";
			Record << "Contact:   "<<"Address:   "<<"Username   "<<"Password"<<endl;	 */
		for (int i = 0; i < total_students; i++)
		{
			Record << arr_name[i] << "," << father_name[i] << "," << arr_roll_no[i] << ",";
			Record << arr_class[i] << "," << arr_contact[i] << "," << arr_address[i] << ",";
			Record << std_username[i] << "," << std_pas[i] << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
string GetField(string line, int field)
{
	int countfield = 1;
	string word = "";
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ',')
		{
			countfield++;
		}
		else if (countfield == field)
		{
			word = word + line[i];
		}
	}
	return word;
}
void ReadStudentRecord()
{
	string line;
	int idx = 0;
	fstream Record(StudentFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{

				arr_name[idx] = GetField(line, 1);
				father_name[idx] = GetField(line, 2);
				arr_roll_no[idx] = stoi(GetField(line, 3));
				arr_class[idx] = stoi(GetField(line, 4));
				arr_contact[idx] = GetField(line, 5);
				arr_address[idx] = GetField(line, 6);
				std_username[idx] = GetField(line, 7);
				std_pas[idx] = GetField(line, 8);
				idx++;
			}
		}
		total_students = idx;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void DeleteStudentRecord()
{
	int loop = 0;
	while (loop < 3)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > DeleteStudentRecord\n";
		cout << "  -----------------------------------------------\n";
		int value, choice;
		cout << "  1. Delete the selected record\n";
		cout << "  2. Delete all records\n";
		cout << "  3. Exit!\n";
		cout << "  Enter Option No:   ";
		cin >> value;
		if (value == 1)
		{
			int choice;
			Header();
			cout << "  Main Menu > Sub-Menu > DeleteStudentRecord\n";
			cout << "  -----------------------------------------------\n";
			cout << "  How many records you want to delete:   ";
			cin >> choice;
			for (int n = 0; n < choice; n++)
			{
				int a = 0;
				bool result = false;
				while (a < 3)
				{
					Header();
					cout << "  Main Menu > Sub-Menu > DeleteStudentRecord\n";
					cout << "  -----------------------------------------------\n";
					if (choice == 1)
					{
						cout << "  Enter Student Roll-No:   ";
					}
					else
					{
						cout << "  Enter " << n + 1 << " Student Roll-No:   ";
					}
					cin >> value;
					for (int i = 0; i < total_students; i++)
					{
						if (arr_roll_no[i] == value)
						{
							result = true;
							for (int j = i; j < total_students - 1; j++)
							{
								arr_name[j] = arr_name[j + 1];
								father_name[j] = father_name[j + 1];
								arr_roll_no[j] = arr_roll_no[j + 1];
								arr_class[j] = arr_class[j + 1];
								arr_contact[j] = arr_contact[j + 1];
								arr_address[j] = arr_address[j + 1];
								std_username[j] = std_username[j + 1];
								std_pas[j] = std_pas[j + 1];
							}
							// after shifting values then clearing last data value
							arr_name[total_students - 1] = "";
							father_name[total_students - 1] = "";
							arr_roll_no[total_students - 1] = 0;
							arr_class[total_students - 1] = 0;
							arr_contact[total_students - 1] = "";
							arr_address[total_students - 1] = "";
							std_username[total_students - 1] = "";
							std_pas[total_students - 1] = "";
							total_students--;
							cout << "  The selected data has been deleted...!\n";
							sleep(1);
							StoreStudentRecord();
							result = true;
							break;
						}
					}
					if (result)
					{
						break;
					}
					else if (a < 2)
					{
						cout << "  Roll-No doesn't exist...!\n";
						sleep(1);
					}
					else if (a == 2)
					{
						cout << "  Too many wrong attempts exiting...!" << endl;
						sleep(2);
						return;
					}
					a++;
				}
			}
			return;
		}
		else if (value == 2)
		{
			for (int j = 0; j < total_students; j++)
			{
				arr_name[j] = "";
				father_name[j] = "";
				arr_roll_no[j] = 0;
				arr_class[j] = 0;
				arr_contact[j] = "";
				arr_address[j] = "";
				std_username[j] = "";
				std_pas[j] = "";
				StoreTeacherRecord();
			}
			return;
		}
		else if (value == 3)
		{
			return;
		}
		else
		{

			if (loop < 2)
			{
				cout << "  Wrong Option...!\n";
				sleep(1);
			}
			else
			{
				cout << "  Too many wrong attempts exiting...!" << endl;
				sleep(2);
				return;
			}
		}
	}
}
void UpdateStudentRecord()
{
	int a = 0;
	while (a < 3)
	{
		bool result = false;
		Header();
		cout << "  Main Menu > Sub-Menu > UpdateStudentRecord\n";
		cout << "  -----------------------------------------------\n";
		int value;
		cout << "  Enter Roll-No which you want to update:   ";
		cin >> value;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (int i = 0; i < total_students; i++)
		{
			if (arr_roll_no[i] == value)
			{
				result = true;
				Header();
				cout << "  Main Menu > Sub-Menu > UpdateStudentRecord\n";
				cout << "  -----------------------------------------------\n";
				cout << "  Personal Details:\n\n";
				cout << "  Enter Student Name:       ";
				getline(cin, arr_name[i]);
				cout << "  Enter Father Name:        ";
				getline(cin, father_name[i]);
				cout << "  Enter Roll-No:            ";
				cin >> arr_roll_no[i];
				cout << "  Enter Class:              ";
				cin >> arr_class[i];
				cout << "  Enter Contact No:         ";
				cin >> arr_contact[i];
				cout << "  Enter Address:            ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, arr_address[i]);
				cout << "  \n  Login Details:\n\n";
				cout << "  Enter Student Username:   ";
				getline(cin, std_username[i]);
				cout << "  Enter Student Password:   ";
				getline(cin, std_pas[i]);
				cout << "  Record has been updated...!";
				sleep(1);
				StoreStudentRecord();
				return;
			}
		}
		if (a < 2)
		{
			if (!result)
			{
				cout << "  Roll-No doesn't exist...!" << endl;
				sleep(1);
			}
		}
		if (a == 2)
		{
			cout << "  Too many wrong attempts exiting...!" << endl;
			sleep(2);
		}
		a++;
	}
}
void ViewStudentRecord()
{
	int a = 0;
	while (a < 3)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > ViewStudentRecord\n";
		cout << "  -----------------------------------------------\n";
		int value;
		bool result = false;
		cout << "  Enter Student Roll-No:   ";
		cin >> value;
		for (int i = 0; i < total_students; i++)
		{
			if (arr_roll_no[i] == value)
			{
				Header();
				cout << "  Main Menu > Sub-Menu > ViewStudentRecord\n";
				cout << "  -----------------------------------------------\n";
				cout << "  Personal Details:\n\n";
				cout << "  Student Name:            " << arr_name[i] << "\n";
				cout << "  Father Name:             " << father_name[i] << "\n";
				cout << "  Roll-No :                " << arr_roll_no[i] << "\n";
				cout << "  Class:                   " << arr_class[i] << "\n";
				cout << "  Contact No:              " << arr_contact[i] << "\n";
				cout << "  Address:                 " << arr_address[i] << "\n\n";
				cout << "  Login Details:\n\n";
				cout << "  Student Username:        " << std_username[i] << "\n";
				cout << "  Student Password:        " << std_pas[i] << "\n\n";
				result = true;
				cout << "  Press any key to exit...!";
				getche();
				return;
			}
		}
		if (a < 2)
		{
			if (!result)
			{
				cout << "  Roll-No doesn't exist...!";
				sleep(1);
			}
		}
		if (a == 2)
		{
			cout << "  Too many wrong attempts exiting...!" << endl;
			sleep(2);
		}
		a++;
	}
}
void AddTeacherRecord()
{
	Header();
	cout << "  Main Menu > Sub-Menu > AddTeacherRecord\n";
	cout << "  -----------------------------------------------\n";
	int choice, a = 1;
	cout << "  How many teachers you want to enter:   ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for (int i = total_teachers; i < total_teachers + choice; i++)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > AddTeacherRecord\n";
		cout << "  -----------------------------------------------\n";
		cout << "  Personal Details:\n\n";
		if (choice == 1)
		{
			cout << "  Enter Teacher Name:       ";
			getline(cin, teacher_name[i]);
		}
		else
		{
			cout << "  Enter " << a << " Teacher Name:     ";
			getline(cin, teacher_name[i]);
		}
		cout << "  Enter Father Name:        ";
		getline(cin, teacher_father_name[i]);
		cout << "  Qualification:            ";
		getline(cin, qualification[i]);
		cout << "  Enter Assign Subject:     ";
		getline(cin, subject[i]);
		cout << "  Enter Contact No:         ";
		cin >> teacher_contact[i];
		cout << "  Enter Address:            ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, teacher_address[i]);
		cout << "  Enter Teacher-ID:         ";
		getline(cin, teacher_id[i]);
		cout << "  \n  Login Details:\n\n";
		cout << "  Enter Teacher Username:   ";
		getline(cin, teacher_username[i]);
		cout << "  Enter Teacher Password:   ";
		getline(cin, teacher_pas[i]);
		a++;
	}
	a = 0;
	total_teachers += choice;
	StoreTeacherRecord();
}
void StoreTeacherRecord()
{
	fstream Record(TeacherFile, ios::out);
	if (Record.is_open())
	{
		/*	Record << "Name:   "<<"Father Name:   "<<"Qualification:   "<<"Assign Subject:   ";
			Record << "Contact:   "<<"Address:   "<<"Teacher ID   "<<"Username   "<<"Password"<<endl; */
		for (int i = 0; i < total_teachers; i++)
		{
			Record << teacher_name[i] << "," << teacher_father_name[i] << "," << qualification[i] << ",";
			Record << subject[i] << "," << teacher_contact[i] << "," << teacher_address[i] << ",";
			Record << teacher_id[i] << "," << teacher_username[i] << "," << teacher_pas[i] << "\n";
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void ReadTeacherRecord()
{
	string line;
	int idx = 0;
	fstream Record(TeacherFile, ios::in);
	if (Record.is_open())
	{
		while (!Record.eof())
		{
			getline(Record, line);
			if (line.empty())
			{
				break;
			}
			else
			{
				teacher_name[idx] = GetField(line, 1);
				teacher_father_name[idx] = GetField(line, 2);
				qualification[idx] = GetField(line, 3);
				subject[idx] = GetField(line, 4);
				teacher_contact[idx] = GetField(line, 5);
				teacher_address[idx] = GetField(line, 6);
				teacher_id[idx] = GetField(line, 7);
				teacher_username[idx] = GetField(line, 8);
				teacher_pas[idx] = GetField(line, 9);
				idx++;
			}
		}
		total_teachers = idx;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	Record.close();
}
void ViewTeachersRecord()
{
	int a = 0;
	Header();
	cout << "  Main Menu > Sub-Menu > ViewTeachersRecord\n";
	cout << "  -----------------------------------------------\n";
	for (int i = 0; i < total_teachers; i++)
	{
		cout << "  " << a + 1 << " Teacher Record:\n\n";
		cout << "  Personal Details:\n\n";
		cout << "  Student Name:            " << teacher_name[i] << "\n";
		cout << "  Father Name:             " << teacher_father_name[i] << "\n";
		cout << "  Qualification:           " << qualification[i] << "\n";
		cout << "  Assign Subject:          " << subject[i] << "\n";
		cout << "  Contact No:              " << teacher_contact[i] << "\n";
		cout << "  Address:                 " << teacher_address[i] << "\n";
		cout << "  Teacher-ID:              " << teacher_id[i] << "\n\n";
		cout << "  Login Details:\n\n";
		cout << "  Student Username:        " << teacher_username[i] << "\n";
		cout << "  Student Password:        " << teacher_pas[i] << "\n\n";
		a++;
	}
	cout << "  Press any key to exit...!" << endl;
	getche();
}
void DeleteTeachersRecord()
{
	int loop = 0;
	while (loop < 3)
	{
		Header();
		cout << "  Main Menu > Sub-Menu > DeleteTeacherRecord\n";
		cout << "  -----------------------------------------------\n";
		int value, choice;
		string id;
		cout << "  1. Delete the selected record\n";
		cout << "  2. Delete all records\n";
		cout << "  3. Exit!\n";
		cout << "  Enter Option No:   ";
		cin >> value;
		if (value == 1)
		{
			int choice;
			Header();
			cout << "  Main Menu > Sub-Menu > DeleteTeacherRecord\n";
			cout << "  -----------------------------------------------\n";
			cout << "  How many records you want to delete:   ";
			cin >> choice;
			for (int n = 0; n < choice; n++)
			{
				int a = 0;
				bool result = false;
				while (a < 3)
				{
					Header();
					cout << "  Main Menu > Sub-Menu > DeleteTeacherRecord\n";
					cout << "  -----------------------------------------------\n";
					if (choice == 1)
					{
						cout << "  Enter Teacher-ID:   ";
					}
					else
					{
						cout << "  Enter " << n + 1 << " Teacher-ID:   ";
					}
					cin >> id;
					for (int i = 0; i < total_teachers; i++)
					{
						if (teacher_id[i] == id)
						{
							result = true;
							for (int j = i; j < total_teachers - 1; j++)
							{
								arr_name[j] = arr_name[j + 1];
								father_name[j] = father_name[j + 1];
								qualification[j] = qualification[j + 1];
								subject[j] = subject[j + 1];
								arr_contact[j] = arr_contact[j + 1];
								arr_address[j] = arr_address[j + 1];
								teacher_id[j] = teacher_id[j + 1];
								std_username[j] = std_username[j + 1];
								std_pas[j] = std_pas[j + 1];
							}
							// after shifting values then clearing last data value
							arr_name[total_teachers - 1] = "";
							father_name[total_teachers - 1] = "";
							qualification[total_teachers - 1] = "";
							subject[total_teachers - 1] = "";
							arr_contact[total_teachers - 1] = "";
							arr_address[total_teachers - 1] = "";
							teacher_id[total_teachers - 1] = "";
							std_username[total_teachers - 1] = "";
							std_pas[total_teachers - 1] = "";
							total_teachers--;
							cout << "  The selected data has been deleted...!\n";
							sleep(1);
							StoreTeacherRecord();
							result = true;
							break;
						}
					}
					if (result)
					{
						break;
					}
					else if (a < 2)
					{

						cout << "  Teacher-ID doesn't exist...!\n";
						sleep(1);
					}
					else if (a == 2)
					{
						cout << "  Too many wrong attempts exiting...!" << endl;
						sleep(2);
						return;
					}
					a++;
				}
			}
			return;
		}
		else if (value == 2)
		{
			for (int j = 0; j < total_teachers; j++)
			{
				arr_name[j] = "";
				father_name[j] = "";
				qualification[j] = "";
				subject[j] = "";
				arr_contact[j] = "";
				arr_address[j] = "";
				teacher_id[j] = "";
				std_username[j] = "";
				std_pas[j] = "";
				StoreTeacherRecord();
			}
			return;
		}
		else if (value == 3)
		{
			return;
		}
		else
		{

			if (loop < 2)
			{
				cout << "  Wrong Option...!\n";
				sleep(1);
			}
			else
			{
				cout << "  Too many wrong attempts exiting...!" << endl;
				sleep(2);
				return;
			}
		}
	}
}
int main()
{
	ReadStudentRecord();
	ReadTeacherRecord();
	ReadMidMarks();
	ReadFinalMarks();
	ReadPresentRecord();
	ReadAbsentRecord();
	int value = 0;
	while (true)
	{
		Header();
		cout << "  Select one of the following options number.....\n";
		cout << "  1. Student Login\n";
		cout << "  2. Teacher Login\n";
		cout << "  3. Admin Login\n";
		cout << "  4. Exit!\n";
		cout << "  Enter Option No:   ";
		cin >> value;
		switch (value)
		{
		case 1:
			StudentLoginMenu();
			break;
		case 2:
			TeacherLoginMenu();
			break;
		case 3:
			AdminLoginMenu();
			break;
		case 4:
			return 0;
		default:
			cout << "Wrong Option...!\n";
			sleep(1);
		}
	}
}