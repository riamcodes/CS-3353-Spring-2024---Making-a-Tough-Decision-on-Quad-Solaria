#include <vector>
#include "Stuff3.h"

// you should modify the code for this one
// you can also change the parameters.
// If you do that. make sure you change that for the call from Decision1()
pair<bool, Stuff3> DecisionRecur1(vector<Stuff3>& vec, int firstElement, int lastElement)
{
    //Base Case: if length 1 return whatever element contained as potential majority
// you can change this line if you decide to change the parameters for DecisionRecur1
    if (firstElement == lastElement){
        return {true, vec[firstElement]};
    }
// Find the middle
    int middleElement = firstElement + (lastElement - firstElement)/2;

//Recursive search for majority element in either half
    pair<bool, Stuff3>  leftSide = DecisionRecur1(vec, firstElement, middleElement);
    pair<bool, Stuff3>  rightSide = DecisionRecur1(vec, middleElement + 1 , lastElement);
//If both halves have same majority element, return the element
    if (leftSide.first && rightSide.first && leftSide.second == rightSide.second){
        return rightSide;
    }
//If one side has a majority, check its validity over the entire segment
    //handle right side first
    int rightCount = 0;
    for (int i = firstElement; i <= lastElement; i++){
        if (rightSide.first && vec[i] == rightSide.second){
            rightCount++;
        }
    }
    if (rightCount > (lastElement - firstElement + 1)/ 2) {
        rightSide.first = true;
        return {rightSide.first, rightSide.second};
    }
    //handle left
    int leftCount = 0;
    for (int i = firstElement; i <= lastElement; i++){
        if (leftSide.first && vec[i] == leftSide.second){
            leftCount++;
        }
    }
    if (leftCount > (lastElement - firstElement + 1)/ 2) {
        leftSide.first = true;
        return {leftSide.first, leftSide.second};
    }
    //If not majority is found or its invalid return false
    return {false, Stuff3()};
}

pair<bool, Stuff3> Decision1(vector<Stuff3>& vec)
{
    // you can change this line if you decide to change the parameters for DecisionRecur1
    if (vec.empty()) return {false, Stuff3()};
    return DecisionRecur1(vec, 0, vec.size() - 1);
}

//---------------------------------------------------------------------------------------------------------
// Recursive function to determine if there is a majority element
pair<bool, Stuff3> DecisionRecur2(vector<Stuff3>& vec, vector<Stuff3>& consecutivePairs, Stuff3 extraOne) {
    // Check if the size of consecutivePairs is 0 or 1, which are the base cases
    if (consecutivePairs.size() <= 1) {
        // Initialize possibleMajority with extraOne by default
        Stuff3 possibleMajority = extraOne;
        // If there is one element, it becomes the new possibleMajority
        if (consecutivePairs.size() == 1) {
            possibleMajority = consecutivePairs.at(0);
        }
        // Initialize count to keep track of how many times possibleMajority appears in vec
        int count = 0;
        // Iterate over vec to count occurrences of possibleMajority
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == possibleMajority) {
                count++;
            }
        }
        // Check if the possibleMajority appears more than half the size of vec
        if (count > vec.size() / 2) {
            return {true, possibleMajority}; // Majority found
        } else {
            return {false, vec[0]}; // No majority found
        }
    }
// Prepare a new vector to hold pairs of consecutive elements that are the same
    vector<Stuff3> newConsecutivePairs;
// Iterate through consecutivePairs in steps of 2
    for (int i = 0; i < consecutivePairs.size() - 1; i += 2) {
        if (consecutivePairs.at(i) == consecutivePairs.at(i + 1)) {
            newConsecutivePairs.push_back(consecutivePairs.at(i));
        }
    }
    // Handle the case where the size of consecutivePairs is odd
    // The last element can be considered an excess element
    Stuff3 finalElement = extraOne;
    if (consecutivePairs.size() % 2 != 0) {
        finalElement = consecutivePairs.at(consecutivePairs.size() - 1);
    }
    // Recurse with the new vector of pairs and the last unpaired element if any
    return DecisionRecur2(vec, newConsecutivePairs, finalElement);
}
// Function to kickstart the recursive decision-making process
pair<bool, Stuff3> Decision2(vector<Stuff3>& vec) {
    if (vec.empty()) {
        return {false, vec[0]}; // Handle empty vector case
    }
    // Initial extra element, possibly a default-constructed Stuff3 object
    Stuff3 extraOne;
    // Create a copy of vec to be used as consecutivePairs for recursion
    vector<Stuff3> consecutivePairs = vec;
    // Start recursion with the full vector
    return DecisionRecur2(vec, consecutivePairs, extraOne);
}


//NOTE: BOYER MOORE FUNCTION VERSION OF DECISION2 BELOW
//UNCOMMENT FOR POTENTIAL BETTER RUN TIME
// the issue is that it doesn't really make true pairs and the recursion is a kind of fake recursion which it does not need to run so I did not choose it as my main submission method
//It does have a better run time though

//-------------------------------
//// Recursive function to reduce the vector by forming pairs
//pair<bool, Stuff3> DecisionRecur2(vector<Stuff3>& vec, Stuff3 candidate, int count, int start) {
//    if (start >= vec.size()) {
//        // If we've processed the entire vector, return the result of the majority vote
//        if (count > 0) {  // If count is positive, candidate is the majority element
//            int total = 0;
//            for (auto& item : vec) {
//                if (item == candidate) total++;
//            }
//            if (total > vec.size() / 2) {
//                return {true, candidate};
//            }
//        }
//        return {false, Stuff3()};
//    }
//
//    // Form pairs
//    if (count == 0) {
//        // If count is zero, select the next candidate
//        candidate = vec[start];
//        count = 1;
//    } else if (vec[start] == candidate) {
//        // If we find the candidate, increase the count
//        count++;
//    } else {
//        // If we find a different element, decrease the count
//        count--;
//    }
//
//    // Recursively call the function with the next index
//    return DecisionRecur2(vec, candidate, count, start + 1);
//}
//
////
//pair<bool, Stuff3> Decision2(vector<Stuff3>& vec) {
//    if (vec.empty()) {
//        return {false, Stuff3()};  // Handle the empty vector case
//    }
//
//    // Initial call to the recursive function with the first element as a candidate
//    return DecisionRecur2(vec, vec[0], 0, 0);
//}