#include <iostream> 
using namespace std;

int complexityChecker(string inputPassword);
int complexityReturner(int PassSize, int alpha, int numeric, int special);
void printEmployees(string employees[],int sizeArray);

void passwordComplexityChecker(void) {
	std::string inputPassword;
  int complexity = 0;
  printf("\nEnter Password: ");
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
  bool foundFlag = false;
  string deleteChoice = "";
  string employees[6] = {"John Smith","Jaelynn Smith","Kaley Barajas","Walter Collier","Kaley Barajas","Cale Myers"};
  int sizeArray = sizeof(employees)/sizeof(employees[0]);

  printf("\nList of Employees");
  printEmployees(employees,sizeArray);
  printf("\nDelete Choice: ");
  getline(cin,deleteChoice);

  

  for (int i = 0; i < sizeArray + 1; i++){
    if (employees[i] == deleteChoice) {
      for (int j = i+1; j < sizeArray; j++){ // shift everything left overwrite chosen delete
        employees[j-1] = employees[j];
      }

      employees[sizeArray -1] = ""; // last two values would be duplicated - make empty
      foundFlag = true;
    }
  }
  if ( foundFlag ){ 
    printf("\n--New List of Employees--");
    printEmployees(employees,sizeArray);
    return; 
  }
  printf("\nNo one in the list named %s",deleteChoice.c_str());
  printEmployees(employees,sizeArray);
  return;
  
}

int complexityChecker(string inputPassword) {
  int alpha = 0;
  int numeric = 0;
  int special = 0;
  int passSize = inputPassword.length(); // some utf chars count as two

  for (std::string::size_type i = 0; i < passSize; i++){

    if(isalpha(inputPassword[i])){ alpha++; }
    else if(isdigit(inputPassword[i])) { numeric++; }
    else{ special++; }

  }

  return complexityReturner(passSize, alpha, numeric, special);
}

int complexityReturner(int passSize, int alpha, int numeric, int special) {

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
    printf("\n%s",employees[i].c_str());
  }
}

/*
TODO:
Make print emplyees return array with deleted choice so is pure
is case sensitive
printf??
size() counts £ as 2 char(bytes) length() 1 char
  - function cchecker calls creturner decided to split into two functions
  do two diff things once counts types of chars
  second uses data of types of chars to make judgement
*/
