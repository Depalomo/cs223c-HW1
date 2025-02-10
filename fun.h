#ifndef FUN_H
#define FUN_H

#include <time.h>
#include <stdio.h>

void clearInput() {
  while (getchar() != '\n');
}

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

//determine the month name from an array by using month number as index.
const char* month;
const char* months[] = {
  "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
};
month = months[broken->tm_mon];

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

void handling(int *input_handle, double *number) {
while (*input_handle != 1) {
  printf("Invalid! Please try again: ");
  clearInput();
  *input_handle = scanf("%lf", number);
}
clearInput();
}

#endif