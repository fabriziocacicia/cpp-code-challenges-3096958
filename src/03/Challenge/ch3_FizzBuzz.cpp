// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    // Write your code here
    for(int i = 1; i < n + 1; i++) {
        std::string to_print = "";
        if(i % 3 == 0 && i > 3) {
            to_print.append("Buzz");
        }

        if(i % 5 == 0 && i > 5) {
            to_print.append("Fizz");
        }

        if(to_print.length() == 0) {
            to_print = std::to_string(i);
        }

        std::cout << to_print;
    }
    
    std::cout << std::endl << std::flush;
    return 0;
}
