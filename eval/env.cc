#include "env.h"

#include "utils.h"

ResultPtr Env::Lookup(std::string sv) const {
    if (var_ == sv) {
        return value_;
    }
    if (parent_ == nullptr) {
        throw VariableNotFoundException();
    }
    return parent_->Lookup(sv);
}

