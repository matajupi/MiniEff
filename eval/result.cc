#include "result.h"

#include "parser/nodes.h"

#define DUMP_HEADER(cls) void cls::Dump(std::ostream &os) const

DUMP_HEADER(VInt) {
    os << value_;
}
DUMP_HEADER(VBool) {
    os << std::boolalpha << value_;
}
DUMP_HEADER(VUnit) {
    os << "()";
}
DUMP_HEADER(VPair) {
    os << "(";
    val1_->Dump(os);
    os << ", ";
    val2_->Dump(os);
    os << ")";
}
DUMP_HEADER(VFun) {
    os << "(" << "fun " << var_ << " -> ";
    body_->Dump(os);
    os << ")";
}
DUMP_HEADER(VRec) {
    os << "(" << "fix " << fun_ << " " << var_ << " -> ";
    body_->Dump(os);
    os << ")";
}
