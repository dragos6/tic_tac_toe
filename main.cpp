#include <iostream>
#include <stdlib.h>
#include "joc.h"


using namespace std;

int main()
{
    int k;
    joc xo;
    while(true)
          {
              xo.startgame();
             cout<<"\n\n\x1b[0m                  Press 1 to play again\n";
             cin>>k;
             if(k==1)xo.reset();

          }
}
