namespace Instructions{

  enum flag{
    Z = 7,
    N = 6,
    H = 5,
    C = 4
  };

  enum opcodes{
    IncA = 0x3C, // Increment A by 1
    IncB = 0x04, // Increment B by 1
    IncC = 0x0C, // Increment C by 1
    IncD = 0x14, // Increment D by 1
    IncE = 0x1C, // Increment E by 1
    IncH = 0x24, // Increment H by 1
    
  };  
  
} // namespace Instruction
