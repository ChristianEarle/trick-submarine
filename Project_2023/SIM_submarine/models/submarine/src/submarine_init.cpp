/******************************* TRICK HEADER ****************************
PURPOSE: (Set the initial data values)
*************************************************************************/

/* Model Include files */
#include <math.h>
#include <cstdlib>
#include "../include/Submarine.hh"

/* default data job */
int Submarine::submarine_default_data(){
	outer_hull_outer_radius = 1.3; //meters
	outer_hull_inner_radius = 1.25; //meters
	inner_hull_outer_radius = 1.10; //meters
	inner_hull_inner_radius = 1.00; //meters
	hull_length = 3.0; //meters
	ballast_tank_volume = 1.0; //cubic meters
	hard_ballast_mass = 0.0; //kg
	hull_mass = 10000.0; //kg
	payload_mass = 1500.0; //kg
	Cd = 0.5; //kg
	pos[0] = 0.0; //meters x-direction
	pos[1] = 0.0; //meters y-direction
	vel[0] = 0.0; //mps x-direction
	vel[1] = 0.0; //mps y-direction
	ballast_energy = (ballast_tank_volume/2) * ATMOS_PRESSURE;
	hull_volume = M_PI * hull_length * inner_hull_outer_radius * inner_hull_outer_radius;
return 0;
}

int Submarine::submarine_init(){
	 //Volume of Hull
return 0;
}
