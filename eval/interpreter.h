#pragma once

#include "parser/visitor.h"
#include "parser/nodes.h"

#include "decs.h"

class Interpreter : public Visitor {
public:
    Interpreter();

    void Eval(Node *node);

    VISIT_DEC(NTop) override;
    VISIT_DEC(NInt) override;
    VISIT_DEC(NBool) override;
    VISIT_DEC(NFun) override;
    VISIT_DEC(NUnit) override;
    VISIT_DEC(NPair) override;
    VISIT_DEC(NIdent) override;
    VISIT_DEC(NLet) override;
    VISIT_DEC(NLetRec) override;
    VISIT_DEC(NSeq) override;
    VISIT_DEC(NApp) override;
    VISIT_DEC(NBinaryApp) override;
    VISIT_DEC(NUnaryApp) override;
    VISIT_DEC(NCond) override;
    VISIT_DEC(NHandler) override;
    VISIT_DEC(NOpCase) override;
    VISIT_DEC(NWithHandle) override;
    VISIT_DEC(NValue) override;

private:
    EnvPtr env_;
    ResultPtr ret_;
};
