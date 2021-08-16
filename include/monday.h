#include <iostream> 
using namespace std;

float celtoFahr(float cel) {
  return (cel * 9/ 5) + 32;
}
float FahrtoCel(float fahr) {
  return (fahr - 32) * 5 / 9;
}

void fahrenheitCentigradeConversion(void) {
  float Temp;
  float Result = 0;
  char Conv;
  std::string Text = "";

  
  std::cout << "Please enter the starting temperature: ";
  std::cin >> Temp;

  std::cout << "Press C to convert Fahrenheit to Celsius" << std::endl;
  std::cout << "Press F to convert Celsius to Fahrenheit" << std::endl;
  std::cin >> Conv;
 	switch(Conv) {
    case 'C':
	  case 'c':
        Result = FahrtoCel(Temp);
        printf("Your Choice: %c \n",Conv);
        printf("%g fahrenheit is %g degrees", Temp, Result);
        break;
    case 'F':
	  case 'f':
        Result = celtoFahr(Temp);
        printf("Your Choice: %c \n",Conv);
        printf("%g degrees is %g fahrenheit \n", Temp, Result);
        break;
    default:
      printf("Temperature is Not A Char Please Enter C or F\n");
      break;
  }
  
}





void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

