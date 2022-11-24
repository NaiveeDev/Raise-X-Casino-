#include "includes.h"
#include "Menu_Functions.h" 
#include "Main_Menu.h" 
#include "Crash_Menu.h" 
#include "Vars.h" 
 

double UserCrashMenu(double& UserCrash);

void BetPrint() {

	gotoxy(6, 7);
	cout << "IN ROUND";

	SetColor(LightBlue, Black);
	cout << " " << ((char)26) << " ";

	SetColor(White, Black);
	cout << "WITHDRAW";


	

}

int ColorI(double i) {

	if (i <= 1.19) {
	
		return 4;
	}
	else if (i >= 1.20 && i <= 1.99) {
		return 3;
	}
	else if (i >= 2.00 && i <= 3.99) {

		return 5;
	}
	else if (i >= 4.00 && i <= 7.99)
	{
		return 10;
	}

}

double CrashRange(string Color) {

	srand(time(NULL));


	if (Color == "Red")
	{
		int MinValue = 1;
		int MaxValue = 19;

		int random = rand() % (MaxValue - MinValue + 1) + MinValue;
		return (double)random / 100;

	}
	else if (Color == "Blue")
	{
		int MinValue = 20;
		int MaxValue = 99;

		int random = rand() % (MaxValue - MinValue + 1) + MinValue;
		return (double)random / 100;
	}
	else if (Color == "Purple")
	{
		int MinValue = 1;
		int MaxValue = 99;

		int random = rand() % (MaxValue - MinValue + 1) + MinValue;
		return (double)random / 100;
	}
	else if (Color == "Green")
	{
		int MinValue = 1;
		int MaxValue = 99;

		int random = rand() % (3 - 2 + 1) + 2;
		return (double)random / 100;
	}

}

int CrashColor() {
	
	// подробнее в readme

	srand(time(NULL));
	int MinValue = 1;
	int MaxValue = 8;
	

	int arr[8] = { 0,0,1,2,2,2,2,3 };

	int random = rand() % (MaxValue - MinValue + 1) + MinValue;
	return arr[random];
}

double RandomCrash() {

	double crash(0.00);

	int ColorInt = CrashColor();

	switch (ColorInt)
	{
	case 0:
		return crash = 1.00;
	case 1:
		crash++;
		return crash += CrashRange("Red");
	case 2:
		crash++;
		return crash += CrashRange("Blue");
	case 3:
		int random = rand() % (3 - 2 + 1) + 2;
		crash = CrashRange("Purple");
		return crash += random;

	}


}

void GameCrashed(double crash) {

	int x = CenterText();
	int y = 2;
	
	system("cls");

	SetColor(White, Black);
	gotoxy(x-4, y);
	SetColor(LightRed, Black);
	cout << "CRASH x" << crash << endl;
	gotoxy(x, y-5);
	SetColor(Black, Black);
}


double CustomCrash(double & UserCrash) {

	system("cls");
	Frame();
	int x = 2;
	int y = 2;

	gotoxy(x, y);
	cout << TypeCrash;

	gotoxy(TypeCrash.length() + x + 1, y);
	SetColor(Red, Black);
	cin >> UserCrash;

	SetColor(White, Black);
	
	if (cin.good())
	{
		SetColor(LightGreen, Black);
		Frame();
		gotoxy(x, y);
		cout << SuccessInput;
		Sleep(1300);
		SetColor(White, Black);
		system("cls");
		return UserCrash;
	}
	else 
	{
		
		SetColor(Red, Black);
		cin.clear();
		cin.ignore(100000, '\n');
		Frame();
		gotoxy(x, y);
		cout << InvalidInput;
		Sleep(1300);
		SetColor(White, Black);
		CustomCrash(UserCrash);
		
	}
	

	

}

double UserCrashMenu(double &UserCrash) {

	char** UserCrashItem = new char* [5];
	UserCrashItem[0] = new char[] {">> x1.10  <<"};
	UserCrashItem[1] = new char[] {">> x1.20  <<"};
	UserCrashItem[2] = new char[] {">> x1.50  <<"};
	UserCrashItem[3] = new char[] {">> x2.00  <<"};
	UserCrashItem[4] = new char[] {">> Custom <<"};

	do
	{

		Frame();
		int choice = vertical_menu(
			UserCrashItem,
			HORIZONTAL_POSITION::CENTER,
			VERTICAL_POSITION::CENTER,
			ALLIGNMENT::LEFT
		);

		switch (choice)
		{
		case 0:
			return UserCrash = 1.10;
			break;
		case 1:
			return UserCrash = 1.20;
			break;
		case 2:
			return UserCrash = 1.50;
			break;
		case 3:
			return UserCrash = 2.00;
			break;
		case 4:
			return CustomCrash(UserCrash);
			break;
		case 5:
			
			break;
		case 6:


		default:
			break;
		}
	} while (true);
	ClearMemory(UserCrashItem);

}