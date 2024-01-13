/************************************************************************
PURPOSE: (Print the final cannon ball state.)
*************************************************************************/
#include <stdio.h>
#include "../include/Submarine.hh"
#include "trick/exec_proto.h"

int Submarine::submarine_shutdown() {
	double t = exec_get_sim_time();
    printf( "========================================\n");
    printf( "      Submarine State at Shutdown     \n");
    printf( "t = %g\n", t);
    printf( "pos = [%.9f, %.9f]\n", pos[0], pos[1]);
    printf( "vel = [%.9f, %.9f]\n", vel[0], vel[1]);
    printf( "========================================\n");
    return 0 ;
}
