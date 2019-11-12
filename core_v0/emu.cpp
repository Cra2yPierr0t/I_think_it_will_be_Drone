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
    uint8_t opcode = 0;
    uint8_t rs1 = 0;
    uint8_t rs2 = 0;
    uint8_t rd = 0;
    uint8_t funct3 = 0;
    uint8_t funct7 = 0;
    uint32_t imm = 0;
    Operation *next;//次の命令
};

//現在着目してる命令
Operation *operation;

void fetch(Operation *operation){
    operation->bin = memeory[pc];
}

void decode(Operation *operation){
    int i;
    for(i = 0;i < 7;i++)
        operation->opcode |= operation->bin[i];

    switch(operation->opcode){
        case 0x33:
            operation->format = R_type;
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
        case 0x13:
        case 0x03:
            operation->format = I_type;
            for(i = 0;i < 5;i++)
                operation->rs1 |= operation->bin[i + 15] << i;
            for(i = 0;i < 5;i++)
                operation->rd |= operation->bin[i + 7] << i;
            for(i = 0;i < 3;i++)
                operation->funct3 |= operation->bin[i + 12] << i;
            for(i = 0;i < 12;i++)
                operation->imm |= operation->bin[i + 25] << i;
            break;
        case 0x23:
            operation->format = S_type;
            for(i = 0;i < 5;i++)
                operation->rs1 |= operation->bin[i + 15] << i;
            for(i = 0;i < 5;i++)
                operation->rs2 |= operation->bin[i + 20] << i;
            for(i = 0;i < 3;i++)
                operation->funct3 |= operation->bin[i + 12] << i;
            for(i = 0;i < 5;i++)
                operation->imm |= operation->bin[i + 7] << i;
            for(i = 0;i < 7;i++)
                operation->imm |= operation->bin[i + 25] << (i + 5);
            break;
        case 0x6f:
            operation->format = J_type;
            for(i = 0;i < 5;i++)
                operation->rd |= operation->bin[i + 7] << i;
            for(i = 0;i < 8;i++)
                operation->imm |= operation->bin[i + 12] << (i + 12);
            for(i = 0;i < 10;i++)
                operation->imm |= operation->bin[i + 20] << (i + 1);
            operation->imm |= operation->bin[19] << 11;
            operation->imm |= operation->bin[31] << 20;
            break;
        case 0x63:
            operation->format = B_type;
            for(i = 0;i < 5;i++)
                operation->rs1 |= operation->bin[i + 15] << i;
            for(i = 0;i < 5;i++)
                operation->rs2 |= operation->bin[i + 20] << i;
            for(i = 0;i < 3;i++)
                operation->funct3 |= operation->bin[i + 12] << i;
            operation->imm |= operation->bin[7] << 11;
            for(i = 0;i < 4;i++)
                operation->imm |= operation->bin[i + 8] << (i + 1);
            for(i = 0;i < 6;i++)
                operation->imm |= operation->bin[i + 25] << (i + 5);
            operation->imm |= operation->bin[31] << 12;
            break;
    }
}

void execute(Operation *operation){
    
}

int main(int argc, char **argv){
    while(1){
        fetch(operation);
        decode(operation);
        execute(operation);
        writeback(operation);
    }
}
