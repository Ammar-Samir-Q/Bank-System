#include <iostream>
#include "Header Files/clsLoginScreen.h"
using namespace std;
int main()
{
	//Username : User1
	//Password : 1234
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
}

