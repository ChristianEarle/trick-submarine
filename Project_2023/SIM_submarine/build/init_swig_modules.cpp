#include <Python.h>
#if PY_VERSION_HEX >= 0x03000000
extern "C" {

PyObject * PyInit__m8fb67ea908d11788d30be737988028d6(void) ; /* /home/caci114/Project_2023/SIM_submarine/S_source.hh */
PyObject * PyInit__mba48123e2b0720fbeeb8ad0d8bd89ec1(void) ; /* /home/caci114/Project_2023/SIM_submarine/models/submarine/include/Submarine.hh */
PyObject * PyInit__sim_services(void) ;
PyObject * PyInit__top(void) ;
PyObject * PyInit__swig_double(void) ;
PyObject * PyInit__swig_int(void) ;
PyObject * PyInit__swig_ref(void) ;

void init_swig_modules(void) {

    PyImport_AppendInittab("_mba48123e2b0720fbeeb8ad0d8bd89ec1", PyInit__mba48123e2b0720fbeeb8ad0d8bd89ec1) ;
    PyImport_AppendInittab("_m8fb67ea908d11788d30be737988028d6", PyInit__m8fb67ea908d11788d30be737988028d6) ;
    PyImport_AppendInittab("_sim_services", PyInit__sim_services) ;
    PyImport_AppendInittab("_top", PyInit__top) ;
    PyImport_AppendInittab("_swig_double", PyInit__swig_double) ;
    PyImport_AppendInittab("_swig_int", PyInit__swig_int) ;
    PyImport_AppendInittab("_swig_ref", PyInit__swig_ref) ;
    return ;
}

}
#else
extern "C" {

void init_m8fb67ea908d11788d30be737988028d6(void) ; /* /home/caci114/Project_2023/SIM_submarine/S_source.hh */
void init_mba48123e2b0720fbeeb8ad0d8bd89ec1(void) ; /* /home/caci114/Project_2023/SIM_submarine/models/submarine/include/Submarine.hh */
void init_sim_services(void) ;
void init_top(void) ;
void init_swig_double(void) ;
void init_swig_int(void) ;
void init_swig_ref(void) ;

void init_swig_modules(void) {

    init_mba48123e2b0720fbeeb8ad0d8bd89ec1() ;
    init_m8fb67ea908d11788d30be737988028d6() ;
    init_sim_services() ;
    init_top() ;
    init_swig_double() ;
    init_swig_int() ;
    init_swig_ref() ;
    return ;
}

}
#endif
