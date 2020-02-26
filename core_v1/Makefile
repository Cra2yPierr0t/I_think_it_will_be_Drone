verilog = alu_decoder.v computer.v branch_controller.v csr_controller.v regfile.v alu.v csr_regfile.v main_decoder.v cpu.v main_controller.v IO/LED8.v IO/Button.v test_bench.v data_mem.v instr_mem.v IO/tx.v IO/rx.v IO/UART.v
output = computer
top = test_bench
wave = wave.vcd

all: $(verilog)
	iverilog -o $(output) -s $(top) $(verilog)
	vvp $(output)

$(wave):
	make all

$(build):
	make all

wave: $(wave)
	gtkwave $(wave) &

build: $(build)
	riscv64-linux-gnu-gcc -c -march=rv32i -mabi=ilp32 -nostdlib -nodefaultlibs -nostartfiles -nolibc -O0 ./prog/*.s
	riscv64-linux-gnu-gcc -static -T ./prog/ld.scr -L. -march=rv32i -mabi=ilp32 -nostdlib -nodefaultlibs -nostartfiles -Wl,--build-id=none -nolibc -O0 *.o
	riscv64-linux-gnu-objdump -D a.out

clean:
	rm $(output) $(wave) a.out *.o
