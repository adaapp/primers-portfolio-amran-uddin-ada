class car {     // The class
  private:
    string colour;
    string make;
    bool engine;
    bool lockedStatus;

  public:           // Access specifier
    car(string init_colour, string init_make, bool init_engine, bool init_lockedStatus) {     // Constructor
      colour =  init_colour;
      make = init_make;
      engine = init_engine;
      lockedStatus = init_lockedStatus;
    }
    void set_colour(string set_colour) { colour = set_colour; }
    string get_colour(void) { return colour; }
    void set_make(string set_make) { make = set_make; }
    string get_make(void) { return make;}

    void engine_on(void) {
      engine ? printf("Sorry, Engine is already on") : printf("Turning the engine on");
      engine = true; 
    }

    void engine_off(void) { 
      engine ? printf("Turning off the engine") : printf("Sorry, Engine is already off");
      engine = false;
    }

    void locked(bool status) {
      if(status){
          lockedStatus ? printf("Sorry, the car is already locked") : printf("Locking the car");
      }
      else if(!status){
          lockedStatus ? printf("Unlocking the car") : printf("Sorry the car is already unlocked");
      }
      lockedStatus = status;
    }

    void status(void) {
      string engine_value;
      string locked_value;
      engine_value = engine ? "On" : "Off";
      locked_value = lockedStatus ? "Locked" : "Unlocked";
      printf("\n\nCar Status: colour:%s, make %s,engine:%s, %s",colour.c_str(),make.c_str(),engine_value.c_str(),locked_value.c_str());
    }
};


class AreaOf {
  float width;
  float height;
  float top;
  public:
    AreaOf(){
    };
    ~AreaOf(){
    }
    //overloaded methods
    float size(float width) {
      return width * width;
    }
    float size(float width, float height) {
      return width * height;
    }
    float size(float width, float height,float top){
      return 0.5 * (width + top) * height;
    }
};


void carClass(void) {
    bool loop = true;
    int choice;
		std::cout << "\nCar Class";
    car golf("black","polo",true,true);
    while (loop){
      golf.status();
      printf("\n1. Turn Engine On\n2. Turn Engine Off\n3. Lock Car\n4. Unlock Car\nPlease select an option (or 0 to finish): ");
      cin >> choice;
      switch (choice) {
        case 0:
          loop = false;
          printf("\nYou have chosen to exit the car class Goodbye");
          break;
        case 1:
          golf.engine_on();
          break;
        case 2:
          golf.engine_off();
          break;
        case 3:
          golf.locked(true);
          break;
        case 4:
          golf.locked(false);
          break;
        default:
          printf("Not Valid Option");
      }
    }
}


void areaOf(void) {
  
		std::cout << " - areaOf: not yet implemented\n\n";
    AreaOf square;
    AreaOf rectangle;
    AreaOf trapezium;
    printf("\nArea of square(5): %g",square.size(5));
    printf("\nArea of rectangle(5): %g",square.size(5,10));
    printf("\nArea of trapezium(5): %g",square.size(14,8,6));
    

}