#define _CRT_SECURE_NO_WARNINGS
#include "includes.h"
#include "Main_Menu.h"
#include "Crash_Menu.h"


using namespace std;



int main()
{
	system("mode con cols=80 lines=20");
	SetConsoleTitleA(">> RAISE X <<");
	setlocale(LC_ALL, "ru");
	srand(time(0));
	
	
	UserInformation Person;

	AuthMenu();
	
	//CrashMenu();

	//MainMenu();







}


