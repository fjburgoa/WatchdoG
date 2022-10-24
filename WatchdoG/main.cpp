#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>

using namespace std;		// No need to keep using “std”

int  i = 1;

int main()
{
	wiringPiSetup();		// Setup the library
	pinMode(i, OUTPUT);		// Configure GPIO0 as an output
	//pinMode(1, INPUT);		// Configure GPIO1 as an input

	while (1)
	{
		// Button is pressed if digitalRead returns 0
		//if (digitalRead(1) == 1)
		//{
			// Toggle the LED
		cout << i << "\n";
		//digitalWrite(0, !digitalRead(0));
		digitalWrite(i, 1);
		delay(200); 	// Delay 500ms
		digitalWrite(i, 0);
		delay(200); 	// Delay 500ms
		//i++;
		//if (i > 15)
		//	i = 0;

		//}
	}
	return 0;
}