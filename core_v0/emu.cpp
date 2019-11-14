//                                  //
//      TODO 符号拡張!!!!!          //
//                                  //

#include<iostream>
#include<vector>
#include<bitset>

uint32_t reg[32];
uint32_t pc = 0;
uint32_t memory[] = {0x00000113, 0x00000193, 0x00640093, 0x00110113, 0x002181b3, 0xfe111ce3, 0x0000026f};

//1111 1110 0001 0001 0001 1111 1 110 0011
//1011 0011
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
Operation *operation = new Operation;

void fetch(Operation *operation){
    printf("pc = %x\n", pc*4);
    operation->bin = memory[pc];
}

void decode(Operation *operation){
    int i;
    for(i = 0;i < 7;i++){
        operation->opcode |= (operation->bin[i] << i);
    }

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
                operation->imm |= (operation->bin[i + 20] << i);
            //printf("rs1     = %d\n", operation->rs1);
            //printf("rd      = %d\n", operation->rd);
            //printf("funct3  = %d\n", operation->funct3);
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
        case 0x73:
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
    switch(operation->opcode){
        case 0x33:
            switch(operation->funct3){
                case 0x00:
                    reg[operation->rd] = reg[operation->rs1] + reg[operation->rs2];
                    pc++;
                    break;
                case 0x07:
                    reg[operation->rd] = reg[operation->rs1] & reg[operation->rs2];
                    pc++;
                    break;
                case 0x06:
                    reg[operation->rd] = reg[operation->rs1] | reg[operation->rs2];
                    pc++;
                    break;
                case 0x04:
                    reg[operation->rd] = reg[operation->rs1] ^ reg[operation->rs2];
                    pc++;
                    break;
            }
        break;
        case 0x03:
            switch(operation->funct3){
                case 0x02:
                    reg[operation->rd] = memory[operation->rs1 + operation->imm];
                    pc++;
                    break;
            }
        break;
        case 0x13:
            switch(operation->funct3){
                case 0x00:
                    reg[operation->rd] = operation->imm + reg[operation->rs1];
                    pc++;
                    break;
                case 0x07:
                    reg[operation->rd] = operation->imm & reg[operation->rs1];
                    pc++;
                    break;
                case 0x06:
                    reg[operation->rd] = operation->imm | reg[operation->rs1];
                    pc++;
                    break;
                case 0x04:
                    reg[operation->rd] = operation->imm ^ reg[operation->rs1];
                    pc++;
                    break;
            }
        break;
        case 0x23:
            switch(operation->funct3){
                case 0x02:
                    memory[reg[operation->rs1] + operation->imm] = reg[operation->rs2];
                    pc++;
                    break;
            }
        break;
        case 0x6f:
            reg[operation->rd] = pc + 1;
            pc = (uint32_t)(operation->imm / 4);
        break;
        case 0x73:
            if(reg[operation->rs1] == reg[operation->rs2]){
                pc += (uint32_t)(operation->imm / 4);
                printf("operation->imm / 4 = %x\n", (uint32_t)(operation->imm / 4));
            }else{
                pc++;
            }
        break;
    }
}

int main(int argc, char **argv){
    unsigned int cnt = 0;
    while(cnt != 10){
        fetch(operation);
        decode(operation);
        execute(operation);
        cnt++;
    }
    for(int i = 0;i < 32; i++){
        printf("reg[%d] = %d\n", i, reg[i]);
    }
    return 0;
}
