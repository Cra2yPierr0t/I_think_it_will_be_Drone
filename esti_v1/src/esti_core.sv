module esti_core(
        output logic [63:0] posi_out,
        input  logic [15:0] acc_in,
        input  logic    clk,
        input  logic    reset
    );

    typedef struct packed{
        logic [63:0] posi;
        logic [63:0] v;
    } state;
    
    state t0, t1;
    logic [63:0] acc;

    always_comb begin
        t1.posi = t0.posi + {acc[63], acc[63:1]} + t0.v; //位置推定, accを右シフト
        t1.v    = t0.v + acc;                            //速度推定
    end

    always_ff @(posedge clk, posedge reset) begin
        if(reset) begin
            t0.posi     <= 64'h0000000000000000;
            t0.v        <= 64'h0000000000000000;
            acc         <= 64'h0000000000000000;
            posi_out    <= 64'h0000000000000000;
        end else begin
            t0.posi     <= t1.posi;
            t0.v        <= t1.v;
            acc         <= {acc_in[15] ? 48'hffffffffffff : 48'h000000000000, acc_in}; //符号拡張
            posi_out    <= t1.posi;
        end
    end
endmodule
