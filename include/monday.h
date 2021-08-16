#include <iostream> 
using namespace std;

float celToFahr(float cel) {
  return (cel * 9/ 5) + 32;
}
float fahrToCel(float fahr) {
  return (fahr - 32) * 5 / 9;
}

float celToKel(float cel) {
  return cel + 273.15;
}

void fahrenheitCentigradeConversion(void) {
  float Temp;
  float Result = 0;
  float resultKelvin = 0;
  char Conv;
  std::string Text = "";

  
  std::cout << "Please enter the starting temperature: ";
  std::cin >> Temp;

  while (cin.fail()) {
    std::cin.clear();
    cin.ignore();
    std::cout << "Not a number please enter a number: ";
    std::cin >> Temp;
  }

  std::cout << "Press C to convert Fahrenheit to Celsius" << std::endl;
  std::cout << "Press F to convert Celsius to Fahrenheit" << std::endl;
  std::cin >> Conv;

 	switch(Conv) {
    case 'C':
	  case 'c':
        Result = fahrToCel(Temp);
        resultKelvin = celToKel(Result);
        printf("Your Choice: %c \n",Conv);
        printf("%g fahrenheit is %g degrees  which is the same as %g Kelvin \n", Temp, Result,resultKelvin);
        break;
    case 'F':
	  case 'f':
        Result = celToFahr(Temp);
        resultKelvin = celToKel(Temp);
        printf("Your Choice: %c \n",Conv);
        printf("%g degrees is %g fahrenheit which is the same as %g Kelvin\n", Temp, Result,resultKelvin);
        break;
    
    
    default:
      printf("Temperature is Not A Char Please Enter C or F\n");
      break;
  }
  
}





void selfServiceCheckout(void) {
	std::cout << " - selfServiceCheckout: not yet implemented\n\n";
}

