#include <r_asm.h>
#include <r_lib.h>

int decode(RAsm *a, RAsmOp *op, const ut8 *b, int l);

static int disassemble (RAsm *a, RAsmOp *op, const ut8 *b, int l) {
	return decode(a, op, b, l);
}
RAsmPlugin r_asm_plugin_series7copu = {
        .name = "series7copu",
        .arch = "series7copu",
        .license = "penis",
        .bits = 32,
        .desc = "Xilinx Series7 Configuration Processor Disassembler",
        .disassemble = &disassemble,
};

#ifndef CORELIB
struct r_lib_struct_t radare_plugin = {
        .type = R_LIB_TYPE_ASM,
        .data = &r_asm_plugin_series7copu
};
#endif

