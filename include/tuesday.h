#include <iostream> 
using namespace std;
int complexityChecker(string inputPassword) {
  int alpha = 0;
  int numeric = 0;
  int special = 0;
  int passSize = inputPassword.size(); // £ extended ascii character counts as two characters

  for (std::string::size_type i = 0; i < passSize; ++i){

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
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}
