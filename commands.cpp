#include <iostream>
#include "commands.h"
#include <windows.h>
#include <winbase.h>
#include <string>


int Patchstar::ReadFile_COMM(void* serialport,char* readout,int n,DWORD dwBytesRead) {
  if(!ReadFile(serialport,readout,n,&dwBytesRead,NULL)){
   std::cout << "Fail to read commport" << std::endl;
   return 0;
  }
  else{
  std::cout << std::endl;
  return 1;
  }
}

int Patchstar::WriteFile_POS(void* serialport,DWORD dwBytesWrite) {
  char write_pos[]= {'P',0x0d};
  if(!WriteFile(serialport,write_pos,2,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "POS transmit complete." << std::endl;
   return 1;
  }
}


int Patchstar::WriteFile_ZERO(void* serialport,DWORD dwBytesWrite) {
  char write_zero[Patchstar::Transmission_space]= {'Z','E','R','O',0x0d};
  if(!WriteFile(serialport,write_zero,5,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "ZERO transmit complete." << std::endl;
   return 1;
  }
}


int Patchstar::WriteFile_RELUP50(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 500 "};
  write_rel[12]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,13,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_RELUP100(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1000 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}
int Patchstar::WriteFile_RELUP_O_100(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1000 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}
int Patchstar::WriteFile_RELUP_O_75(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 750 "};
  write_rel[12]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=750 from original place.
  if(!WriteFile(serialport,write_rel,13,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_RELUP_O_150(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1500 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}
int Patchstar::WriteFile_RELUP_O_125(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1250 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1250 from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_RELUP_O_175(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1750 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1750 from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_RELUP_X_10(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 1400 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_REL10(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 -10 "};
  write_rel[12]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,13,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}


int Patchstar::WriteFile_REL200(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 -2000 "};
  write_rel[14]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,15,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_RELUP200(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"REL 0 0 2000 "};
  write_rel[13]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,14,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

/*

int Patchstar::WriteFile_REL_sum(void* serialport,DWORD dwBytesWrite, int typenumber){
 char write_rel[Patchstar::Transmission_space][Patchstar::Transmission_space]={'0'};
    for(int fill=0; fill<Patchstar::Transmission_space;fill++) {
    //fill up the array with REL
      write_rel[fill][0]= {'R'};
      write_rel[fill][1]= {'E'};
      write_rel[fill][2]= {'L'};
      write_rel[fill][3]= {' '};
    }
    return 1;
}

*/


int Patchstar::WriteFile_ABS_ZERO(void* serialport,DWORD dwBytesWrite) {
  char write_rel[Patchstar::Transmission_space]={"ABS 0 0 0 "};
  write_rel[10]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command moves manipulator to the relative position d(X)=0 d(Y)=0 d(z)=1k from original place.
  if(!WriteFile(serialport,write_rel,11,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "REL transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_TOP(void* serialport,DWORD dwBytesWrite,int topspeed) {
  char write_rel[Patchstar::Transmission_space]={"TOP 3000 "};
  write_rel[9]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command set a top speed for the manipulator.
  if(!WriteFile(serialport,write_rel,10,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "TOP transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_ACC(void* serialport,DWORD dwBytesWrite,int topspeed) {
  char write_rel[Patchstar::Transmission_space]={"ACC 10 "};
  write_rel[7]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command set a acceleration for the manipulator.
  if(!WriteFile(serialport,write_rel,8,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "ACC transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_FIRST(void* serialport,DWORD dwBytesWrite,int topspeed) {
  char write_rel[Patchstar::Transmission_space]={"FIRST 10 "};
  write_rel[10]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command set a top speed for the manipulator.
  if(!WriteFile(serialport,write_rel,11,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "TOP transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_CURRENT(void* serialport,DWORD dwBytesWrite,int topspeed) {
  char write_rel[Patchstar::Transmission_space]={"CURENT 10 "};
  write_rel[10]=0x0d;

  std::cout << "Transmitted signal was " << write_rel << std::endl;
  // This command set a top speed for the manipulator.
  if(!WriteFile(serialport,write_rel,11,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "TOP transmit complete." << std::endl;
   return 1;
  }
}

int Patchstar::WriteFile_STATUS(void* serialport,DWORD dwBytesWrite) {
  char write_pos[]= {'S',0x0d};
  if(!WriteFile(serialport,write_pos,2,&dwBytesWrite,NULL)) {
   std::cout << "Fail to finish transmition command.";
   return 0;
  }
  else {
   std::cout << "STATUS transmit complete." << std::endl;
   return 1;
  }
}

int Delay(int n) {
/* long tt;
 tt=GetTickCount();
 while(GetTickCount()-tt<n)
  {
   if ((GetTickCount()-tt)<=0)
   tt=GetTickCount();
  }
*/
  Sleep(n);
  return 0;
}
