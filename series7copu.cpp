extern "C"{
	#include <r_asm.h>
	#include <r_lib.h>
}
#include <vector>
#include <map>
#include <string>

struct op2mnemonic
{
	std::map< uint32_t, std::string > o2m = 
	{
		{0b00000000000000000000000000000000, "nop"},
		{0b00001000000000000000000000000000, "read"},
		{0b00010000000000000000000000000000, "write"},
		{0b00011000000000000000000000000000, "reserved opcode"}
	};

	std::map< uint32_t, std::string > r2m = 
	{
		{0b00000000000000000000000000000000, "CRC"},
		{0b00000000000000000010000000000000, "FAR"},
		{0b00000000000000000100000000000000, "FDRI"},
		{0b00000000000000000110000000000000, "FDRO"},
		{0b00000000000000001000000000000000, "CMD"},
		{0b00000000000000001010000000000000, "CTL0"},
		{0b00000000000000001100000000000000, "MASK"},
		{0b00000000000000001110000000000000, "STAT"},
		{0b00000000000000010000000000000000, "LOUT"},
		{0b00000000000000010010000000000000, "COR0"},
		{0b00000000000000010100000000000000, "MFWR"},
		{0b00000000000000010110000000000000, "CBC"},
		{0b00000000000000011000000000000000, "IDCODE"},
		{0b00000000000000011010000000000000, "AXSS"},
		{0b00000000000000011100000000000000, "COR1"},
		{0b00000000000000100000000000000000, "WBSTAR"},
		{0b00000000000000100010000000000000, "TIMER"},
		{0b00000000000000101100000000000000, "BOOTST"},
		{0b00000000000000110000000000000000, "CTL1"},
		{0b00000000000000111110000000000000, "BSPI"},

	};
	std::map< uint32_t, std::string > header_types = 
	{	
		{0x20000000,  "Type 1"},
                {0x40000000 : "Type 2"},
	};

	uint32_t TYPE1_MASK = 0x20000000;
	uint32_t TYPE2_MASK = 0x40000000;

	uint32_t OPCODE_MASK	= 0b00011000000000000000000000000000;

	uint32_t TYPE_MASK	= 0b11100000000000000000000000000000;

	uint32_t REG_ADD_MASK	= 0b00000000000000111110000000000000;
        uint32_t TYPE1_ADD_MASK = 0b00000000000000111110000000000000;
	uint32_t TYPE1_WORD_COUNT_MASK =  
				  0b00000000000000000000011111111111;
	uint32_t TYPE2_WORD_COUNT_MASK =
	 			  0b00000111111111111111111111111111;

	uint32_t OP_NOP      = 0b00;
	uint32_t OP_READ     = 0b01;
	uint32_t OP_WRITE    = 0b10;
	uint32_t OP_RESERVED = 0b11; 

	op2mnemonic(){
	}
	std::string operator [] (const uint32_t opc)
        {

            if(([&](){ return (opc) ?
                        o2m.end() : o2m.find(opc);})() == o2m.end())
                return "illegal opcode";
            return o2m[opc];
        }

};
static int disassemble(RAsm *a, RAsmOp *op, const ut8 *b, int l)
{
	op2mnemonic op2mne;
	

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
