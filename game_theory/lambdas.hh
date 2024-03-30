#pragma once

#include <functional>
#include <vector>

using iterator_type = std::vector<int>::iterator;
using strategy_type = std::function<bool(iterator_type, iterator_type)>;

strategy_type cooperator();
strategy_type cheater();
strategy_type copycat();
strategy_type grudger();
strategy_type detective();
strategy_type copykitten();
