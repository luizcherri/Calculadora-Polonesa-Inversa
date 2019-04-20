#include <stdlib.h>

#ifndef _PILHA_H_
#define _PILHA_H_

class PILHA {
      private:
              float *p;
              int cont;
      public:
             PILHA(){
                     cont = 0;
                     p = NULL;      
             }
             
             ~PILHA(){
                      free (p);         
             }
               
             void push (float c){
                   cont++;
                   p = (float *) realloc (p , sizeof(float)*cont);
                   p[cont-1] = c;           
             }
             
             float pop (){
                   cont--;
                   float x = p[cont];
                   p = (float *) realloc (p , sizeof(float)*cont);
                   return (x);    
             }
             
             float top (){
                  return (p[cont - 1]);    
             }
             
             int size (){
                 return (cont);
             }
};

#endif
