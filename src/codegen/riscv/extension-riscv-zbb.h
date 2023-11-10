#ifndef V8_CODEGEN_RISCV_EXTENSION_RISCV_ZBB_H_
#define V8_CODEGEN_RISCV_EXTENSION_RISCV_ZBB_H_

#include "src/codegen/assembler.h"
#include "src/codegen/riscv/base-assembler-riscv.h"
#include "src/codegen/riscv/constant-riscv-zbb.h"
#include "src/codegen/riscv/register-riscv.h"

namespace v8 {
namespace internal {

class AssemblerRISCVZbb : public AssemblerRiscvBase {
 public:
  void ror(Register rd, Register rs1, Register rs2);
  void rori(Register rd, Register rs1, uint8_t shamt);
};

}  // namespace internal
}  // namespace v8
#endif  // V8_CODEGEN_RISCV_EXTENSION_RISCV_ZBB_H_
