#include "envpool/core/py_envpool.h"
#include "envpool/slowdown/slowdown_envpool.h"

using SlowdownEnvSpec = PyEnvSpec<slowdown::SlowdownEnvSpec>;
using SlowdownEnvPool = PyEnvPool<slowdown::SlowdownEnvPool>;
PYBIND11_MODULE(slowdown_envpool, m) { REGISTER(m, SlowdownEnvSpec, SlowdownEnvPool) }
