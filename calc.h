#include <iostream>
#include <math.h>
#include "pilha.h"

#define eps 0.000000000000001

#ifndef _CALC_H_
#define _CALC_H_

using namespace std;

class calc {
      private:
            float result; 
            PILHA * pilha;
            float r;
            int ok;
            
      public:
             calc(){
                  result = 0;
                  r = 0;
                  pilha = new PILHA();
                  ok = true;
             }
             
             ~calc(){
                  delete pilha; 
             }

             void add (char c[]) {
                  
                  if (c[0] == '='){
                     return;         
                  }
                  
                  float x,y;
                  if ( (c[0] == '+' || c[0] == '-' || c[0] == '*'|| c[0] == '/') && (c[1] == '\0')) {
                         x = pilha->pop();
                         y = pilha->pop(); 
                         
                         switch (c[0]){
                                case '+': r = (x+y);
                                          break;       
                         
                                case '-': r = (x-y);
                                          break;
                                          
                                case '*': r =(x*y);
                                          break;
                                          
                                case '/': if (x == 0) {
                                             ok = false;
                                          }
                                          else {
                                             r = (x/y);
                                          }
                                          break;
                         }
                         pilha->push(r);
                  }
                  
                  else if ( (c[0] == 'r' || c[0] == 'l') && (c[1] == '\0')) {
                         x = pilha->pop();
                         if (x >= 0) {
                             float r;
                             switch (c[0]){
                                    case 'l': if (x != 0) {
                                                 r = log(x);
                                              }
                                              else {
                                                 ok = false;
                                              }   
                                              break;       
                                    case 'r': r = sqrt(x);
                                              break;         
                             }      
                             pilha->push(r);
                         }
                         
                         else {
                              ok = false;
                         }
                  }
                  
                  else {
                       pilha->push(atof(c));
                  }
                  
             }
             
             float eq() {
                  if (ok == true) {
                     result = pilha->top();
                     return (result);         
                  }
                  else {
                       cout << "ERRO: Operacao invalida" << endl;
                       return (0);
                  } 
             }  
};

#endif
