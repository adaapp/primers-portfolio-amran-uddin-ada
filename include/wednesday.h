#include <iostream> 
#include <fstream> 
using namespace std;

bool isNumber(string inp);
std::vector<string> searchRecords(string file,bool phoneNumber, string search);
std::vector<string> parseFile (string line);

void phoneDirectory(void) {
  string searchInput;
  cout << "\nPlease enter a name or number to search: ";
  getline(cin,searchInput);

  std::vector<std::string> parsedObj;

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
  std::vector<std::string> parsedObj;
  std::ifstream fileObj;
  std::string line;
  std::string initial;

  printf("\n|%-7s|%-10s|%-7s|\n", "-------","----------","-------");
	printf("|%-7s|%-10s|%-7s|\n", "Initial","Last","Salary");
  printf("|%-7s|%-10s|%-7s|\n", "-------","----------","-------");

  fileObj.open("include/employeesalary.csv");
  if(!fileObj.is_open()) throw std::runtime_error("Could not open file");
  while (!fileObj.eof()){
    getline(fileObj, line);
    parsedObj = parseFile(line);
    initial = parsedObj[0].substr(0, 1) + ".";
    printf("|%-7s|%-10s|£%-6s|\n", initial.c_str(),parsedObj[1].c_str(),parsedObj[2].c_str());
  }
  fileObj.close();
  printf("|%-7s|%-10s|%-7s|\n", "-------","----------","-------");
}

//------------|------------|------------|------------|------------|-------

bool isNumber(string searchInput){
  for (std::string::size_type i = 0; i < searchInput.length(); i++){
    if (!isdigit(searchInput[i])) { return false; }
  }
  return true;
}

std::vector<string> searchRecords(string file,bool phoneNumber, string search){
  string line;
  int counter = 0;
  bool found = false;
  std::vector<std::string> parsedObj;
  std::ifstream fileObj;
  
  fileObj.open(file);
  if(!fileObj.is_open()) throw std::runtime_error("Could not open file");
  while (!fileObj.eof() && !found){
    getline(fileObj, line);
    counter++;   
    if (phoneNumber){
      parsedObj = parseFile(line);
      if (parsedObj[1] == search){
        found = true;
      }
    }
    else {
      parsedObj = parseFile(line);
      if (parsedObj[0] == search){
        found = true;
      }
    } 
  }

  fileObj.close();
  if (!found) { 
    parsedObj[0] = "0";
    parsedObj[1] = "0";

  }
  parsedObj.push_back(to_string(counter));
  return parsedObj;
}
// Switched to vectors so parsefile works well with p6 as well
std::vector<string> parseFile (string line) {
  int mid = line.find(',');
  std::vector<std::string> parsedObj;
  int start = 0;
  for (std::string::size_type i = 0; i < line.length(); i++){
    if (line[i] == ','){
      parsedObj.push_back(line.substr(start, i - start)); // star to length
      start = i + 1;
    }
  }
  parsedObj.push_back(line.substr(start, line.length()));
  return parsedObj;
}

//------------|------------|------------|------------|------------|-------
