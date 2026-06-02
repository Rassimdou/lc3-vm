#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * LC-3 virtual machine scaffold.
 *
 * This file sets up the machine state and the core constants we will use as
 * the emulator grows. The execution loop and instruction handlers will land in
 * later commits.
 */

#define MEMORY_MAX (1u << 16)
#define PC_START 0x3000

typedef uint16_t word_t;

enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,   /* program counter */
    R_COND, /* condition flags */
    R_COUNT
};

enum {
    OP_BR = 0, /* branch */
    OP_ADD,    /* add */
    OP_LD,     /* load */
    OP_ST,     /* store */
    OP_JSR,    /* jump register */
    OP_AND,    /* bitwise and */
    OP_LDR,    /* load register */
    OP_STR,    /* store register */
    OP_RTI,    /* unused */
    OP_NOT,    /* bitwise not */
    OP_LDI,    /* load indirect */
    OP_STI,    /* store indirect */
    OP_JMP,    /* jump */
    OP_RES,    /* reserved (unused) */
    OP_LEA,    /* load effective address */
    OP_TRAP    /* execute trap */
};

enum {
    FL_POS = 1 << 0, /* P */
    FL_ZRO = 1 << 1, /* Z */
    FL_NEG = 1 << 2  /* N */
};

static word_t memory[MEMORY_MAX];
static word_t reg[R_COUNT];

static void reset_vm(void) {
    for (size_t i = 0; i < MEMORY_MAX; i++) {
        memory[i] = 0;
    }

    for (size_t i = 0; i < R_COUNT; i++) {
        reg[i] = 0;
    }

    reg[R_PC] = PC_START;
    reg[R_COND] = FL_ZRO;
}

int main(void) {
    reset_vm();

    puts("LC-3 VM scaffold ready.");
    return EXIT_SUCCESS;
}
