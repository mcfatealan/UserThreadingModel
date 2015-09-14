#include <stdio.h>
#include "thread.c"

#define MAX 100
int race_var=0; 	//we want to detect the race of this variable

void plain_loop() {for(int i=0;i<10000;i++) for(int j=0;j<10000;j++); }

void thread_singer(int param)
{
	printf("Hi everyone, I'm Dr. Singer!\n");
	
	
	while(1)
	{
		if (race_var < MAX) race_var++;
		
		//sleep(1);	 //We don't use sleep, it would cause a segment fault in our program, using plain loop instead 
		plain_loop();
		if (param) printf("La la la!\n");
		thread_relinquish();	//call this within a thread to allow scheduling of a new thread
		//Actually I'm rather disappointed.. I thought they might use some advanced technique to interrupt threads and switch, wheares they just insert one switch-invoking sentence in it... WTF...
	}
}

void thread_snoozer(int param)
{
	printf("Hi everyone, I'm Dr. Snoozer!\n");

	
	while(1)
	{
		if (race_var < MAX) race_var++;

		//sleep(1);	 
		plain_loop();
		printf("Zz zz zzz!\n");
		thread_relinquish();
	}
}

int main()
{
	thread_manager_init();
	thread_startup_report(); /***********/
	thread_launch( 4000, thread_singer,0);	//set param to 1: sing 0:silence 
	thread_launch( 4000, thread_snoozer,0);

	thread_manager_start();
	
	return 0;
}
