#pragma once

#include <memory>

class Env;
class Result;

using EnvPtr = std::shared_ptr<const Env>;
using ResultPtr = std::shared_ptr<const Result>;
