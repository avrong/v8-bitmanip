#include "src/codegen/riscv/extension-riscv-zbb.h"

namespace v8 {
namespace internal {

void AssemblerRISCVZbb::ror(Register rd, Register rs1, Register rs2) {
  GenInstrR(0b0110000, 0b101, OP, rd, rs1, rs2);
}

#ifdef V8_TARGET_ARCH_RISCV32
void AssemblerRISCVZbb::rori(Register rd, Register rs1, uint8_t shamt) {
  DCHECK(is_uint5(shamt));
  GenInstrI(0b101, OP_IMM, rd, rs1,  (0b0110000 << kFunct7Shift) | shamt);
}
#endif

#ifdef V8_TARGET_ARCH_RISCV64
void AssemblerRISCVZbb::rori(Register rd, Register rs1, uint8_t shamt) {
  DCHECK(is_uint6(shamt));
  GenInstrI(0b101, OP_IMM, rd, rs1,  (0b011000 << kFunct6Shift) | shamt);
}
#endif

}  // namespace internal
}  // namespace v8
