#pragma once
#include "includes.h"
#include "Menu_Functions.h"
#include "Auth_Functions.h"
#include "Vars.h"
#include "Crash_Menu.h"


using namespace std;



class UserInformation {

public:
	string UserName;
	string UserPassword;
	string UserBalance = "10";

};


bool Password_Database(UserInformation Person) {



	string DefaulPasswords[] = {

		"12345678",
		"87654321",
		"12344321",
		"12341234",
		"88888888",
		"11111111",

	};

	bool isUnique = false;

	for (int i = 0; i < 6; i++)
	{
		if (Person.UserPassword == DefaulPasswords[i])
		{
			isUnique = true;
		}
		else if (isUnique != true)
			isUnique = false;
	}

	return isUnique;

}

int PasswordValid(UserInformation Person) {


	if (Person.UserPassword.length() < 8)
		return 0;

	else if (Password_Database(Person) == true)
		return 1;

	else if (Password_Database(Person) == false)
		return 2;


}

bool Auth_Register(UserInformation Person) {

	int x = 2;
	int y = 1;

	gotoxy(x, y);
	cout << YourName;
	SetColor(LightGreen, Black);
	gotoxy(YourName.length() + x + 1, y);
	
	getline(cin, Person.UserName);

	system("cls");
	SetColor(White, Black);

	gotoxy(x, y);
	cout << YourPassword;
	SetColor(LightGreen, Black);

	gotoxy(YourPassword.length() + x + 1, y);
	cin >> Person.UserPassword;

	SetColor(White, Black);

	gotoxy(0, 0);
	SetColor(LightRed, Black);
	Frame();
	gotoxy(3, 2);

	if (PasswordValid(Person) == 0) {
		cout << LengthError;
		Sleep(1700);
		return false;
	}
	else if (PasswordValid(Person) == 1) {
		
		cout << SimplyError;
		Sleep(1700);
		return false;
	}	
	else if (PasswordValid(Person) == 2) {
		gotoxy(0, 0);
		SetColor(LightGreen, Black);
		Frame();
		gotoxy(3, 2);
		cout << Registered;
		replace(Person.UserName.begin(), Person.UserName.end(), ' ', '_');
		ofstream File("Users//" + Person.UserName + ".txt", ios::app);
		File << Person.UserPassword << "\n";
		File << Person.UserName << "\n";
		File << Person.UserBalance;
		Sleep(1700);
		File.close();
		return true;
	}
	
	SetColor(White, Black);
	system("cls");
	

}

bool Auth_Login(UserInformation Person) {

	system("cls");

	int x = 2;
	int y = 1;

	gotoxy(x, y);
	cout << YourName;
	SetColor(LightRed, Black);
	gotoxy(YourName.length() + x + 1, y);
	
	getline(cin, Person.UserName);
	
	replace(Person.UserName.begin(), Person.UserName.end(), ' ', '_');
	ifstream User("Users//" + Person.UserName + ".txt");


	system("cls");
	SetColor(White, Black);
	if (User.is_open()) {

		string TempPass;
		int x = 2;
		int y = 1;

		gotoxy(x, y);
		cout << YourPassword << endl;
		SetColor(LightRed, Black);
		gotoxy(YourPassword.length() + x + 1, y);
		cin >> Person.UserPassword;

		SetColor(White, Black);


		while (getline(User, TempPass))
		{
			if (TempPass == Person.UserPassword)
			{
				gotoxy(x, y);
				SetColor(LightGreen, Black);
				Frame();
				gotoxy(2, 2);
				cout << LoggedIn;
				Sleep(1200);
				system("cls");
				SetColor(White, Black);
				return true;
			}
		
		}

	}
	else
	{
		int x = 0;
		int y = 0;

		gotoxy(x, y);
		SetColor(LightRed, Black);
		Frame();
		gotoxy(2, 2);
		cout << NotRegistered;
		Sleep(1200);
		system("cls");
		SetColor(White, Black);
		return false;
			
	}

	system("cls");
	
}

void MainMenu(UserInformation Person) {


	char** menuItem = new char* [3];
	menuItem[0] = new char[] {">> Crash  <<"};
	menuItem[1] = new char[] {">> Double <<"};
	menuItem[2] = new char[] {">> Exit   <<"};

	do
	{
		
		Frame();
		int choice = vertical_menu(
			menuItem, 
			HORIZONTAL_POSITION::CENTER,
			VERTICAL_POSITION::CENTER,
			ALLIGNMENT::LEFT
		);
	
		switch (choice)
		{
		case 0:
			
			break;
		case 1:
			
			break;
		case 2:
			exit(0);
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			
		default:
			break;
		}
	} while (true);
	ClearMemory(menuItem);



}

double Start(UserInformation Person, double UserCrash, double crash, double bet) {

	system("cls");
	int x = CenterText();
	int y = 2;




	crash = RandomCrash();
	double newBet = bet;
	gotoxy(8, 9);

	string Balance = Person.UserBalance;
	string UserName = Person.UserName;
	double newBalance;
	

	bool isCrash = false;
	while (isCrash == false)
	{
		for (double i = 1.00; i != crash; i += 0.01)
		{

			gotoxy(x, y);

			SetColor(White, ColorI(i));
			cout << "x";
			cout << i;

			SetColor(White, Black);
			gotoxy(7, 6);
			cout << "  " << bet << "\t   " << newBet * i;

			BetPrint();


			if (crash <= i)
				break;

			if (i >= UserCrash && crash >= UserCrash)
			{
				string newBalance;
				newBalance += newBet - bet;

				ofstream User("Users//" + UserName + ".txt");

				User << newBalance << endl;
				User.close();
				return 1;
			}


			Sleep(100);
			system("cls");

		}
		GameCrashed(crash);
		system("pause");
		
		return newBalance = stoi(Balance) - bet;

	}


}

void CrashMenu(UserInformation Person) {

	double UserCrash(0.00);
	double crash(0.00);
	double bet(stoi(Person.UserBalance));
	double newBet(0.00);
	
	

	char** CrashMenuItem = new char* [3];
	CrashMenuItem[0] = new char[] {">>    Bet    <<"};
	CrashMenuItem[1] = new char[] {">>   Crash   <<"};
	CrashMenuItem[2] = new char[] {">>   Start   <<"};

	do
	{

		Frame();
		int choice = vertical_menu(
			CrashMenuItem,
			HORIZONTAL_POSITION::CENTER,
			VERTICAL_POSITION::CENTER,
			ALLIGNMENT::LEFT
		);

		switch (choice)
		{
		case 0:
			break;
		case 1:
			UserCrash = UserCrashMenu(UserCrash);
			break;
		case 2:
			newBet = Start(Person, UserCrash, crash, bet);
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:


		default:
			break;
		}
	} while (true);
	ClearMemory(CrashMenuItem);

}

void AuthMenu() {

	UserInformation Person;


	bool SuccessLogin = false;
	bool SuccessReg = false;

	char** menuItem = new char* [3];
	menuItem[0] = new char[] {">>    Auth    <<"};
	menuItem[1] = new char[] {">>  Register  <<"};
	menuItem[2] = new char[] {">>    Exit    <<"};

	do
	{

		int option = vertical_menu(
			menuItem,
			HORIZONTAL_POSITION::CENTER,
			VERTICAL_POSITION::CENTER,
			ALLIGNMENT::LEFT
		);

		switch (option)
		{
		case 0:
			SuccessLogin = Auth_Login(Person);
			if (SuccessLogin)
				CrashMenu(Person);
			else
				exit(0);
		case 1:
			SuccessReg = Auth_Register(Person);
			if (SuccessReg)
				CrashMenu(Person);
			else
				exit(0);
			break;
		case 2:
			exit(0);
			break;
		}
	} while (true);
	ClearMemory(menuItem);

}


