#ifndef SLOWDOWN_ENVPOOL_H
#define SLOWDOWN_ENVPOOL_H

#include <memory>
#include <vector>

#include "envpool/core/async_envpool.h"
#include "envpool/core/env.h"

namespace slowdown {

template<typename T>
inline static void fill_dynamic_array(Array& state, const T& value, std::vector<int>&& shape)
{
  auto* array = new TArray<T>(::Spec<T>(std::move(shape)));
  array->Fill(value);
  static_cast<Container<T>&>(state).reset(array);
}

class SlowdownEnvFns {
 public:
  static decltype(auto) DefaultConfig() {
    return MakeDict();
  }

  template <typename Config>
  static decltype(auto) StateSpec(const Config& conf) {
    return MakeDict(
      "obs:nested1.dyn1"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn2"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn3"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn4"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn5"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn6"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn7"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn8"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested1.dyn9"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn1"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn2"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn3"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn4"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn5"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn6"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn7"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn8"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested2.dyn9"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn1"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn2"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn3"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn4"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn5"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn6"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn7"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn8"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested3.dyn9"_.Bind(Spec<Container<int>>({}, Spec<int>({-1}))),
      "obs:nested4.arr1"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr2"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr3"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr4"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr5"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr6"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr7"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr8"_.Bind(Spec<int>({-1})),
      "obs:nested4.arr9"_.Bind(Spec<int>({-1})),
      "info:foo1"_.Bind(Spec<int>({})),
      "info:foo2"_.Bind(Spec<int>({})),
      "info:foo3"_.Bind(Spec<int>({})),
      "info:foo4"_.Bind(Spec<int>({})),
      "info:foo5"_.Bind(Spec<int>({})),
      "info:foo6"_.Bind(Spec<int>({})),
      "info:foo7"_.Bind(Spec<int>({})),
      "info:foo8"_.Bind(Spec<int>({})),
      "info:foo9"_.Bind(Spec<int>({}))
    );
  }

  template <typename Config>
  static decltype(auto) ActionSpec(const Config& conf) {
    return MakeDict("players.action"_.Bind(Spec<int>({-1})),
                    "players.id"_.Bind(Spec<int>({-1})));
  }
};

using SlowdownEnvSpec = EnvSpec<SlowdownEnvFns>;

class SlowdownEnv : public Env<SlowdownEnvSpec> {
 public:
  SlowdownEnv(const Spec& spec, int env_id)
      : Env<SlowdownEnvSpec>(spec, env_id)
  {}

  void Reset() override {
    WriteState();
  }

  void Step(const Action& action) override {
    int x = 0;
    for (int i = 0; i < 1000000; i++) {
      x += i * x + 1;
    }
    WriteState();
  }

  bool IsDone() override {
    return false;
  }

  void WriteState() {
    auto state = Allocate(max_num_players_);

    fill_dynamic_array(state["obs:nested1.dyn1"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn2"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn3"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn4"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn5"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn6"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn7"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn8"_], 42, {10});
    fill_dynamic_array(state["obs:nested1.dyn9"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn1"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn2"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn3"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn4"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn5"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn6"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn7"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn8"_], 42, {10});
    fill_dynamic_array(state["obs:nested2.dyn9"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn1"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn2"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn3"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn4"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn5"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn6"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn7"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn8"_], 42, {10});
    fill_dynamic_array(state["obs:nested3.dyn9"_], 42, {10});

    state["obs:nested4.arr1"_].Fill(123);
    state["obs:nested4.arr2"_].Fill(123);
    state["obs:nested4.arr3"_].Fill(123);
    state["obs:nested4.arr4"_].Fill(123);
    state["obs:nested4.arr5"_].Fill(123);
    state["obs:nested4.arr6"_].Fill(123);
    state["obs:nested4.arr7"_].Fill(123);
    state["obs:nested4.arr8"_].Fill(123);
    state["obs:nested4.arr9"_].Fill(123);

    state["info:foo1"_] = 88;
    state["info:foo2"_] = 88;
    state["info:foo3"_] = 88;
    state["info:foo4"_] = 88;
    state["info:foo5"_] = 88;
    state["info:foo6"_] = 88;
    state["info:foo7"_] = 88;
    state["info:foo8"_] = 88;
    state["info:foo9"_] = 88;
  }
};

using SlowdownEnvPool = AsyncEnvPool<SlowdownEnv>;

}  // namespace slowdown

#endif  // SLOWDOWN_ENVPOOL_H
