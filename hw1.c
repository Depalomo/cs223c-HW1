// Damon Palomo
// CWID: 885521658
// dpalomo@csu.fullerton.edu
// CPSC 223C
// Due date: February 12, 2025 before 2:00am.
// Assignment 1: Calculate total volume (ml) between 3 beakers and total percent alcohol.
// Use the input output functions to communicate with the user and request inputs. Use the
// time functions to output formatted time to the terminal. Use functions defined in header
// to handle any user-end typos.

#include "fun.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {

printf("Welcome to Modern Chemistry brought to by Chief Software Engineer Damon Palomo\n");

//display date and time.
PrintTime();

//get users name.
printf("Please enter your user name: ");
char user[40];
fgets(user, 40, stdin);

//get users title and remove endline character.
printf("Please enter your title: (Director, Sargent, Ms, Chief, Engineer, Fishmonger, etc): ");
char title[40];
fgets(title, 40, stdin);
title[strcspn(title, "\n")] = '\0';

//redisplay user inputs.
printf("Thank you %s %s", title, user);

double total_volume;
double alc_amt = 0.0;
double volume = 0;
double percent = 0;
int input_return = 0;                                // If input is invalid return value of scanf() != 1

for (int count = 1; count < 4; count++) {

 //get the volume(ml) and percent alcohol of each beaker from student.
 printf("Please enter the volume(ml) of the liquid in beaker #%d: ", count);
 input_return = scanf("%lf", &volume);
 //handle if user does not input a double.
 handling(&input_return, &volume);
 printf("volume entered: %.3lf\n", volume);

 //add volume of current beaker to total.
 total_volume += volume;
 
//does the same as previous but instead taking in percent alcohol.
 printf("Please enter the percent of alcohol in beaker #%d as decimal fraction: ", count);
 input_return = scanf("%lf", &percent);
 handling(&input_return, &percent);

 // make sure the user inputs a decimal fraction.
 while(0 > percent || percent > 1) {
        printf("Must be between 0.00 and 1.00: ");
        input_return = scanf("%lf", &percent);
        handling(&input_return, &percent);
       }
 printf("percent entered: %.3lf\n", percent);

 // calculate volume of alcohol by summing the product of each input.
 alc_amt += (volume * percent);
}

//calculate alcohol percentage
alc_amt = (alc_amt / total_volume);

printf("The final beaker contains %.2f ml of fluid of which contains %.3f%% alcohol.\n", total_volume, 100 * alc_amt);

 //print the date and time again.
 PrintTime();

//print time since the last epoch.
time_t epoch = time(NULL);
printf("The time since the epoch is %lu seconds.\n", epoch);

//farewell message
printf("Have a good day %s %s", title, user);

//return 0
printf("A zero will be retunred to the operating system.\n");

printf("====End of execution ===================================\n");
return 0;



}
