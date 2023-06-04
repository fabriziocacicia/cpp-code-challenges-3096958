// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::getline(std::cin, try_again);
    do{

        // Write your code here
        const int wait_delay = 4 + (rand() % 7);
        const auto wait_delay_in_seconds = std::chrono::seconds(wait_delay);

        const auto waiting_start_time = std::chrono::steady_clock::now();
        while(std::chrono::steady_clock::now() - waiting_start_time < wait_delay_in_seconds) {
            continue;
        }
        
        const int WRITING_DELAY = 2;
        const auto writing_delay_in_seconds = std::chrono::seconds(WRITING_DELAY);
        const auto writing_start_time = std::chrono::steady_clock::now();

        std::cout << "Type a 3-letter word: \n" << std::flush;
        std::string word;
        std::getline(std::cin, word);

        const bool fast_enough = std::chrono::steady_clock::now() - writing_start_time < writing_delay_in_seconds;

        // Make the word uppercase
        for(int i = 0; i < word.length(); i++) {
            word[i] = toupper(word[i]);
        }
        
        const bool correct_word = std::find(begin(words), end(words), word) != end(words);
        
        if(!word.empty()) {
            if(fast_enough && correct_word) {
                std::cout << "Success!\n" << std::flush;
            } else {
                std::cout << "Failure!\n" << std::flush;
            }
            return 0;
        }
        

        std::cout << "Try again? (Y/N): " << std::flush;
        std::getline(std::cin, try_again);
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
