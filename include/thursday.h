#include <iostream>
#include <thread>
using namespace std;

void sleepDuration(int seconds = 10);
void timer1();
void timer2();
int t1Duration = 5;
int t2Duration = 10;


void sleepTimer(void) {
  cout << "sleepTimer: Calling sleep function with thread Id: " <<std::this_thread::get_id() <<"\n";
  sleepDuration();
  printf("sleepTimer: Sleep Timer Finished");
}

void sleepDuration(int seconds){
  std::this_thread::sleep_for(std::chrono::milliseconds(seconds*1000));
}

void joinDetachThreads(void) {
  cout << "Main Thread: " <<std::this_thread::get_id() <<" started\n";
  std::thread thread1(&timer1);
  std::thread thread2(&timer2);
  thread1.join(); // makes main thread wait for this to finish first
  thread2.join(); // before main thread can continue
  cout << "Main Thread: " <<std::this_thread::get_id() <<" ended\n";
}


void timer1(){
  cout << "Thread 1: " <<std::this_thread::get_id() <<" started\n";
  sleepDuration(t1Duration);
  cout << "Thread 1: " <<std::this_thread::get_id() <<" ended\n";

}
void timer2(){
  cout << "Thread 2: " <<std::this_thread::get_id() <<" started\n";
  sleepDuration(t2Duration);
  cout << "Thread 2: " <<std::this_thread::get_id() <<" ended\n";
}