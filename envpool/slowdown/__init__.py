from envpool.python.api import py_env
from .slowdown_envpool import _SlowdownEnvPool, _SlowdownEnvSpec


SlowdownEnvSpec, SlowdownDMEnvPool, SlowdownGymEnvPool = py_env(
  _SlowdownEnvSpec, _SlowdownEnvPool
)


__all__ = [
  "SlowdownEnvSpec",
  "SlowdownDMEnvPool",
  "SlowdownGymEnvPool",
]
