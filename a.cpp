#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
  printf("hello1\n");

  this_thread::sleep_for(chrono::milliseconds(5000));

  printf("hello2\n");

}

