// IntArray.cpp
#include "IntArray.h"
#include <iostream>
#include <fstream>

IntArray::IntArray(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    file.close();
}

int IntArray::find(int value) const {
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

int IntArray::modify(int index, int newValue) {
    if (index < 0 || index >= data.size()) {
        std::cerr << "Invalid index provided." << std::endl;
        return -1; // Indicating an error
    }
    int oldValue = data[index];
    data[index] = newValue;
    return oldValue;
}

void IntArray::add(int value) {
    data.push_back(value);
}

void IntArray::modifyOrRemove(int index, bool remove) {
    if (index < 0 || index >= data.size()) {
        std::cerr << "Invalid index provided." << std::endl;
        return;
    }
    if (remove) {
        data.erase(data.begin() + index);
    }
    else {
        data[index] = 0;
    }
}

void IntArray::print() const {
    for (int value : data) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
