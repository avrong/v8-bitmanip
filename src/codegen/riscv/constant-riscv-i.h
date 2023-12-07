// Copyright 2022 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef V8_CODEGEN_RISCV_CONSTANT_RISCV_I_H_
#define V8_CODEGEN_RISCV_CONSTANT_RISCV_I_H_
#include "src/codegen/riscv/base-constants-riscv.h"
namespace v8 {
namespace internal {

// Note use RO (RiscV Opcode) prefix
// RV32I Base Instruction Set
constexpr Opcode RO_LUI = LUI;
constexpr Opcode RO_AUIPC = AUIPC;
constexpr Opcode RO_JAL = JAL;
constexpr Opcode RO_JALR = JALR | (0b000 << kFunct3Shift);
constexpr Opcode RO_BEQ = BRANCH | (0b000 << kFunct3Shift);
constexpr Opcode RO_BNE = BRANCH | (0b001 << kFunct3Shift);
constexpr Opcode RO_BLT = BRANCH | (0b100 << kFunct3Shift);
constexpr Opcode RO_BGE = BRANCH | (0b101 << kFunct3Shift);
constexpr Opcode RO_BLTU = BRANCH | (0b110 << kFunct3Shift);
constexpr Opcode RO_BGEU = BRANCH | (0b111 << kFunct3Shift);
constexpr Opcode RO_LB = LOAD | (0b000 << kFunct3Shift);
constexpr Opcode RO_LH = LOAD | (0b001 << kFunct3Shift);
constexpr Opcode RO_LW = LOAD | (0b010 << kFunct3Shift);
constexpr Opcode RO_LBU = LOAD | (0b100 << kFunct3Shift);
constexpr Opcode RO_LHU = LOAD | (0b101 << kFunct3Shift);
constexpr Opcode RO_SB = STORE | (0b000 << kFunct3Shift);
constexpr Opcode RO_SH = STORE | (0b001 << kFunct3Shift);
constexpr Opcode RO_SW = STORE | (0b010 << kFunct3Shift);
constexpr Opcode RO_ADDI = OP_IMM | (0b000 << kFunct3Shift);
constexpr Opcode RO_SLTI = OP_IMM | (0b010 << kFunct3Shift);
constexpr Opcode RO_SLTIU = OP_IMM | (0b011 << kFunct3Shift);
constexpr Opcode RO_XORI = OP_IMM | (0b100 << kFunct3Shift);
constexpr Opcode RO_ORI = OP_IMM | (0b110 << kFunct3Shift);
constexpr Opcode RO_ANDI = OP_IMM | (0b111 << kFunct3Shift);
constexpr Opcode RO_SLLI = OP_IMM | (0b001 << kFunct3Shift);
constexpr Opcode RO_SRLI = OP_IMM | (0b101 << kFunct3Shift);
// RO_SRAI = OP_IMM | (0b101 << kFunct3Shift), // Same as SRLI, use func7
constexpr Opcode RO_ADD =
    OP | (0b000 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SUB =
    OP | (0b000 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_SLL =
    OP | (0b001 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SLT =
    OP | (0b010 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SLTU =
    OP | (0b011 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_XOR =
    OP | (0b100 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SRL =
    OP | (0b101 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SRA =
    OP | (0b101 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_OR =
    OP | (0b110 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_AND =
    OP | (0b111 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_FENCE = MISC_MEM | (0b000 << kFunct3Shift);
constexpr Opcode RO_ECALL = SYSTEM | (0b000 << kFunct3Shift);
// RO_EBREAK = SYSTEM | (0b000 << kFunct3Shift), // Same as ECALL, use imm12

// Zbb: basic
// Logical with negate
constexpr Opcode RO_ANDN =
    OP | (0b111 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_ORN =
    OP | (0b110 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_XNOR =
    OP | (0b100 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
// Sign- and zero-extension
constexpr Opcode RO_SEXT_B = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000100 << kImm12Shift);
constexpr Opcode RO_SEXT_H = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000101 << kImm12Shift);
constexpr Opcode RO_ZEXT_H = OP | (0b100 << kFunct3Shift) | (0b000010000000 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_ZEXT_H = OP_32 | (0b100 << kFunct3Shift) | (0b000010000000 << kImm12Shift);
#endif
// Count leading/training zero bits
constexpr Opcode RO_CLZ = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000000 << kImm12Shift);
constexpr Opcode RO_CTZ = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000001 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_CLZW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000000 << kImm12Shift);
constexpr Opcode RO_CTZW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000001 << kImm12Shift);
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
// Count population
constexpr Opcode RO_CPOP = OP_IMM | (0b001 << kFunct3Shift) | (0b011000000010 << kImm12Shift);
#if V8_TARGET_ARCH_RISCV64
constexpr Opcode RO_CPOPW = OP_IMM_32 | (0b001 << kFunct3Shift) | (0b011000000010 << kImm12Shift);
#endif

#if V8_TARGET_ARCH_RISCV64
  // RV64I Base Instruction Set (in addition to RV32I)
constexpr Opcode RO_LWU = LOAD | (0b110 << kFunct3Shift);
constexpr Opcode RO_LD = LOAD | (0b011 << kFunct3Shift);
constexpr Opcode RO_SD = STORE | (0b011 << kFunct3Shift);
constexpr Opcode RO_ADDIW = OP_IMM_32 | (0b000 << kFunct3Shift);
constexpr Opcode RO_SLLIW = OP_IMM_32 | (0b001 << kFunct3Shift);
constexpr Opcode RO_SRLIW = OP_IMM_32 | (0b101 << kFunct3Shift);
// RO_SRAIW = OP_IMM_32 | (0b101 << kFunct3Shift), // Same as SRLIW, use func7
constexpr Opcode RO_ADDW =
    OP_32 | (0b000 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SUBW =
    OP_32 | (0b000 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
constexpr Opcode RO_SLLW =
    OP_32 | (0b001 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SRLW =
    OP_32 | (0b101 << kFunct3Shift) | (0b0000000 << kFunct7Shift);
constexpr Opcode RO_SRAW =
    OP_32 | (0b101 << kFunct3Shift) | (0b0100000 << kFunct7Shift);
#endif
// clang-format on
}  // namespace internal
}  // namespace v8

#endif  // V8_CODEGEN_RISCV_CONSTANT_RISCV_I_H_
