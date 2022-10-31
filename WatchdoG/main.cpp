#include <iostream>		// Include all needed libraries here
#include <wiringPi.h>
#include <unistd.h>
#include <signal.h>

#define ON  1
#define OFF 0

#define PIN0 0
#define PIN1 1

using namespace std;		// No need to keep using “std”

unsigned int  i = 0;

 

//use:
//digitalWrite(PINx, ON);
//digitalWrite(PINx, OFF); 
//digitalRead(PINx);

void sigalarm_handler (int sig)
{
   pwmWrite(PIN1, i);
   i+=40;
   if (i > 1023)
   {
	   i = 0;
   }
}

int main()
{
	wiringPiSetup();		    // Setup the library
	//pinMode(PIN1, OUTPUT);		  // Configure as input
	pinMode(PIN1, PWM_OUTPUT);		  // Configure as input

    cout << "Starting Countdown\n\n";
    signal(SIGALRM, &sigalarm_handler); //ojo es SIGALRM no SIGALARM
    ualarm(100000,100000);  //periodo del timer cada 100useg

    if (fork() == 0) 
	{
	   // Child process will return 0 from fork()
	   printf("Child process will attempt to start dump1090.\n");
	   //status = system("/home/pi/dump1090/dump1090 --interactive");
	   int status = system("/home/pi/dump1090/dump1090");
	   exit(0);
    }
    else 
	{
	   //Start surveillance of pin
	   printf("Starting Battery Surveillance.\n");
    }

	while (1)
	{
		// Button is pressed if digitalRead returns 0
		if (digitalRead(PIN0) == 1)
			system("sudo shutdown -P now");

	}
	return 0;
}