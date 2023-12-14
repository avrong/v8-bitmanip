#ifndef V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_
#define V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_

#include "src/codegen/riscv/base-constants-riscv.h"
namespace v8 {
namespace internal {

// Zba

// Zbb: basic

// Zbb: bitwise rotation
constexpr Opcode RO_ROL =
    OP | (0b001 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_ROR =
    OP | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_ORCB =
    OP_IMM | (0b101 << kFunct3Shift) | (0b001010000111 << kImm12Shift);

#ifdef V8_TARGET_ARCH_RISCV32
constexpr Opcode RO_RORI =
    OP_IMM | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_REV8 =
    OP_IMM | (0b101 << kFunct3Shift) | (0b011010011000 << kImm12Shift);
#endif

#ifdef V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_ROLW =
    OP_32 | (0b001 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_RORW =
    OP_32 | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_RORI =
    OP_IMM | (0b101 << kFunct3Shift) | (0b011000 << kFunct6Shift);
constexpr Opcode RO_RORIW =
    OP_IMM_32 | (0b101 << kFunct3Shift) | (0b0110000 << kFunct7Shift);
constexpr Opcode RO_REV8 =
    OP_IMM | (0b101 << kFunct3Shift) | (0b011010111000 << kImm12Shift);
#endif

}  // namespace internal
}  // namespace v8

#endif  // V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_
