#include <iostream> 
#include <fstream> 
using namespace std;

bool isNumber(string inp);
string* searchRecords(string file,bool phoneNumber, string search);
string* parseFile (string line);

void phoneDirectory(void) {
  string searchInput;
  cout << "\nPlease enter a name or number to search: ";
  getline(cin,searchInput);

  std::string *parsedObj = new string[3];

  parsedObj = searchRecords("include/phonedirectory.csv",isNumber(searchInput), searchInput);
  if (parsedObj[0] == "0"){
    printf("\nSearching %s records \n", parsedObj[2].c_str());
    printf("\nFound No Matches for %s\n",searchInput.c_str());
  }
  else {
    printf("\nSearching %s records \n", parsedObj[2].c_str());
    printf("\nFound %s, Tel: %s \n",parsedObj[0].c_str(),parsedObj[1].c_str());
  }
  
}


void dataFileParser(void) {
	std::cout << " - dataFileParser: not yet implemented\n\n";
}

//-------------------------------------------------------------------

bool isNumber(string searchInput){
  for (std::string::size_type i = 0; i < searchInput.length(); i++){
    if (!isdigit(searchInput[i])) { return false; }
  }
  return true;
}

string* searchRecords(string file,bool phoneNumber, string search){
  string line;
  int counter = 0;
  bool found = false;
  std::string *parsedObj = new string[2];
  std::string *returnObj = new string[3];
  std::ifstream fileObj;
  
  fileObj.open(file);
  if(!fileObj.is_open()) throw std::runtime_error("Could not open file");
  while (!fileObj.eof()){
    getline(fileObj, line);
    counter++;   
    if (phoneNumber && !found){
      parsedObj = parseFile(line);
      if (parsedObj[1] == search){
        found = true;
      }
    }
    else if (!found){
      parsedObj = parseFile(line);
      if (parsedObj[0] == search){
        found = true;
      }
    } 
  }

  fileObj.close();
  if (!found) { 
    returnObj[0] = "0";
    returnObj[1] = "0";

  }
  else {
    returnObj[0] = parsedObj[0];
    returnObj[1] = parsedObj[1];
  }
  returnObj[2] = to_string(counter);
  return returnObj;
}

string* parseFile (string line) {
  int mid = line.find(',');
  std::string *parsedObj = new string[2];
  parsedObj[0] = line.substr(0, mid);
  parsedObj[1] = line.substr(mid + 1, line.length());
  return parsedObj;
}

//-------------------------------------------------------------------
