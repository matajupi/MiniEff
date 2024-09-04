#pragma once

#include <exception>
#include <memory>
#include <tuple>

class CastFailureException : public std::exception {
    char *what() {
        return (char *)"CastFailureException";
    }
};

class UnsupportedOperatorException : public std::exception {
    char *what() {
        return (char *)"UnsupportedOperatorException";
    }
};
class UnknownOperatorException : public std::exception {
    char *what() {
        return (char *)"UnsupportedOperatorException";
    }
};

class VariableNotFoundException : public std::exception {
    char *what() {
        return (char *)"VariableNotFoundException";
    }
};

class AmbiguousHandlerException : public std::exception {
    char *what() {
        return (char *)"AmbiguousHandlerException";
    }
};

template <typename T, typename U>
std::shared_ptr<T> Cast(std::shared_ptr<U> before) {
    auto after = std::dynamic_pointer_cast<T>(before);
    if (after == nullptr) {
        throw CastFailureException();
    }
    return after;
}
template <typename T1, typename T2, typename U>
std::tuple<
    std::shared_ptr<T1>,
    std::shared_ptr<T2>
> Cast(std::shared_ptr<U> before) {
    auto after1 = std::dynamic_pointer_cast<T1>(before);
    auto after2 = std::dynamic_pointer_cast<T2>(before);
    if (after1 == nullptr && after2 == nullptr) {
        throw CastFailureException();
    }
    return { after1, after2 };
}
template <typename T1, typename T2, typename T3, typename U>
std::tuple<
    std::shared_ptr<T1>,
    std::shared_ptr<T2>,
    std::shared_ptr<T3>
> Cast(std::shared_ptr<U> before) {
    auto after1 = std::dynamic_pointer_cast<T1>(before);
    auto after2 = std::dynamic_pointer_cast<T2>(before);
    auto after3 = std::dynamic_pointer_cast<T3>(before);
    if (after1 == nullptr && after2 == nullptr && after3 == nullptr) {
        throw CastFailureException();
    }
    return { after1, after2, after3 };
}
template <typename T, typename U>
std::shared_ptr<T> TryCast(std::shared_ptr<U> before) {
    auto after = std::dynamic_pointer_cast<T>(before);
    return after;
}

