#include <iostream> 
using namespace std;
int complexityChecker(string inputPassword) {
  int alpha = 0;
  int numeric = 0;
  int special = 0;
  int passSize = inputPassword.size();
  for (std::string::size_type i = 0; i < passSize; ++i){
    if(isalpha(inputPassword[i])){
      alpha++;
    }
    else if(isdigit(inputPassword[i])){
      numeric++;
    }
    else{
      special++;
    }
  }
}

void passwordComplexityChecker(void) {
	std::string inputPassword;
  cin >> inputPassword;
  complexityChecker(inputPassword)
  printf("The password is '%s' \n",inputPassword,);
}


void employeeListRemoval(void) {
	std::cout << " - employeeListRemoval: not yet implemented\n\n";
}
