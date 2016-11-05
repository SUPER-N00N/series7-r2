extern "C"{
	#include <r_asm.h>
	#include <r_lib.h>
}
#include <map>
#include <string>

static int disassemble(RAsm *a, RAsmOp *op, const ut8 *b, int l)
{

	return 0;	
}

RAsmPlugin r_asm_plugin_series7copu = {
	"series7copu",
	"series7copy",
	"penis",
	32,
	"Xilinx Series7 Configuration Processor Disassembler",
	&disassemble,
};

#ifdef CORELIB
struct r_lib_struct_t radare_plugin = {
        .type = R_LIB_TYPE_ASM,
        .data = &r_asm_plugin_series7copu
};
#endif
