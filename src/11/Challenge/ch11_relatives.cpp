// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    std::string line;
    if(file.is_open()){

        // Write your code here
        getline(file, line);
    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // Write your code here
    std::vector<std::vector<std::string>> people;

    std::stringstream ssLine(line);
    std::string person;

    while(getline(ssLine, person, ',')) {
        std::stringstream ssPerson(person);
        std::string s;
        std::vector<std::string> personNames;
        while(getline(ssPerson, s, ' ')) {
            personNames.push_back(s);
        }

        for(auto & p : people) {
            if(p[1] == personNames[1]) {
                std::cout << personNames[0] << " " << personNames[1] << " could be relative to " << p[0] << " " << p[1] << "\n" << std::flush;
                return 0;
            }
        }

        people.push_back(personNames);
    }

    std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 