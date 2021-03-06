//  -*- mode: c++; coding: utf-8; c-file-style: "stroustrup"; -*-

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits>
#include <set>
#include <stdio.h>
#include <queue>

#define DBG(x, arg...)       //x, ##arg

const double eps=1e-9;

using namespace std;

int main(int narg, char **arg)
{
    int t;
    cin >> t;
    for(int it=0; it<t; it++)
    {
        unsigned long long n;
        cin >> n;
        cout << "Case #" << (it+1) << ": " << ((n+1)*n/2+1) << endl;
    }
    return 0;


    // the code below was used to decode brainfuck phrase:
    /*
      +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++++++++++++++++++++++++++++++++++.++.+++++.-.>+[-]++++++
      ++++++++++++++++++++++++++.<-----------.++++++++++.>+[-]++++++++++++++++++++++++++++++++.<+.------------.---.>+[-]++++++++++++++++++++
      ++++++++++++.<+++++++++.+++++++.--------.-----------.+++.+++++++++++++.>+[-]++++++++++++++++++++++++++++++++.<---.---------.>+[-]+++++
      +++++++++++++++++++++++++++.<+++++++++++++.+.--.-----------------.++++++++.--.+.++++++++++++.>+[-]++++++++++++++++++++++++++++++++.<--
      ---------------.++++++++++++++++++.-.-.>+[-]++++++++++++++++++++++++++++++++.<------.------------.+++.+.>+[-]+++++++++++++++++++++++++
      +++++++.<+++++++++++++++.------------.++++++++++.---.++++++.--------------.+.>+[-]++++++++++++++++++++++++++++++++.<-------.>+[-]+++++
      +++++++++++++++++++++++++++.<+++++++++++++++++.---.++++++.-------.----------.>+[-]++++++++++++++++++++++++++++++++.<-.+++++.+++++++.--
      ----------.++++++++++++.---.-----------.+++++++++++++++++++.---------------.>+[-]++++++++++++++++++++++++++++++++.<--.--.++++++++++.--
      ----.>+[-]++++++++++++++++++++++++++++++++.<----.+++++++++++++.----------.>+[-]++++++++++++++++++++++++++++++++.<+++++++++++.++++++.-.
      ----.+++++.-.>+[-]++++++++++++++++++++++++++++++++.<-----------.++++++++++.>+[-]++++++++++++++++++++++++++++++++.<+.------------.---.>
      +[-]++++++++++++++++++++++++++++++++.<++++++++.------------.+++++++++++++++++++++++.---------------.++++.++++++++.--------.>+[-]++++++
      ++++++++++++++++++++++++++.<+.+++++++.--------.-----------.+++.+++++++++++++.>+[-]++++++++++++++++++++++++++++++++.<---.---------.>+[-
      ]++++++++++++++++++++++++++++++++.<---.--.++++++++++.------.>+[-]++++++++++++++++++++++++++++++++.<+++++++++++.-------.----.--.++.++++
      ++++++++++.>+[-]++++++++++++++++++++++++++++++++.<+.------------.-------.+++++++++++++++++++.>+[-]++++++++++++++++++++++++++++++++.<--
      ---------------.--.+++++++++++++.>+[-]++++++++++++++++++++++++++++++++.<------------.+++.>+[-]++++++++++++++++++++++++++++++++.<++++++
      +++++.++.---.-----------.+++++++++++++++++.------------------.++.-.------------------------------------------------------.
    */
    // into: Input is the number of straight cuts made through a round chocolate cake and output is the maximum number of cake pieces that can be produced.


    string prg;
    cin >> prg;
    int inst_size=2;

#if 0
    // try whitespace
    const char code[3]={'\t', ' ', '\n'};
    for(unsigned i=0; i<prg.size(); i+=inst_size)
    {
        if(prg[i]=='!') printf("%c", code[0]);
        else if(prg[i]=='.') printf("%c", code[1]);
        else if(prg[i]=='?') printf("%c", code[2]);
    }
    return 0;
#endif

    // brainfuck
    char code[8]={'+', // ok
                  ',',
                  '>',
                  '.', // ok
                  '-', // ok
                  '[',
                  '<',
                  ']'};
    //sort(code, code+8);
    for(unsigned i=0; i<prg.size(); i++)
    {
        if(prg[i]=='.') prg[i]=0; else if(prg[i]=='!') prg[i]=1; else prg[i]=2;
    }
    int iperm=0;
    do
    {
        printf("Perm: %d\n", iperm++);
        ofstream file("/tmp/kk.bf");
        for(unsigned i=0; i<prg.size(); i+=inst_size)
        {
            string new_inst=prg.substr(i, inst_size);
            int icode=new_inst[0]*3+new_inst[1];
            file << code[icode];
        }
        file.close();
        printf("{"); fflush(stdout); fflush(stderr);
        system("cat /tmp/kk.bf");
        printf("}\n"); fflush(stdout); fflush(stderr);
        printf("{"); fflush(stdout); fflush(stderr);
        system("beef /tmp/kk.bf");
        printf("}\n"); fflush(stdout); fflush(stderr);
        break;
    }
    while(next_permutation(code, code+8));
    return 0;
}
