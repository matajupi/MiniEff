#pragma once

#include <memory>
#include <iostream>

#include "decs.h"

#define DUMP_DEC void Dump(std::ostream &os) const

// enum class ResultType {
//     RTInt,
//     RTBool,
//     RTPair,
//     RTUnit,
//     RTFun,
//     RTRec,
//     RTOp,
//     RTPrim,
//     RTEffect,
// };

class Node;

class Result {
public:
    virtual DUMP_DEC = 0;
};

class VInt : public Result {
public:
    VInt(int value) : value_(value) { }

    int GetValue() const { return value_; }

    DUMP_DEC override;

private:
    int value_;
};

class VBool : public Result {
public:
    VBool(bool value) : value_(value) { }

    bool GetValue() const { return value_; }

    DUMP_DEC override;

private:
    bool value_;
};

class VUnit : public Result {
public:
    DUMP_DEC override;
};

class VPair : public Result {
public:
    VPair(ResultPtr val1, ResultPtr val2)
        : val1_(val1), val2_(val2) { }

    ResultPtr GetValue1() const { return val1_; }
    ResultPtr GetValue2() const { return val2_; }

    DUMP_DEC override;

private:
    ResultPtr val1_;
    ResultPtr val2_;
};

class VFun : public Result {
public:
    VFun(EnvPtr env, std::string var, Node *body)
        : env_(env), var_(var), body_(body) { }

    EnvPtr GetEnv() const { return env_; }
    std::string GetVar() const { return var_; }
    Node *GetBody() const { return body_; }

    DUMP_DEC override;

private:
    EnvPtr env_;
    std::string var_;
    Node *body_;
};

class VRec : public Result {
public:
    VRec(EnvPtr env, std::string fun, std::string var, Node *body)
        : env_(env), fun_(fun), var_(var), body_(body) { }

    EnvPtr GetEnv() const { return env_; }
    std::string GetFun() const { return fun_; }
    std::string GetVar() const { return var_; }
    Node *GetBody() const { return body_; }

    DUMP_DEC override;

private:
    EnvPtr env_;
    std::string fun_;
    std::string var_;
    Node *body_;
};
