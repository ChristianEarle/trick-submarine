/************************************************************************
PURPOSE: (Simulate a submarine.)
LIBRARY DEPENDENCIES:
    ((submarine/src/Submarine.o))
**************************************************************************/
#ifndef SUBMARINE_HH
#define SUBMARINE_HH

// Density of salt water = 1023.6 kg/m^3
#define DENSITY_SALT_WATER 1023.6
// Acceleration of gravity = 9.80665 m/s^2
#define GRAVITY 9.80665
//Pascal to PSI
#define CONVERSION_PASCALS_TO_PSI 1.4504e-4
//Atmospheric Pressure
#define ATMOS_PRESSURE 101353.0


class Submarine {
    public:

    // Parameters
    double outer_hull_outer_radius; /* *io m outer hull outer radius */
    double outer_hull_inner_radius; /* *io m outer hull inner radius */
    double inner_hull_outer_radius; /* *io m inner hull outer radius */
    double inner_hull_inner_radius; /* *io m inner hull inner radius */
    double hull_length; /* *io m hull length */
    double ballast_tank_volume; /* *io L ballast tank volume */
    double hard_ballast_mass; /* *io kg hard ballast mass  */
    double hull_mass; /* *io kg hull mass */
    double payload_mass; /* *io kg payload mass */
    double Cd; /* *io -- drag coeff */
	double hull_volume; /* *io L hull volume */
	double ballast_air_volume; /* *io L ballast air volume */
	double ballast_water_volume; /* *io L ballast water volume */
	double mass_ballast_water; /* *io Kg mass of ballast water */
	double hull_disp_volume; /* *io L hull displacement volume */
	double mass_total; /* *io Kg total mass */
	double A; /* *io m^3 area of cross section */
	double mass_total_disp; /* *io kg mass total displacement */
	double bouy_force; /* *io N bouyancy force */
	double drag_force; /* *io N drag force */
	double gravity_force; /* *io N gravity force */
	double total_force; /* *io N total force */
	
    // State Variables (Uncalculated Variables)
	double pos[2]; /* m submarine */
	double vel[2]; /* m/s submarine */
    double ballast_energy; /* joules ballast energy */
    double pump_power; /* watts pump power */

    // Calculated Variables
	double acc[2]; /* *io m/s/s outer hull outer radius */

    // Control Variable
    double ballast_air_ratio; /* *o -- outer hull outer radius */     // To the GUI.
    double water_pressure_pascals; /* *i kPa outer hull outer radius */
    double water_pressure_PSI; /* *o PSI outer hull outer radius */    // To the GUI.
    int    pump_power_command; /* *i -- outer hull outer radius */   // From the GUI.

    // Methods

  int submarine_default_data();
  int submarine_init();
  int submarine_shutdown();
  int submarine_integ();
  int submarine_deriv();
  int submarine_control();
};

#endif
