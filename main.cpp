#include <iostream>
#include "operations.h"


using namespace std;




int main() {

   Patchstar patch;
    HANDLE serialport;
    serialport=open_commport();
   Position_Zero(serialport,patch);

    Repeat_indentation_100_slow(serialport,patch,3);

   CloseHandle(serialport);

   return 0;
}
