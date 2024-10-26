// Submitted by
// Abu Obaida Zishan
// Please note that this code was developed in an Ubuntu machine
// might not work in Windows

#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

unsigned int ONE_SECOND = 1000000;
bool led_state = false;

// please configure this port from Arduino IDE (IDE>TOOLS>PORT)
void sendData(string command)
{
  std::string port = "/dev/ttyACM0";
  
  // Write to the port
  {
    std::ofstream ard(port); // open the device in write mode
    usleep(ONE_SECOND);
    if (ard)
    {
      ard << command << '\n'; // send the command
    }
    else
    {
      cout << "Error: Could not open port for writing" << endl;
      return;
    }
  } // `ofstream` is closed here when it goes out of scope
  
  usleep(ONE_SECOND); // wait a bit before reading

  // Read from the port
  {
    std::ifstream ard(port); // open the device in read mode
    if (ard)
    {
      string response;
      while (getline(ard, response)) // read response line by line
      {
        cout << response << endl;
      }
    }
    else
    {
      cout << "Error: Could not open port for reading" << endl;
    }
  } // `ifstream` is closed here when it goes out of scope
}

int main()
{
  while (1)
  {
    sendData("H");
    usleep(ONE_SECOND);
  }
  return 0;
}
