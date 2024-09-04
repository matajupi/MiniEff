#include "interpreter.h"

#include <iostream>

#include "result.h"
#include "env.h"
#include "utils.h"

#define VISIT_HEADER(cls) void Interpreter::Visit(cls *node)

Interpreter::Interpreter() {
    // TODO:
}
void Interpreter::Eval(Node *node) {
    node->Accept(*this);
// TODO:
if (ret_ == nullptr) { std::cout << "nullptr" << std::endl; }
else { ret_->Dump(std::cout); }
}
VISIT_HEADER(NTop) {
    node->GetDec()->Accept(*this);
}
VISIT_HEADER(NInt) {
    ret_ = std::make_shared<VInt>(node->GetValue());
}
VISIT_HEADER(NBool) {
    ret_ = std::make_shared<VBool>(node->GetValue());
}
VISIT_HEADER(NValue) {
    ret_ = node->GetValue();
}
VISIT_HEADER(NUnit) {
    ret_ = std::make_shared<VUnit>();
}
VISIT_HEADER(NFun) {
    ret_ = std::make_shared<VFun>(env_, node->GetVar(), node->GetBody());
}
VISIT_HEADER(NPair) {
    // TODO: Effect
    node->GetExpr1()->Accept(*this);
    auto v1 = ret_;
    node->GetExpr2()->Accept(*this);
    auto v2 = ret_;
    ret_ = std::make_shared<VPair>(v1, v2);
}
VISIT_HEADER(NIdent) {
    ret_ = env_->Lookup(node->GetStr());
}
VISIT_HEADER(NLet) {
    // TODO: Effect
    node->GetBexpr()->Accept(*this);
    auto v = ret_;
    env_ = std::make_shared<Env>(node->GetVar(), v, env_);
    node->GetCexpr()->Accept(*this);
    env_ = env_->GetParent();
}
VISIT_HEADER(NLetRec) {
    env_ = std::make_shared<Env>(
        node->GetFun(),
        std::make_shared<VRec>(
            env_, node->GetFun(), node->GetVar(), node->GetBexpr()
        ),
        env_
    );
    node->GetCexpr()->Accept(*this);
    env_ = env_->GetParent();
}
VISIT_HEADER(NSeq) {
    // TODO:
}
VISIT_HEADER(NApp) {
    node->GetFun()->Accept(*this);
    auto [fun, rec] = Cast<const VFun, const VRec>(ret_);
    node->GetArg()->Accept(*this);
    auto tmp = env_;
    if (fun) {
        env_ = std::make_shared<Env>(fun->GetVar(), ret_, fun->GetEnv());
        fun->GetBody()->Accept(*this);
    }
    else {
        env_ = std::make_shared<Env>(rec->GetFun(), rec,
            std::make_shared<Env>(rec->GetVar(), ret_, rec->GetEnv()));
        rec->GetBody()->Accept(*this);
    }
    env_ = tmp;
}
VISIT_HEADER(NBinaryApp) {
    // TODO:
}
VISIT_HEADER(NUnaryApp) {
    // TODO:
}
VISIT_HEADER(NCond) {
    node->GetCond()->Accept(*this);
    auto cond = Cast<const VBool>(ret_);
    if (cond->GetValue()) {
        node->GetConseq()->Accept(*this);
    }
    else {
        node->GetAlter()->Accept(*this);
    }
}
VISIT_HEADER(NHandler) {
    // TODO:
}
VISIT_HEADER(NOpCase) {
    // TODO:
}
VISIT_HEADER(NWithHandle) {
    // TODO:
}
