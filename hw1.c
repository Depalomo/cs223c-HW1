// Damon Palomo
// dpalomo@csu.fullerton.edu
// CPSC 223C
// Due date: February 12, 2025 before 2:00am.
// Assignment 1: calculate total volume (ml) between 3 beakers and total percent alcohol

#include <stdio.h>
#include <time.h>

int main() {
float vol1 = 0.0;
float vol2 = 0.0;
float vol3 = 0.0;
float per1 = 0.0;
float per2 = 0.0;
float per3 = 0.0;

printf("Welcome to Modern Chemistry brought to by Chief Software Engineer Damon Palomo\n");

time_t current_linux_time;
 current_linux_time = time(NULL);
struct tm * broken = localtime(&current_linux_time);

const char *ampm;
if(broken->tm_hour < 12) {
    ampm = "am";
} else {
    ampm = "pm";
}

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

printf("Please enter your user name: ");
char user[40];
fgets(user, 40, stdin);

printf("Please enter your title: (Director, Sargent, Ms, Chief, Engineer, Fishmonger, etc): ");
char title[40];
fgets(title, 40, stdin);

printf("Thank you %s %s \n", title, user);
}
