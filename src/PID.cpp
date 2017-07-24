#include "PID.h"
#include <iostream>
#include <thread>
#include <math.h>
using namespace std;

#define DEBUG_PRINT (0)

/*
* PID with fixed coefficient values
*/




PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  //Initialize values
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0;
  i_error = 0;
  d_error = 0;


  std::cout << "Initialized" << std::endl;

}

void PID::UpdateError(double cte) {

    // I error
    i_error += cte;

    // D error
    d_error = (cte - p_error);

    // P error , normalized per step
    p_error = cte;

    if (DEBUG_PRINT){
      std::cout << "d_error" << d_error << std::endl;
      std::cout << "p_error" << p_error << std::endl;
      std::cout << "i_error" << i_error << std::endl;
    }

}


double PID::TotalError() {

  double totalerror =  (Kp*p_error + Ki*i_error + Kd*d_error);
  std::cout << "Total Error: " << totalerror << std::endl;
  return totalerror;
}