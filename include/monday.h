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
  float temp;
  float result = 0;
  float resultKelvin = 0;
  char conv;
  std::string Text = "";

  
  std::cout << "Please enter the starting temperature: ";
  std::cin >> temp;

  while (cin.fail()) {
    std::cin.clear();
    cin.ignore();
    std::cout << "Not a number please enter a number: ";
    std::cin >> temp;
  }

  std::cout << "Press C to convert Fahrenheit to Celsius" << std::endl;
  std::cout << "Press F to convert Celsius to Fahrenheit" << std::endl;
  std::cin >> conv;

 	switch(conv) {
    case 'C':
	  case 'c':
        result = fahrToCel(temp);
        resultKelvin = celToKel(result);
        printf("Your Choice: %c \n",conv);
        printf("%g fahrenheit is %g degrees  which is the same as %g Kelvin \n", temp, result,resultKelvin);
        break;
    case 'F':
	  case 'f':
        result = celToFahr(temp);
        resultKelvin = celToKel(temp);
        printf("Your Choice: %c \n",conv);
        printf("%g degrees is %g fahrenheit which is the same as %g Kelvin\n", temp, result,resultKelvin);
        break;
    
    
    default:
      printf("Temperature is Not A Char Please Enter C or F\n");
      break;
  }
  
}





void selfServiceCheckout(void) {
	const float tax = 5.5;
  int quantity = 1;
  float item;
  float total = 0;
  int i = 1;
  while (quantity > 0){
    printf("\n Please enter a quantity for item %d (or 0 to finish): ", i);
    std::cin >> quantity;
    if (quantity <= 0) {
      break;
    }
    printf("\n Please enter item %d’s cost: ", i);
    std::cin >> item;
    total += quantity * item;
    i++;
  }

  printf("\n Subtotal %.2f", total);
  printf("\n Tax %.2f \n", total * (tax / 100));
  printf("\n Total %.2f\n", total * ((tax/100) + 1));
}

/*
3 0.99
2 1.5
1 2.99
*/