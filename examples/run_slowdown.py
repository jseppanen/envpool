import numpy as np
import envpool
import time


def run_test(num_threads):
    num_envs = 10 * num_threads
    num_players = 5

    env = envpool.make_gym(
        "Slowdown-v0",
        num_envs=num_envs,
        num_threads=num_threads,
        max_num_players=num_players,
    )
    env.reset()

    action = {
        "players.id": np.arange(num_envs * num_players, dtype=np.int32) % num_players,
        "players.action": np.zeros(num_envs * num_players, dtype=np.int32),
    }

    tic = time.time()
    for _ in range(1000):
        env.step(action)
    toc = time.time()
    env.close()
    return 1000 * num_envs / (toc - tic)


print(f"1 thread: {run_test(1):.1f} SPS")
print(f"2 threads: {run_test(2):.1f} SPS")
print(f"4 threads: {run_test(4):.1f} SPS")
print(f"8 threads: {run_test(8):.1f} SPS")
print(f"16 threads: {run_test(16):.1f} SPS")
print(f"32 threads: {run_test(32):.1f} SPS")
print(f"64 threads: {run_test(64):.1f} SPS")
print(f"96 threads: {run_test(96):.1f} SPS")

# 1 thread: 17849.3 SPS
# 2 threads: 22744.9 SPS
# 4 threads: 30579.2 SPS
# 8 threads: 39536.7 SPS
# 16 threads: 46167.0 SPS
# 32 threads: 48889.3 SPS
# 64 threads: 40827.2 SPS
# 96 threads: 17439.2 SPS
