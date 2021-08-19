#include <iostream> 
#include <fstream> 
using namespace std;

bool isNumber(string inp);
std::vector<string> searchRecords(string file,bool phoneNumber, string search);
std::vector<string> parseFile (string line);
string repeatNTimes(int repeat,string val);
std::vector<std::vector<std::string>> parsed2dObjfunction(string file);
std::string removeWhitespace(string data);
std::vector<std::string> removeVectorSpace(std::vector<std::string> vectorData);

void phoneDirectory(void) {
  string searchInput;
  cout << "\nPlease enter a name or number to search: ";
  getline(cin,searchInput);

  std::vector<std::string> parsedObj;
  parsedObj = searchRecords("include/phonedirectory.csv",isNumber(removeWhitespace(searchInput)), searchInput);
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
  std::vector<std::vector<std::string>> parsed2dObj;
  std::string initial;

  parsed2dObj = parsed2dObjfunction("include/employeesalary.csv");
  int maxLast = stoi(parsed2dObj[parsed2dObj.size() - 1][1]); // last element reserved for max values
  int maxSalary = stoi(parsed2dObj[parsed2dObj.size() - 1][2]);

  string lastDash = repeatNTimes(maxLast,"-");
  string salaryDash = repeatNTimes(maxSalary + 1,"-"); //make up for the £

  printf("\n|%-7s|%-*s|%-*s|\n", "-------", maxLast,lastDash.c_str(), maxSalary,salaryDash.c_str());
	printf("|%-7s|%-*s|%-*s|\n", "Initial", maxLast,"Last", maxSalary + 1,"Salary");
  printf("|%-7s|%-*s|%-*s|\n", "-------", maxLast,lastDash.c_str(), maxSalary,salaryDash.c_str());

  for(std::vector<std::vector<std::string>>::size_type i = 0; i != parsed2dObj.size() - 1; i++) {
    initial = parsed2dObj[i][0].substr(0, 1) + ".";
    printf("|%-7s|%-*s|£%-*s|\n", initial.c_str(), maxLast,parsed2dObj[i][1].c_str(), maxSalary,parsed2dObj[i][2].c_str());
  }
  printf("|%-7s|%-*s|%-*s|\n", "-------", maxLast,lastDash.c_str(), maxSalary,salaryDash.c_str());
}
//------------|------------|------------|------------|------------|
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
      if (parsedObj[1] == removeWhitespace(search)){
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
//------------|------------|------------|------------|------------|
string repeatNTimes(int repeat,string val){
  string repeated = "";
  for (int i =0;i < repeat;i++){
    repeated += val;
  }
  return repeated;
}

std::vector<std::vector<std::string>> parsed2dObjfunction(string file){
  std::vector<std::string> parsedObj;
  std::vector<std::vector<std::string>> parsed2dObj;
  std::ifstream fileObj;
  std::string line;
  int initial = 7;
  int maxLast = 4;
  int maxSalary = 5;

  fileObj.open(file);
  if(!fileObj.is_open()) throw std::runtime_error("Could not open file");
  while (!fileObj.eof()){
    getline(fileObj, line);
    parsedObj = removeVectorSpace(parseFile(line));
    parsed2dObj.push_back(parsedObj);
    if (parsedObj[1].length() > maxLast){
      maxLast = parsedObj[1].length();
    }
    if (parsedObj[2].length() > maxSalary){
      maxSalary = parsedObj[2].length();
    }
  }
  fileObj.close();
  maxSalary++;
  maxLast++;
  // send max lengths at the end of records
  parsedObj[0] = (to_string(initial));
  parsedObj[1] = (to_string(maxLast));
  parsedObj[2] = (to_string(maxSalary));
  parsed2dObj.push_back(parsedObj);
  return parsed2dObj;
};
//------------|------------|------------|------------|------------|
std::string removeWhitespace(string data){
  data.erase(std::remove(data.begin(),data.end(),' '),data.end());
  return data;
}

std::vector<std::string> removeVectorSpace(std::vector<std::string> vectorData){
  vectorData[0] = removeWhitespace(vectorData[0]);
  vectorData[1] = removeWhitespace(vectorData[1]);
  vectorData[2] = removeWhitespace(vectorData[2]);
  return vectorData;
}