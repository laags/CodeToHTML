#ifndef ASSIGNMENT4_HTMLCONVERTER_H
#define ASSIGNMENT4_HTMLCONVERTER_H


#include <string>
#include <fstream>

class HTMLConverter {
public:
    HTMLConverter(); // Default Constructor
    static void replaceChar(std::ifstream& inStream, std::ofstream& outStream); // Text replacing routine
    struct writeExcept; // Write exception
    static bool convert(std::string inPath, std::string outPath); // Main Converting function
};


#endif //ASSIGNMENT4_HTMLCONVERTER_H
