// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    age = 0;

    if(birth_d < 1) {
        birth_d = 1;
    }

    time_t now = time(NULL);
    struct tm nowinfo = *localtime(&now);

    today_y = nowinfo.tm_year + 1900;
    today_m = nowinfo.tm_mon + 1;
    today_d = nowinfo.tm_mday;
    mktime(&nowinfo);
    std::cout << asctime(&nowinfo) << "\n\n" << std::flush;

    struct tm birth_tm = *localtime(&now);
    birth_tm.tm_mday = birth_d;
    birth_tm.tm_mon = birth_m - 1;
    birth_tm.tm_year = birth_y - 1900;
    mktime(&birth_tm);


    if(today_y == birth_y) {
       age = nowinfo.tm_yday - birth_tm.tm_yday;
    } else {
        for(int y = birth_y; y <= today_y; y++) {
            bool is_leap = true;
            if(y % 4 != 0) {
                is_leap = false;
            }

            if(y % 100 == 0 && y % 400 != 0) {
                is_leap = false;
            }

            int days_in_year = is_leap ? 366 : 365;

            if(y == birth_y) {
                age += days_in_year - birth_tm.tm_yday;
            } else if (y == today_y) {
                 age += nowinfo.tm_yday;
            } else {
                age += days_in_year;
            }
        }     
    }


    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
