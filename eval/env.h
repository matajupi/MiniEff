#pragma once

#include <exception>
#include <memory>
#include <string>

#include "decs.h"

class Env {
public:
    Env(std::string var, ResultPtr value, EnvPtr parent)
        : var_(var), value_(value), parent_(parent) { }

    std::string GetVar() const { return var_; }
    ResultPtr GetValue() const { return value_; }
    EnvPtr GetParent() const { return parent_; }

    ResultPtr Lookup(std::string sv) const;

private:
    std::string var_;
    ResultPtr value_;
    EnvPtr parent_;
};

