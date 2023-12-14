#include "src/codegen/riscv/extension-riscv-b.h"

namespace v8 {
namespace internal {

// Zba

// Zbb: basic

// Zbb: bitwise rotation
void AssemblerRISCVB::rol(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0110000, 0b001, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::ror(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0110000, 0b101, OP, rd, rs1, rs2);
}

void AssemblerRISCVB::orcb(Register rd, Register rs) {
  GenInstrI(0b101, OP_IMM, rd, rs, 0b001010000111);
}

#ifdef V8_TARGET_ARCH_RISCV32
void AssemblerRISCVB::rori(Register rd, Register rs1, uint8_t shamt) {
  DCHECK(is_uint5(shamt));
  GenInstrI(0b101, OP_IMM, rd, rs1,  0b011000000000 | shamt);
}

void AssemblerRISCVB::rev8(Register rd, Register rs) {
  GenInstrI(0b101, OP_IMM, rd, rs,  0b011010011000);
}
#endif

#ifdef V8_TARGET_ARCH_RISCV64
void AssemblerRISCVB::rolw(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0110000, 0b001, OP_32, rd, rs1, rs2);
}

void AssemblerRISCVB::rori(Register rd, Register rs1, uint8_t shamt) {
  DCHECK(is_uint6(shamt));
  GenInstrI(0b101, OP_IMM, rd, rs1,  0b011000000000 | shamt);
}

void AssemblerRISCVB::roriw(Register rd, Register rs1, uint8_t shamt) {
  DCHECK(is_uint5(shamt));
  GenInstrI(0b101, OP_IMM_32, rd, rs1,  0b011000000000 | shamt);
}

void AssemblerRISCVB::rorw(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0110000, 0b101, OP_32, rd, rs1, rs2);
}

void AssemblerRISCVB::rev8(Register rd, Register rs) {
  GenInstrI(0b101, OP_IMM, rd, rs,  0b011010111000);
}
#endif

}  // namespace internal
}  // namespace v8
