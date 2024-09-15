#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void reverseFileContent(const std::string& inputFileName, const std::string& outputFileName) {
    // Open the input file
    std::ifstream inFile(inputFileName);

    // Check if the input file is open
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open the input file!" << std::endl;
        return;
    }

    // Read the entire file content into a string
    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

    // Close the input file
    inFile.close();

    // Reverse the content string
    std::reverse(content.begin(), content.end());

    // Open the output file
    std::ofstream outFile(outputFileName);

    // Check if the output file is open
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the output file!" << std::endl;
        return;
    }

    // Write the reversed content to the output file
    outFile << content;

    // Close the output file
    outFile.close();

    std::cout << "Reversed content saved to " << outputFileName << " successfully." << std::endl;
}

int main() {
    // Declare the file name
    std::string fileName = "CSC450_CT5_mod5.txt";
    std::string reverseFileName = "CSC450-mod5-reverse.txt";

    // Create an output file stream object
    std::ofstream outFile(fileName, std::ios::app); // appending to the file

    // Check if the file is open
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    // Get input from the user
    std::string userInput;
    std::cout << "Enter text to store in the file. " << std::endl;
    std::cout << "Type 'reverse' to create a file to reverse all text" << std::endl;
    std::cout << "Type 'exit' to Exit" << std::endl;

    // Loop to get user input until they type 'exit'
    while (true) {
        std::getline(std::cin, userInput);

        // Exit condition
        if (userInput == "exit") {
            break;
        } else if (userInput == "reverse") {
            // Call the method to reverse file content
            reverseFileContent(fileName, reverseFileName);
        }

        // Write the input to the file
        outFile << userInput << std::endl;
    }

    // Close the file
    outFile.close();
    std::cout << "Data saved to " << fileName << " successfully." << std::endl;

    return 0;
}