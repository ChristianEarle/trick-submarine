%module mba48123e2b0720fbeeb8ad0d8bd89ec1

%include "trick/swig/trick_swig.i"


%insert("begin") %{
#include <Python.h>
#include <cstddef>
%}

%{
#include "/home/caci114/Project_2023/SIM_submarine/models/submarine/include/Submarine.hh"
%}

%trick_swig_class_typemap(Submarine, Submarine)



#ifndef SUBMARINE_HH
#define SUBMARINE_HH


#define DENSITY_SALT_WATER 1023.6

#define GRAVITY 9.80665

#define CONVERSION_PASCALS_TO_PSI 1.4504e-4

#define ATMOS_PRESSURE 101353.0


class Submarine {
    public:

    
    double outer_hull_outer_radius; 

    double outer_hull_inner_radius; 

    double inner_hull_outer_radius; 

    double inner_hull_inner_radius; 

    double hull_length; 

    double ballast_tank_volume; 

    double hard_ballast_mass; 

    double hull_mass; 

    double payload_mass; 

    double Cd; 

	double hull_volume; 

	double ballast_air_volume; 

	double ballast_water_volume; 

	double mass_ballast_water; 

	double hull_disp_volume; 

	double mass_total; 

	double A; 

	double mass_total_disp; 

	double bouy_force; 

	double drag_force; 

	double gravity_force; 

	double total_force; 

	
    
	double pos[2]; 

	double vel[2]; 

    double ballast_energy; 

    double pump_power; 


    
	double acc[2]; 


    
    double ballast_air_ratio; 
     
    double water_pressure_pascals; 

    double water_pressure_PSI; 
    
    int    pump_power_command; 
   

    

  int submarine_default_data();
  int submarine_init();
  int submarine_shutdown();
  int submarine_integ();
  int submarine_deriv();
  int submarine_control();
};
#define TRICK_SWIG_DEFINED_Submarine

#endif

#ifdef TRICK_SWIG_DEFINED_Submarine
%trick_cast_as(Submarine, Submarine)
#endif
