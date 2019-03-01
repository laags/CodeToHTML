#include <iostream>
#include <regex>
#include "HTMLConverter.h"

using namespace std;

int main() {
    cout <<"   _____          _                 _    _ _______ __  __ _      \n"
           "  / ____|        | |               | |  | |__   __|  \\/  | |     \n"
           " | |     ___   __| | ___   ______  | |__| |  | |  | \\  / | |     \n"
           " | |    / _ \\ / _` |/ _ \\ |______| |  __  |  | |  | |\\/| | |     \n"
           " | |___| (_) | (_| |  __/          | |  | |  | |  | |  | | |____ \n"
           "  \\_____\\___/ \\__,_|\\___|          |_|  |_|  |_|  |_|  |_|______|\n"
           "                                                                 \n" << endl;
    cout <<"+======================================================================+" << endl;

    regex rOne("^[^/\\\\?|><:*\"+,;=\\]\\[]{1,250}\\.(cpp)$"); // Regex for the cpp name
    regex rTwo("^[^/\\\\?|><:*\"+,;=\\]\\[]{1,250}\\.(html)$"); // Regex for the html name

    while(true) {
        // Take inputs for filenames and validate them
        string inFile, outFile;
        cout << "Please enter the input file name (Example:'inputfile.cpp'): " << endl;
        while (true) {
            cin >> inFile;
            if (regex_match(inFile, rOne)) {
                break;
            } else {
                cout << "Try again: " << endl;
                cin.clear();
                cin.ignore();
            }
        }
        cin.ignore();

        cout <<"+======================================================================+" << endl;

        cout << "Please enter the output file name (Example:'outputfile.html'): " << endl;
        while (true) {
            cin >> outFile;
            if (regex_match(outFile, rTwo)) {
                break;
            } else {
                cout << "Try again: " << endl;
                cin.clear();
                cin.ignore();
            }
        }

        cout <<"+======================================================================+" << endl;

        // Convert the file to HTML
        if (HTMLConverter::convert(inFile, outFile))
            cout << "File converted successfully." << endl;

        cout <<"+======================================================================+" << endl;

        // Check if user wants to exit or continue
        cout << "\nType exit to quit or anything else to retry: " << endl;
        string quit;
        cin >> quit;
        if(quit == "exit")
            break;
    }
    return 0;
}