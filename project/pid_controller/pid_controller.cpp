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
  
  prev_cte = 0.0;
  int_cte = 0.0;
  delta_time = 1.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  if (delta_time == 0){
    diff_cte = 0;
  }
  else{
    diff_cte = (cte - prev_cte) / delta_time;
  }
  prev_cte = cte;
  int_cte += cte * delta_time;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  	double control = Kp*prev_cte + Kd*diff_cte/delta_time + Ki*int_cte;

  	
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
}