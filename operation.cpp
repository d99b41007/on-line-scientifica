#include "operations.h"
#include <iostream>
#include <mmsystem.h>

using namespace std;

//in each operation I've add 2ms delay in the function

int buffersize=20; // declare for readout buffer or szbuffer Sep.22,2012

int Position_Zero(HANDLE serialport,Patchstar patch) // Zeroing the position
{
 //   char szBuff[20]={0},readout[20]={0};
    DWORD dwBytesWrite=0;//,dwBytesRead=0;

    if(patch.WriteFile_ZERO(serialport,dwBytesWrite)) {
        Position_report(serialport,patch);
        Delay(2);
    }
    else { cout << "Fail to Zeroing the file";}
 return 0;
}

int Position_report(HANDLE serialport,Patchstar patch) // report current position
{
   char readout[20]={" "};//szBuff[20]={0}
   DWORD dwBytesRead=0,dwBytesWrite=0;


    if(patch.WriteFile_POS(serialport,dwBytesWrite)) {
         Delay(2);
         patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);   // read data from serail port
         cout << endl << "Position = " << readout << endl;
         Delay(2);
        return 1;
    }
    else {
         cout << "Fail to read position";
         return 0;
    }

}

int Indentation_200(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout)
{
    patch.WriteFile_REL200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);
    Delay(400);
    patch.WriteFile_RELUP200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);
    Delay(5000);
 return 0;
}

int Indentation_200_slow(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout)
{
    patch.WriteFile_REL200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(400);
    Position_report(serialport,patch);
    Delay(400);
    patch.WriteFile_RELUP200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(400);
    Position_report(serialport,patch);
    Delay(28800);
 return 0;
}

int Indentation_200_nodelay(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout)
{
    timeBeginPeriod(1);
    patch.WriteFile_REL200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);
    Delay(400);
    patch.WriteFile_RELUP200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);
    Delay(5000);
    timeEndPeriod(1);
 return 0;
}



int Repeat_indentation(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
//  patch.WriteFile_STATUS(serialport,dwBytesWrite);
/*  delete at 2014-02-13
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    cout << "read=" << readout << endl;
    Delay(10);
 //   patch.WriteFile_TOP(serialport,dwBytesWrite,topspeed);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    cout << "Top_speed=" << readout << endl;
 //   patch.WriteFile_RELUP50(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(10);


    patch.WriteFile_REL10(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(10);
    Position_report(serialport,patch);
    Delay(100);
 */
    patch.WriteFile_RELUP_O_175(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(1000);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(500);
    Position_report(serialport,patch);
    Delay(10);

    return 0;
}


int Repeat_indentation_00(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}

int Repeat_indentation_25(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_175(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(175);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}


int Repeat_indentation_50(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_150(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(150);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}


int Repeat_indentation_75(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_125(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(125);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}


int Repeat_indentation_100(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_100(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(100);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}

int Repeat_indentation_100_slow(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_100(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(400);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200_slow(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}



int Repeat_indentation_100_nodelay(HANDLE serialport,Patchstar patch, int i)
{
    timeBeginPeriod(1);
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_100(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(100);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200_nodelay(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);
    timeEndPeriod(1);
    return 0;
}


int Repeat_indentation_125(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_75(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(75);
    Position_report(serialport,patch);

    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200(serialport,patch,dwBytesRead,dwBytesWrite,readout);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}

int On_line_monitoring (HANDLE serialport,Patchstar patch,long n)
{
/*    long tt;
    tt=GetTickCount();
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
 while(GetTickCount()-tt<n)
  {
        cout << "Time :" << GetTickCount() <<"start"<< endl;
        if(patch.WriteFile_POS(serialport,dwBytesWrite)) {
         patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);   // read data from serail port
          cout << "Position = " << endl << readout << endl;
          cout << "Time :" << endl << GetTickCount() <<"end"<< endl;
        }
        else {
         cout << "Fail to read position";
         return 0;
        }
        if ((GetTickCount()-tt)<=0) {

       tt=GetTickCount();
       }

  }*/
  return 0;
}

int Indentation_200_online(HANDLE serialport,Patchstar patch,DWORD dwBytesRead,DWORD dwBytesWrite, char* readout)
{
    patch.WriteFile_REL200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(400);
    patch.WriteFile_RELUP200(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Delay(200);
    Position_report(serialport,patch);
    Delay(100);
 return 0;
}
int Repeat_indentation_100_online(HANDLE serialport,Patchstar patch, int i)
{
    DWORD dwBytesRead=0,dwBytesWrite=0;
    char readout[buffersize];
    patch.WriteFile_RELUP_O_100(serialport,dwBytesWrite);
    patch.ReadFile_COMM(serialport,readout,buffersize,dwBytesRead);
    Position_report(serialport,patch);
    Delay(175);
    for(int repeated=i;repeated>0;repeated--) {
        Indentation_200_online(serialport,patch,dwBytesRead,dwBytesWrite,readout);
     Delay(2500);
    }

    patch.WriteFile_ABS_ZERO(serialport,dwBytesWrite);
    Delay(200);
    Position_report(serialport,patch);
    Delay(2);

    return 0;
}

