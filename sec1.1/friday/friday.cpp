/*
	ID: erkam.u1
	PROG: friday
	LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
Is Friday the 13th really an unusual event?

That is, does the 13th of the month land on a Friday less often than on any other day of the week? To answer this question, write a program that will compute the frequency that the 13th of each month lands on Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given period of N years. The time period to test will be from January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. N is positive and will not exceed 400.

Note that the start year is NINETEEN HUNDRED, not 1990.

There are few facts you need to know before you can solve this problem:

January 1, 1900 was on a Monday.
Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
*/
int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    string result;
    int n;
    fin >> n;
    // Jan 13, 1990 was Saturday
    // weeks are in mod7, starts from 0 til 6
    int weekday = 0;
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekdays[] = {0, 0, 0, 0, 0, 0, 0};
    // add number of days in current month to get the 13th of the next month
    for (int i = 1900; i < 1900+n; ++i){
        for (int j = 0; j < 12; ++j){
            weekdays[weekday]++;
            // check leap year
            if(j==1 && ((i%100 != 0 && i%4 == 0) || (i%400 == 0))){
                weekday += 29;
            }
            else{
                weekday += months[j];
            }
            weekday %= 7;
        }
    }
    for(int i = 0; i < 6; ++i){
        fout << weekdays[i] << " ";
    }

    fout << weekdays[6] << endl;
    return 0;
}
