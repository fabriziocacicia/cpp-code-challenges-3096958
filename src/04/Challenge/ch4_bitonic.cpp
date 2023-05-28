// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>
#include <utility>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.
bool is_bitonic(const std::vector<int> &v){
    
    // Write your code here
    bool is_bitonic = true;

    bool partial_const = true;
    bool partial_asc = v[0] <= v[1];
    bool partial_desc = v[0] >= v[1];
    int n_pivot = 0;
    

    for(int i = 1; i < v.size() - 1; i++) {
        if(partial_asc && v[i] > v[i+1]) {
            n_pivot++;
            partial_asc = false;
            partial_desc = true;
        }

        if(partial_desc && v[i] < v[i+1]) {
            n_pivot++;
            partial_desc = false;
            partial_asc = true;
        }

        if(n_pivot > 2) {
            return false;
        }
    }

    if(n_pivot == 2) {
        if(partial_asc) {
            return v.back() <= v.front();
        }

        if(partial_desc) {
            return v.back() >= v.front();
        }
    }

    return is_bitonic;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    // std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    // std::vector<int> myvec = {1, 1, 1, 1, 1};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 2};  // Yes
    // std::vector<int> myvec = {3, 4, 5, 2, 4};  // No
    // std::vector<int> myvec = {1, 2, 3, 4, 5};  // Yes
    // std::vector<int> myvec = {1, 2, 3, 1, 2};  // No
    // std::vector<int> myvec = {5, 4, 6, 2, 6};  // No
    // std::vector<int> myvec = {5, 4, 3, 2, 1};  // Yes
    // std::vector<int> myvec = {5, 4, 3, 2, 6};  // Yes
    // std::vector<int> myvec = {5, 4, 6, 5, 4};  // No
    // std::vector<int> myvec = {5, 4, 6, 5, 5};  // Yes
    std::vector<std::pair<std::vector<int>, bool>> myVectors = {
        {{1, 2, 5, 4, 3}, true},
        {{1, 1, 1, 1, 1}, true},
        {{3, 4, 5, 2, 2}, true},
        {{3, 4, 5, 2, 4}, false},
        {{1, 2, 3, 4, 5}, true},
        {{1, 2, 3, 1, 2}, false},
        {{5, 4, 6, 2, 6}, false},
        {{5, 4, 3, 2, 1}, true},
        {{5, 4, 3, 2, 6}, true},
        {{5, 4, 6, 5, 4}, false},
        {{5, 4, 6, 5, 5}, true},
    };

    for(const auto & vec : myVectors) {
        std::cout << (is_bitonic(vec.first) == vec.second ? "Correct" : "Wrong");
        std::cout << std::endl << std::endl << std::flush;
    }
    return 0;
}
