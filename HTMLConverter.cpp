#include <iostream>
#include <sstream>
#include "HTMLConverter.h"

using namespace std;

// Custom exception for writing/replacing text
struct HTMLConverter::writeExcept : public exception
{
    const char * what () const throw () {
        return "Unable to write to HTML file.";
    }
};

HTMLConverter::HTMLConverter() {}

// Walks over file character by character, replacing what needs to be replaced
void HTMLConverter::replaceChar(ifstream& inStream, ofstream& outStream )
{
    try {
        outStream << "<PRE>" << endl;
        char next;
        inStream.get(next);
        while (!inStream.eof()) {
            if (next == '<')
                outStream << "&lt;";
            else if (next == '>')
                outStream << "&gt;";
            else
                outStream << next;
            inStream.get(next);
        }
        outStream << "</PRE>" << endl;
    }catch(...){
    writeExcept writeExcept;
    throw writeExcept;
    }
}

// Function that reads in source and outputs it to HTML
bool HTMLConverter::convert(string inPath, string outPath)
{
    ifstream fin;
    ofstream fout;
    string filePath = inPath;
    string outputPath = outPath;

    // Open the input file
    try {
        fin.open(inPath); //input file (must in the same folder)
    }catch(...){ cout << "Unknown exception" << endl; }
    if (fin.fail()) {
        cout << "Unable to open input file: '" << inPath << "'." << endl;
        return false;
    }

    // Open/Create the output file
    try {
        fout.open(outputPath); //output file (in the same folder)
    }catch(...){ cout << "Unknown exception" << endl; }
    if (fout.fail()) {
        cout << "Creating file '" << outputPath << "' failed.";
        return false;
    }

    // Write Tags and converted text to HTML file
    try {
        replaceChar(fin, fout);
    }catch(writeExcept& e ){ cout << e.what() << endl;}
    catch(...){}

    // Close the files
    try {
        fin.close();
        fout.close();
    }catch(ifstream::failure e){ cout << "Unable to close files." << endl;}
    catch(...){ cout << "Unknown exception" << endl; }

    // Returns true if was successful
    return true;
}