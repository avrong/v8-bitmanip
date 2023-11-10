#ifndef V8_CODEGEN_RISCV_CONSTANT_RISCV_ZBB_H_
#define V8_CODEGEN_RISCV_CONSTANT_RISCV_ZBB_H_

#include "src/codegen/riscv/base-constants-riscv.h"

namespace v8 {
namespace internal {

// Note use RO (RiscV Opcode) prefix
constexpr Opcode RO_ROR =
    OP | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);

#ifdef V8_TARGET_ARCH_RISCV32
constexpr Opcode RO_RORI =
    OP_IMM | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
#endif

#ifdef V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_RORI =
    OP_IMM | (0b101 << kFunct3Shift) | (0b011000 << kFunct6Shift);
#endif

}  // namespace internal
}  // namespace v8
#endif  // V8_CODEGEN_RISCV_CONSTANT_RISCV_ZBB_H_
