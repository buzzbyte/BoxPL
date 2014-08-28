// The Box Esoteric Programming Language

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <map>
using namespace std;

#define VERSION "0.2.2"
#define DEBUG 1

string keywords[] = {"Open Box", "Close Box", "pack", "unpack", "unwrap", "makeline"};
int indentVal = 4;

bool startFound = false;
bool endFound = false;

int boxId;
string boxIdStr;
map<string, string> boxvars;

int lineCount = 0;
string inputFilename;

int randomId();

void debug(string dbgtxt) {
	if (DEBUG == 2) {
		cout << " [DEBUG: " << dbgtxt << "] " << endl;
	}
}

void c_err(string errtxt) {
	if (DEBUG >= 1) {
		cerr << "ERROR: " << errtxt << ", at line " << lineCount << " in '" << inputFilename << "'." << endl;
	}
	exit(1);
}


string splitBySpace(string str, int length) {
	string arr[length];
    int i = 0;
    stringstream ssin(str);
    while (ssin.good() && i < length){
        ssin >> arr[i];
        ++i;
    }
    return *arr;
}
// */

int randomId() {
	return rand();
}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void syntaxCheck(string keyword, string line) {
	if (keyword == keywords[2]) {
		// Syntax: pack <{prompt}> {variable}
		string getPackSyntax[] = {line.substr(0,4), // "pack"
								  line.substr(line.find("<")+1, line.find(">")-(line.find("<")+1)), // "{prompt}"
								  line.substr(line.find(">")+2)}; // "{variable}"

		string reqTokens[] = {" <", "> "};
		for (int i = 0; i < sizeof(reqTokens)/sizeof(reqTokens[0]); ++i) {
			if(line.find(reqTokens[i]) == string::npos) {
				c_err("Missing token, '" + reqTokens[i] + "'");
			}
		}
		if(line.find(">")+2 == string::npos) {
			c_err("Missing input variable");
		}
	} else if (keyword == keywords[3]) {
		// Syntax: unpack [{output-text}]
		string reqTokens[] = {" [", "]"};
		for (int i = 0; i < sizeof(reqTokens)/sizeof(reqTokens[0]); ++i) {
			if(line.find(reqTokens[i]) == string::npos) {
				c_err("Missing token, '" + reqTokens[i] + "'");
			}
		}
	} else if (keyword == keywords[4]) {
		// Syntax: unwrap {variable}
		if (line == keyword) {
			c_err("Missing variable");
		}
		if (boxvars.find(line.substr(7)) == boxvars.end()) {
			c_err("Variable '" + line.substr(7) + "' is not defined");
		}
	} else if (keyword == keywords[5]) {
		// Syntax: makeline
		if(line != keyword) {
			c_err("'" + keyword + "' has no parameters");
		}
	}
}

void doCmd(string keyword, string line) {
	//map<string, string> boxvars;
	if (keyword == keywords[2]) {
		///string splitPack[] = {line.substr(0,4), line.substr(6, line.find(">")-6), line.substr(line.find(">")+2)};
		string splitPack[] = {line.substr(0,4), // "pack"
							  line.substr(line.find("<")+1, line.find(">")-(line.find("<")+1)), // "{prompt}"
							  line.substr(line.find(">")+2)}; // "{variable}"
		cout << "[INPUT] " << splitPack[1];
		cin >> boxvars[splitPack[2]];
		debug("Storing input in variable '" + splitPack[2] + "'.");
	} else if (keyword == keywords[3]) {
		string splitUPack[] = {line.substr(0,6), line.substr(line.find("[")+1, line.find("]")-(line.find("[")+1))};
		cout << splitUPack[1];
	} else if (keyword == keywords[4]) {
		string splitUWrap[] = {line.substr(0,6), line.substr(7)};
		cout << boxvars[splitUWrap[1]];
	} else if (keyword == keywords[5]) {
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	if (DEBUG == 2) {
		cout << "[BoxPL Interpreter v" << VERSION << "]" << endl;
	}
	if (argc != 2) {
		if (DEBUG != 2) {
			cout << "[BoxPL Interpreter v" << VERSION << "]" << endl;
		}
		cout << "Usage: " << argv[0] << " <inputfile>" << endl;
		return 0;
	} else {
		ifstream boxFile (argv[1]);
		if (!boxFile.is_open()) {
			if (DEBUG != 2) {
				cout << "[BoxPL Interpreter v" << VERSION << "]" << endl;
			}
			cout << "Error: File cannot be opened. Protip: Check if the file actually exists. ;)" << endl;
			return 1;
		}
		inputFilename = argv[1];
		string fline;
		while(getline(boxFile, fline)) {
			lineCount++;
			//cout << "Reading line: " << lineCount << endl;
			// Review code here...

			for (int i = 0; i < sizeof(keywords)/sizeof(keywords[0]); ++i) {
				/* // Check if there is an unknown keyword:
				if(!fline.find(keywords[i]) == 0) c_err("Undefined keyword in '" + fline + "'.");
				if(!fline.find(keywords[i]) == indentVal) c_err("Undefined keyword in '" + fline.substr(4) + "'.");
				checkExit(); // */

				// Detect keywords:
				if(fline.find(keywords[i]) == 0) debug("Keyword found! " + keywords[i]);

				// Detect indented keywords:
				if(fline.find(keywords[i]) == indentVal) {
					debug("Keyword found! " + keywords[i]);
					syntaxCheck(keywords[i], fline.substr(4));
					doCmd(keywords[i], fline.substr(4));
				}
			}
			if (fline.find(keywords[0]) == 0)
			{
				/*
				startFound = true;
				string splitInit[2];
			    int i = 0;
			    stringstream ssin(fline);
			    while (ssin.good() && i < 3){
			        ssin >> splitInit[i];
			        ++i;
			    } // */
			    //debug(splitInit[2]);
				string splitInit[2] = splitBySpace(fline,2);
				if(!is_number(splitInit[2])) {
					srand((unsigned)time(0));
					boxId = randomId();
				} else {
					boxId = atol(splitInit[2].c_str());
				}// */
				
				stringstream ss;
				ss << boxId;
				ss >> boxIdStr;
				debug("Box ID: " + boxIdStr);
				//cout << boxId << endl;
			}

			if (fline.find(keywords[1]) == 0) {
				endFound = true;
				cout << endl;
				cout << "[Box closed seccessfully]" << endl;
				return 0;
			}

			if(fline.find("#") == 0) continue;

			//lineCount++;
		}
	}
	cout << "Error: Program closed unexpectedly." << endl;
	return 1;
}