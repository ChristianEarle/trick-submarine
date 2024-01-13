from pkgutil import extend_path
__path__ = extend_path(__path__, __name__)
import sys
import os
sys.path.append(os.getcwd() + "/trick.zip/trick")

import _sim_services
from sim_services import *

# create "all_cvars" to hold all global/static vars
all_cvars = new_cvar_list()
combine_cvars(all_cvars, cvar)
cvar = None

# /home/caci114/Project_2023/SIM_submarine/S_source.hh
import _m8fb67ea908d11788d30be737988028d6
combine_cvars(all_cvars, cvar)
cvar = None

# /home/caci114/Project_2023/SIM_submarine/models/submarine/include/Submarine.hh
import _mba48123e2b0720fbeeb8ad0d8bd89ec1
combine_cvars(all_cvars, cvar)
cvar = None

# /home/caci114/Project_2023/SIM_submarine/S_source.hh
from m8fb67ea908d11788d30be737988028d6 import *
# /home/caci114/Project_2023/SIM_submarine/models/submarine/include/Submarine.hh
from mba48123e2b0720fbeeb8ad0d8bd89ec1 import *

# S_source.hh
import _m8fb67ea908d11788d30be737988028d6
from m8fb67ea908d11788d30be737988028d6 import *

import _top
import top

import _swig_double
import swig_double

import _swig_int
import swig_int

import _swig_ref
import swig_ref

from shortcuts import *

from exception import *

cvar = all_cvars

