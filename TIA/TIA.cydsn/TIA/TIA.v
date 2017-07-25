
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 06/27/2017 at 13:06
// Component: TIA
module TIA (
	output  AO,
	input  [3:0] AUDC,
	input  [4:0] AUDF,
	input   CLK,
	input   CNT
);

//`#start body` -- edit after this line, do not edit this line

    reg [4:0] dvdr; //: unsigned(4 downto 0) := "00000";
    reg [3:0] sr4;//: std_logic_vector(3 downto 0) := "0000";
    reg [4:0] sr5;//: std_logic_vector(4 downto 0) := "00000";
    wire sr5_tap;
    wire sr4_in;   
    wire sr5_in;       
    wire sr4_cnt;  
    wire sr5_cnt;  

    always @ (posedge CLK)
    begin 
        if (CLK) begin           
            if (CNT) begin                 
                if (sr4_cnt) begin 
                    sr4 <= {sr4_in,sr4[3:1]};
                end
                if (sr5_cnt) begin 
                    sr5 <= {sr5_in,sr5[4:1]};
                end             
                if (dvdr == (AUDF)) begin 
                    dvdr <= "00000";
                end
                else begin 
                    dvdr <= dvdr + 1;
                end
            end
        end                     
    end    
    
     
    assign sr5_in = (
                    (AUDC == 4'b0000)|
                    (sr5_tap)|
                    (sr5 == 5'b00000 & ((AUDC[0])|(AUDC[1])|(sr4 == 4'b1111)))
                    ) ? 1:0;
       // begin
       // sr5_in <= 1;
       // end
       // else begin 
       // sr5_in <= 1;
       // end
        
    assign sr4_in = (
                    (AUDC == 4'b0000)|
                    (AUDC[3:2] == 2'b00 & (sr4 == 4'b1111 | ((sr4[1] ~^ sr4[0]) == 1)))|
                    (AUDC[3:2] == 2'b11 & (sr4[3:1] == 3'b101 | sr4[1] == 0))|
                    (AUDC[3:2] == 2'b01 & sr4[3] == 0)|
                    (AUDC[3:2] == 2'b10 & sr5[0] == 1)
                    ) ? 1:0;
       // else '0';
    
    assign sr5_tap = (AUDC[1:0] == 2'b00) ? sr5[0] ^ sr4[0] : sr5[0] ^ sr5[3];             
    
    assign sr5_cnt = (dvdr == AUDF) ? 1:0; //else '0';  -- CHECKME
        
    assign sr4_cnt =  
            (dvdr == AUDF & 
            ((AUDC[1:0] == 2'b10 & sr5[4:1] == 4'b0001) | 
            (AUDC[1:0] == 2'b11 & sr5[0] == 1)|
            (AUDC[1] == 0)))
             ? 1:0;
      //  else '0';
        
    assign AO = sr4[0];

//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
