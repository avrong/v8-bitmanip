#include "src/codegen/riscv/extension-riscv-b.h"

namespace v8 {
namespace internal {

// Zba

// Zbb: basic
// Logical with negate
void AssemblerRISCVB::andn(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0100000, 0b111, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::orn(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0100000, 0b110, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::xnor(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0100000, 0b100, OP, rd, rs1, rs2);
}

// Count leading/trailing zero bits
void AssemblerRISCVB::clz(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM, rd, rs, 0b011000000000);
}

void AssemblerRISCVB::ctz(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM, rd, rs, 0b011000000001);
}

#if V8_TARGET_ARCH_RISCV64
void AssemblerRISCVB::clzw(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM_32, rd, rs, 0b011000000000);
}

void AssemblerRISCVB::ctzw(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM_32, rd, rs, 0b011000000001);
}
#endif

// Count population
void AssemblerRISCVB::cpop(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM, rd, rs, 0b011000000010);
}

#if V8_TARGET_ARCH_RISCV64
void AssemblerRISCVB::cpopw(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM_32, rd, rs, 0b011000000010);
}
#endif

// Integer minimum/maximum
void AssemblerRISCVB::max(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0000101, 0b110, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::maxu(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0000101, 0b111, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::min(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0000101, 0b100, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::minu(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0000101, 0b101, OP, rd, rs1, rs2);
}

// Sign- and zero-extension
void AssemblerRISCVB::sext_b(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM, rd, rs, 0b011000000100);
}

void AssemblerRISCVB::sext_h(Register rd, Register rs) {
  GenInstrI(0b001, OP_IMM, rd, rs, 0b011000000101);
}

#if V8_TARGET_ARCH_RISCV32
void AssemblerRISCVB::zext_h(Register rd, Register rs) {
  GenInstrI(0b100, OP, rd, rs, 0b000010000000);
}
#elif V8_TARGET_ARCH_RISCV64
void AssemblerRISCVB::zext_h(Register rd, Register rs) {
  GenInstrI(0b100, OP_32, rd, rs, 0b000010000000);
}
#endif

// Zbb: bitwise rotation

}  // namespace internal
}  // namespace v8
