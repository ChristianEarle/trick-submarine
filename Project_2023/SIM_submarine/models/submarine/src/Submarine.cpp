/*********************************************************************
  PURPOSE: ( Trick numeric )
*********************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "trick/integrator_c_intf.h"
#include "../include/Submarine.hh"

int Submarine::submarine_control(){
	pump_power = pump_power_command;
	if (pump_power > 5000.0) pump_power = 5000.0;
	if (pump_power < -5000.0) pump_power = -5000.0;
	return(0);
}
int Submarine::submarine_deriv(){
	//for calculations
	water_pressure_pascals = DENSITY_SALT_WATER * -GRAVITY * (-pos[1]) + ATMOS_PRESSURE;//Water Pressure Pascals
	ballast_air_volume = ballast_energy / water_pressure_pascals; //Volume of Ballast Air
	//Recalculation if air value is impossible
	if (ballast_air_volume < 0){
		ballast_air_volume = 0;
		ballast_energy = 0;
		}
	if (ballast_air_volume > ballast_tank_volume){
		ballast_air_volume = ballast_tank_volume;
		ballast_energy = ballast_air_volume * water_pressure_pascals;
		}
	if (pos[1] >= outer_hull_outer_radius) { //Volume of Hull Displacement logic
		hull_disp_volume = 0;
		}
	if ((pos[1] < outer_hull_outer_radius) && (pos[1] > -outer_hull_outer_radius)) {
		hull_disp_volume = hull_volume / (1 + exp(-5.5 * -pos[1]));
		}
	if (pos[1] <= -outer_hull_outer_radius) {
		hull_disp_volume = hull_volume;
		}
	ballast_water_volume = ballast_tank_volume - ballast_air_volume; //Volume of Ballast Water
	mass_ballast_water = ballast_water_volume * DENSITY_SALT_WATER; //Mass of Ballast Water
	mass_total = payload_mass + hull_mass + hard_ballast_mass + mass_ballast_water; //Mass Total
	mass_total_disp = (hull_disp_volume + ballast_air_volume) * DENSITY_SALT_WATER; //Mass of Total Displacement
	A = 2 * outer_hull_outer_radius * hull_length; //Cross Sectional Area
	bouy_force = mass_total_disp * GRAVITY; //Force of Bouyancy
	drag_force = (-0.5) * DENSITY_SALT_WATER * vel[1] * abs(vel[1]) * Cd * A; //Force of Drag
	gravity_force = -GRAVITY * mass_total; //Force of Gravity (weight)
	total_force = gravity_force + bouy_force + drag_force; //Total Force
	acc[1] = total_force / mass_total; //acceleration in y direction
	
	//for GUI
	water_pressure_PSI = water_pressure_pascals * CONVERSION_PASCALS_TO_PSI; //Water Pressure PSI
	ballast_air_ratio = ballast_air_volume / ballast_tank_volume; //Ballast Air Ratio
  return 0;
}

int Submarine::submarine_integ(){
  int ipass;

  load_state(
	     &pos[0],
	     &pos[1],
	     &vel[0],
	     &vel[1],
	     &ballast_energy,	
	     NULL);
  load_deriv(
	     &vel[0],
	     &vel[1],
	     &acc[0],
	     &acc[1],
	     &pump_power,
	     NULL);

  ipass = integrate();

  unload_state(
	       &pos[0],
	       &pos[1],
	       &vel[0],
	       &vel[1],
	       &ballast_energy,
	       NULL);
  return(ipass);
}
