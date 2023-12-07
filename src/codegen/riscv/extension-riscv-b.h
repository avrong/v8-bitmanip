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
  // Logical with negate
  void andn(Register rd, Register rs1, Register rs2);
  void orn(Register rd, Register rs1, Register rs2);
  void xnor(Register rd, Register rs1, Register rs2);
  // Count leading/trailing zero bits
  void clz(Register rd, Register rs);
  void ctz(Register rd, Register rs);
#if V8_TARGET_ARCH_RISCV64
  void clzw(Register rd, Register rs);
  void ctzw(Register rd, Register rs);
#endif
  // Count population
  void cpop(Register rd, Register rs);
#if V8_TARGET_ARCH_RISCV64
  void cpopw(Register rd, Register rs);
#endif
  // Integer minimum/maximum
  void max(Register rd, Register rs1, Register rs2);
  void maxu(Register rd, Register rs1, Register rs2);
  void min(Register rd, Register rs1, Register rs2);
  void minu(Register rd, Register rs1, Register rs2);
  // Sign- and zero-extension
  void sext_b(Register rd, Register rs);
  void sext_h(Register rd, Register rs);
  void zext_h(Register rd, Register rs);

 // Zbb: bitwise rotation

};
}  // namespace internal
}  // namespace v8
#endif  // V8_CODEGEN_RISCV_EXTENSION_RISCV_B_H_
