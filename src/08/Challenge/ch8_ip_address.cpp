// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){

    // Write your code here
    std::vector<std::string> parts;
    std::string part = "";

    // Add a dot at the end to store a part into parts after every dot
    ip += '.';
    for(int i = 0; i < ip.length(); i++) {
        if(ip[i] != '.') {
            // If there is some character that is not a number the IP is not valid
            // Subtrating the '0' char means converting the integer value of the character int its actual numeric value
            if(ip[i] - '0' < 0 || ip[i] - '0' > 9) {
                return false;
            }

            part += ip[i];
        } else {
            parts.push_back(part);
            part = "";
        }
    }

    bool is_valid = true;

    // If the IP is not made by 4 parts is not valid
    if(parts.size() != 4) {
        return false;
    }

    for(auto & p : parts) {
        int num = stoi(p);

        if(num < 0 || num > 255) {
            return false;
        }
    }


    return is_valid;
}

// Main function
int main(){
    std::string s;
    
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
