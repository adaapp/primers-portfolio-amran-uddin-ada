#include <iostream>
#include <thread>
using namespace std;

void sleepDuration(int seconds);

void sleepTimer(void) {
  cout << "sleepTimer: Calling sleep function with thread Id: " <<std::this_thread::get_id() <<"\n";
  sleepDuration(10);
  cout <<  "sleepTimer: Sleep Timer Finished";
}


void joinDetachThreads(void) {
	std::cout << " - joinDetachThreads: not yet implemented\n\n";
}

void sleepDuration(int seconds){
  cout << "sleepDuration: Putting to sleep Thread: " <<std::this_thread::get_id() <<" for " << seconds << " seconds\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000));
  cout << "sleepDuration: Function finished\n";

}