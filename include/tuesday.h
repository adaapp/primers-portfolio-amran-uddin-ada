#include <iostream> 
using namespace std;

int complexityChecker(string inputPassword);
void printEmployees(string employees[],int sizeArray);

void passwordComplexityChecker(void) {
	std::string inputPassword;
  int complexity = 0;
  cout << "Enter Password: ";
  getline(cin,inputPassword); // get line allows for spaces opposed to just cin
  complexity = complexityChecker(inputPassword);

  switch (complexity) {
    case 1:
      printf("The password is '%s' and is Weak \n", inputPassword.c_str());
      break;
    case 2:
      printf("The password is '%s' Moderate \n", inputPassword.c_str());
      break;
    case 3:
      printf("The password is '%s' Strong \n", inputPassword.c_str());
      break;
    case 4:
      printf("The password is '%s' Very Strong \n", inputPassword.c_str());
      break;
  }
}

void employeeListRemoval(void) {
  string deleteChoice = "";
  string employees[5] = {"John Smith","Jaelynn Smith","Kaley Barajas","Walter Collier","Cale Myers"};
  int sizeArray = sizeof(employees)/sizeof(employees[0]);

  std::cout << "\nList of Employees";
  printEmployees(employees,sizeArray);
  std::cout << "\nDelete Choice: ";
  getline(cin,deleteChoice);

  

  for (int i = 0; i < sizeArray + 1; i++){
    if (employees[i] == deleteChoice) {
      for (int j = i+1; j < sizeArray; j++){ // shift everything left overwrite chosen delete
        employees[j-1] = employees[j];
      }

      employees[sizeArray -1] = ""; // last two values would be duplicated - make empty
      cout << "\n" << "--New List of Employees--";
      printEmployees(employees,sizeArray);
      return;
    }
  }
  cout << "\n" << "No one in the list named " << deleteChoice;
  printEmployees(employees,sizeArray);
  return;
  
}

int complexityChecker(string inputPassword) {
  int alpha = 0;
  int numeric = 0;
  int special = 0;
  int passSize = inputPassword.size(); // £ extended ascii character counts as two characters

  for (std::string::size_type i = 0; i < passSize; i++){

    if(isalpha(inputPassword[i])){ alpha++; }
    else if(isdigit(inputPassword[i])) { numeric++; }
    else{ special++; }

  }

  if (passSize >= 8 && numeric >=2 && alpha >= 4){
    if (special >=1 ) {
      return 4;
    } // difference between very strong and strong is the special char
    return 3;
  }

  else {
    int counter = 0;
    // for moderate result need at least two to be true
    if (numeric >= 1) { counter++; }
    if (alpha >= 1) { counter++; }
    if (special >= 1) { counter++; }

    if (passSize >= 4 && counter >=2){ // needs at least size>=4 and more than 1 type of char
      return 2;
    }
    return 1;
  }
}

void printEmployees(string employees[],int sizeArray){
  for (int i = 0; i < sizeArray; i++){
    if (employees[i] == "") { return; }
    cout << "\n" << employees[i];
  }
}

/*
TODO:
Make print emplyees return array with deleted choice so is pure
is case sensitive
printf??
*/
