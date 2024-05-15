#include "cpu.h"
#include "opcodes.h"

#define halfCarryBitCheck(x,y) ((((x & 0xF) + (y & 0xF)) & 0x10) == 0x10)

cpu::cpu(){}

void cpu::reset(){
  Mem.resetMemory();
  Regs.resetRegisters();
}

void cpu::execute(){  
  
  typedef Instructions::opcodes Ins;

  Byte opcode = fetch();
  
  switch (opcode){
  case Ins::IncA: Inc(Regs.a); Regs.pc++; break;
  case Ins::IncB: Inc(Regs.b); Regs.pc++; break;
  case Ins::IncC: Inc(Regs.c); Regs.pc++; break;
  case Ins::IncD: Inc(Regs.d); Regs.pc++; break;
  case Ins::IncE: Inc(Regs.e); Regs.pc++; break;
  case Ins::IncH: Inc(Regs.h); Regs.pc++; break;
  
  default:
    Regs.pc++;
    break;
  }

}

Byte cpu::fetch(){

  Byte byte;

  return byte;
}

void cpu::setFlag(char Bit,bool value){

  Regs.f &= ~(1 << Bit); // Clear Bit

  if(value)
    Regs.f ^= (1 << Bit); // Set Bit
}

bool cpu::getFlag(char Bit){
  return (Regs.f >> Bit) & 1;
}



//Instructions
void cpu::Inc(Byte &Reg){

  Reg++;
  setFlag(Instructions::flag::Z,Reg==0);
  setFlag(Instructions::flag::N,0);
  setFlag(Instructions::flag::H,halfCarryBitCheck(Reg-1,1));
  }

