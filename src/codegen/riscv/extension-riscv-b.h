#include "src/codegen/assembler.h"
#include "src/codegen/riscv/base-assembler-riscv.h"
#include "src/codegen/riscv/constant-riscv-b.h"
#include "src/codegen/riscv/register-riscv.h"
#ifndef V8_CODEGEN_RISCV_EXTENSION_RISCV_B_H_
#define V8_CODEGEN_RISCV_EXTENSION_RISCV_B_H_

namespace v8 {
namespace internal {
class AssemblerRISCVB : public AssemblerRiscvBase {
 public:

 // Zba

 // Zbb: basic

 // Zbb: bitwise rotation
  void rol(Register rd, Register rs1, Register rs2);
  void ror(Register rd, Register rs1, Register rs2);
  void rori(Register rd, Register rs1, uint8_t shamt);
  void orcb(Register rd, Register rs);
  void rev8(Register rd, Register rs);
#ifdef V8_TARGET_ARCH_RISCV64
  void rolw(Register rd, Register rs1, Register rs2);
  void roriw(Register rd, Register rs1, uint8_t shamt);
  void rorw(Register rd, Register rs1, Register rs2);
#endif

};
}  // namespace internal
}  // namespace v8
#endif  // V8_CODEGEN_RISCV_EXTENSION_RISCV_B_H_
