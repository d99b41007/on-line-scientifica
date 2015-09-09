#include <string.h>
#include <windows.h>

#ifndef COMMAND_H
#define COMMAND_H


class Patchstar {

 public:

int ReadFile_COMM(void*,char*,int,DWORD);
int WriteFile_POS(void*,DWORD);
int WriteFile_ZERO(void*,DWORD);
int WriteFile_REL200(void*,DWORD);
int WriteFile_RELUP200(void*,DWORD);
int WriteFile_REL10(void*,DWORD);
int WriteFile_RELUP100(void*,DWORD);
int WriteFile_RELUP_X_10(void*,DWORD);
int WriteFile_RELUP_O_75(void*,DWORD);
int WriteFile_RELUP_O_100(void*,DWORD);
int WriteFile_RELUP_O_150(void*,DWORD);
int WriteFile_RELUP_O_125(void*,DWORD);
int WriteFile_RELUP_O_175(void*,DWORD);
int WriteFile_RELUP50(void*,DWORD);
int WriteFile_ABS_ZERO(void* serialport,DWORD dwBytesWrite);
int WriteFile_TOP(void*,DWORD,int);
int WriteFile_ACC(void*,DWORD,int);
int WriteFile_FIRST(void*,DWORD,int);
int WriteFile_CURRENT(void*,DWORD,int);
int WriteFile_Move(void*,DWORD);
int WriteFile_STATUS(void*,DWORD);
// int WriteFile_REL_sum(void*,DWORD,int);
static const int Transmission_space = 20;

};

int Delay(int n);

#endif
