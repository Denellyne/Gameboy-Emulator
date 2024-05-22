#pragma once
#include <cstring>

typedef char  Byte;
typedef short Word;

struct Registers{

  /*
  a -> Accumulator
  f -> Flag Register
  sp -> Stack Pointer
  pc -> Program Counter
  Others are normal registers
  */
  Byte a,f,b,c,d,e,h,l;
  Word sp,pc;

  Registers(){
    resetRegisters();
  }

  void resetRegisters(){
    a=f=b=c=d=e=h=l=0;
    pc = 0x100;
    sp = 8191;  
  }

};

struct Memory{
  
  Memory(){
    resetMemory();
  }

  void resetMemory(){
    memset(ram,0,8192);
    memset(vRam,0,8192);
  }

  Byte ram[8192],vRam[8192];

};

class cpu{
public:

  cpu();

  void execute();
  void reset();

private:
  Memory Mem;
  Registers Regs;

  void setFlag(char bit,bool value);
  bool getFlag(char bit);

  Byte fetch();

  void Inc(Byte& reg);
  void Inc(Word& reg);
  void Inc(Byte& regLow,Byte& regHigh);

  void Dec(Byte& reg);
  void Dec(Word& reg);
  void Dec(Byte& regLow,Byte& regHigh);

};
