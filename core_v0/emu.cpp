#include<iostream>
#include<vector>
#include<bitset>

uint32_t reg[32];
uint32_t pc;
std::vector<uint32_t> memory = {0xffffffff, 0xeeeeeeee};

typedef enum {
    R_type,
    I_type,
    S_type,
    B_type,
    J_type,
} Format;

typedef struct Operation Operation;

struct Operation {
    Format format;  //命令フォーマット
    std::bitset<32> bin;   //バイナリ
    uint32_t addr;  //アドレス
    uint8_t opcode;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t rd;
    uint8_t funct3;
    uint8_t funct7;
    uint32_t imm;
    Operation *next;//次の命令
};

//現在着目してる命令
Operation *operation;

void decode(Operation *operation){
    for(i = 0;i < 7;i++)
        operation->opcode |= operation->bin[i];

    switch(operation->opcode){
        case: 0x33
            for(i = 0;i < 5;i++)
                operation->rs1 |= operation->bin[i + 15] << i;
            for(i = 0;i < 5;i++)
                operation->rs2 |= operation->bin[i + 20] << i;
            for(i = 0;i < 5;i++)
                operation->rd |= operation->bin[i + 7] << i;
            for(i = 0;i < 3;i++)
                operation->funct3 |= operation->bin[i + 12] << i;
            for(i = 0;i < 7;i++)
                operation->funct7 |= operation->bin[i + 25] << i;
            break;
        case: 0x13
            for( = 0;i < 5;i++)
                operation->rs1 |= operation->bin[i + 15] << i;
    }
}

int main(int argc, char **argv){
    decode(operation);
}
