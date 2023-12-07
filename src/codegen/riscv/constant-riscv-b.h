#ifndef V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_
#define V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_

#include "src/codegen/riscv/base-constants-riscv.h"
namespace v8 {
namespace internal {

// Zba

// Zbb: basic
// Logical with negate
constexpr Opcode RO_ANDN =
    OP | (0b111 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_ORN =
    OP | (0b110 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_XNOR =
    OP | (0b100 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
// Count leading/trailing zero bits
constexpr Opcode RO_CLZ = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000000 << kImm12Shift);
constexpr Opcode RO_CTZ = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000001 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_CLZW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000000 << kImm12Shift);
constexpr Opcode RO_CTZW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000001 << kImm12Shift);
#endif
// Count population
constexpr Opcode RO_CPOP = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000010 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_CPOPW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000010 << kImm12Shift);
#endif
// Integer minimum/maximum
constexpr Opcode RO_MAX =
    OP | (0b110 << kFunct3Shift) | (0b0000101 << kFunct7Shift);
constexpr Opcode RO_MAXU =
    OP | (0b111 << kFunct3Shift) | (0b0000101 << kFunct7Shift);
constexpr Opcode RO_MIN =
    OP | (0b100 << kFunct3Shift) | (0b0000101 << kFunct7Shift);
constexpr Opcode RO_MINU =
    OP | (0b101 << kFunct3Shift) | (0b0000101 << kFunct7Shift);
// Sign- and zero-extension
constexpr Opcode RO_SEXT_B = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000100 << kImm12Shift);
constexpr Opcode RO_SEXT_H = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000101 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV32
constexpr Opcode RO_ZEXT_H = OP | (0b100 << kFunct3Shift) | (0b000010000000 << kImm12Shift);
#elif V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_ZEXT_H = OP_32 | (0b100 << kFunct3Shift) | (0b000010000000 << kImm12Shift);
#endif

// Zbb: bitwise rotation

}  // namespace internal
}  // namespace v8

#endif  // V8_CODEGEN_RISCV_CONSTANT_RISCV_B_H_
