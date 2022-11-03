from envpool.registration import register


register(
  task_id="Slowdown-v0",
  import_path="envpool.slowdown",
  spec_cls="SlowdownEnvSpec",
  dm_cls="SlowdownDMEnvPool",
  gym_cls="SlowdownGymEnvPool",
)
