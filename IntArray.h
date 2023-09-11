// IntArray.h

#pragma once
#include <vector>
#include <string>

class IntArray {
private:
    std::vector<int> data;

public:
    // Constructor: Reads data from the file into the array
    IntArray(const std::string& filePath);

    // Function to check if a certain integer exists in the array.
    // Returns the index if found, otherwise returns -1.
    int find(int value) const;

    // Function to modify the value of an integer at a given index.
    // Returns the old value.
    int modify(int index, int newValue);

    // Function to add a new integer to the end of the array.
    void add(int value);

    // Function to either set the value at a given index to 0 or remove the integer.
    void modifyOrRemove(int index, bool remove);

    // Function to print the current contents of the array (useful for demonstration)
    void print() const;
};
