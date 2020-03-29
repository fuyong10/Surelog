module and_tb(output logic o); 
  logic a, b;
  assign o = a & b;
   
  initial begin
    $monitor("@%0dns %0d & %0d = %0d",$time,a, b, o);
    #100 $finish();
  end
  
  initial 
  begin 
     a = 1'b0;
     b = 1'b0;
     #5
     a = 1'b0;
     b = 1'b1; 
     #5
     a = 1'b1;
     b = 1'b0;  
     #5
     a = 1'b1;
     b = 1'b1;  
  end 
    
endmodule
