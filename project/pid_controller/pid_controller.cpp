/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  Kp = Kpi;
  Ki = Kii;
  Kd = Kdi;
  
  Output_Max_Lim = output_lim_maxi;
  Output_Min_Lim = output_lim_mini;
  
  p_error = 0.0;
  d_error = 0.0;
  i_error = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if (delta_time == 0){
    d_error = 0;
  }
  else{
    d_error = (cte - p_error) / delta_time;
  }
  p_error = cte;
  i_error += cte * delta_time;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  	double control = Kp*p_error + Kd*d_error + Ki*i_error;

  	
  	if (control > Output_Max_Lim){
      control = Output_Max_Lim;
    }
  	else if (control < Output_Min_Lim){
      control = Output_Min_Lim;
      }
  
    return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
  	delta_time = new_delta_time;
  return delta_time;
}