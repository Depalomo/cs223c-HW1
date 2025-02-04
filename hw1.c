// Damon Palomo
// dpalomo@csu.fullerton.edu
// CPSC 223C
// Due date: February 12, 2025 before 2:00am.
// Assignment 1: calculate total volume (ml) between 3 beakers and total percent alcohol

#include <stdio.h>
#include <time.h>
#include <string.h>

void PrintTime() {
//get local time.
time_t current_linux_time;
 current_linux_time = time(NULL);
struct tm * broken = localtime(&current_linux_time);

//determine if am or pm.
const char *ampm = (broken->tm_hour < 12) ? "am" : "pm";
if(broken->tm_hour > 12) {
        broken->tm_hour -=12;
}

//determine the month name.
const char *month;
switch(broken->tm_mon + 1) {
    case 1: month = "January";
            break;
    case 2: month = "February";
            break;
    case 3: month = "March";
            break;
    case 4: month = "April";
            break;
    case 5: month = "May";
            break;
    case 6: month = "June";
            break;
    case 7: month = "July";
            break;
    case 8: month = "August";
            break;
    case 9: month = "September";
            break;
    case 10: month = "October";
            break;
    case 11: month = "November";
            break;
    case 12: month = "December";
            break;
}

//display time.
 if(broken == NULL)
     printf("A call to function localtime failed.\n");
 else
     printf("The time is now %04d %s %02d @ %02d:%02d%s\n",
             broken->tm_year+1900,
             month,
             broken->tm_mday,
             broken->tm_hour,
             broken->tm_min, 
             ampm); 
}

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

//total_volume, alc_amt
double total_volume;
double alc_amt = 0.0;
double volume = 0;
double percent = 0;
for (int count = 1; count < 4; count++) {
 //get the volume(ml) and percent alcohol of each beaker from student.
 printf("Please enter the volume(ml) of the liquid in beaker #%d: ", count);
 scanf("%lf", &volume);
 total_volume += volume;
 printf("Please enter the percent of alcohol in beaker #%d as decimal fraction: ", count);
 scanf("%lf", &percent);
  // make sure the user inputs a decimal fraction.
 while(percent > 1) {
  printf("Please enter as a decimal fraction: ");
  scanf("%lf", &percent);
 }
 // calculate volume of alcohol.
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
return 0;

}
