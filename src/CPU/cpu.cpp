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


  //Increment
  case Ins::INC_A: Inc(Regs.a); Regs.pc++; break;
  case Ins::INC_B: Inc(Regs.b); Regs.pc++; break;
  case Ins::INC_C: Inc(Regs.c); Regs.pc++; break;
  case Ins::INC_D: Inc(Regs.d); Regs.pc++; break;
  case Ins::INC_E: Inc(Regs.e); Regs.pc++; break;
  case Ins::INC_H: Inc(Regs.h); Regs.pc++; break;
  case Ins::INC_L: Inc(Regs.l); Regs.pc++; break;
  case Ins::INC_BC: Inc(Regs.b,Regs.c); Regs.pc++; break;
  case Ins::INC_DE: Inc(Regs.d,Regs.e); Regs.pc++; break;
  case Ins::INC_HL: Inc(Regs.h,Regs.l); Regs.pc++; break;
  case Ins::INC_SP: Inc(Regs.sp); Regs.pc++; break;
  //Decrement
  case Ins::DEC_A: Dec(Regs.a); Regs.pc++; break;
  case Ins::DEC_B: Dec(Regs.b); Regs.pc++; break;
  case Ins::DEC_C: Dec(Regs.c); Regs.pc++; break;
  case Ins::DEC_D: Dec(Regs.d); Regs.pc++; break;
  case Ins::DEC_E: Dec(Regs.e); Regs.pc++; break;
  case Ins::DEC_H: Dec(Regs.h); Regs.pc++; break;
  case Ins::DEC_L: Dec(Regs.l); Regs.pc++; break;
  case Ins::DEC_BC: DEC(Regs.b,Regs.c); Regs.pc++; break;
  case Ins::DEC_DE: DEC(Regs.d,Regs.e); Regs.pc++; break;
  case Ins::DEC_HL: DEC(Regs.h,Regs.l); Regs.pc++; break;
  case Ins::DEC_SP: DEC(Regs.sp); Regs.pc++; break;
  
  default:
    Regs.pc++;
    break;
  }

}

Byte cpu::fetch(){

  Byte byte;

  return byte;
}

void cpu::setFlag(char bit,bool value){

  Regs.f &= ~(1 << bit); // Clear Bit

  if(value)
    Regs.f ^= (1 << bit); // Set Bit
}

bool cpu::getFlag(char bit){
  return (Regs.f >> bit) & 1;
}

//Instructions
void cpu::Inc(Byte &reg){
  setFlag(Instructions::flag::H,halfCarryBitCheck(reg,1));
  reg++;
  setFlag(Instructions::flag::Z,reg==0);
  setFlag(Instructions::flag::N,0);
  }

void cpu::Inc(Byte& regLow,Byte& regHigh){


}

void cpu::Dec(Byte& reg){
  
  setFlag(Instructions::flag::H,halfCarryBitCheck(reg,1));
  reg--;
  setFlag(Instructions::flag::Z,reg==0);
  setFlag(Instructions::flag::N,1);
}

void cpu::Dec(Byte& regLow,Byte& regHigh){


}