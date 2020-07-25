module spi_driver_top(
    input   logic   clk,
    output  logic   SCLK,
    output  logic   MOSI,
    input   logic   MISO,
    output  logic   SS,
    output  logic   [7:0] read_data
);

    spi_driver spi_driver(
        .clk        (clk        ),
        .SCLK       (SCLK       ),
        .MOSI       (MOSI       ),
        .MISO       (MISO       ),
        .SS         (SS         ),
        .read_data  (read_data  )
    );

endmodule
