/*
--------------------------------------------------------------------------------

  Primeiro Trabalho de P.O.O.
  Luiz Henrique Cherri       N�mero USP: 5991829
  
================================================================================

  ENTRADA:
           Digite a express�o separando n�meros e opera��es com espa�os
      ou quebra de linha. Quando tiver dogitado toda a express�o pessine '='
           EX: '1 1 1 + + =' imprimir� 3
       
  OBS: 
       O algoritmo foi compilado em Windows utilizando o compilado 'DEV C++'
       
--------------------------------------------------------------------------------
*/


#include "calc.h"

int main (){
    calc * a = new calc();
    
    cout << " ---- MENU LIST ----"  << endl;
    cout << " '+' Soma"          << endl << " '-' Subtracao"     << endl;
    cout << " '/' Divisao"       << endl << " '*' Multiplicacao" << endl;
    cout << " 'r' Raiz quadrada" << endl << " 'l' Logaritimo"    << endl << endl;
    cout << " OBS: Ao acabar de digitar a expresao presione '='"  << endl << endl;
    
    
    
    char x[20] = "1";
    cout << ">> ";
    
    while (x[0] != '=') {
        cin >> x;
        a->add (x);
    }

    cout << "\n\nResultado = " << a->eq() << endl;
    
    delete (a);
    
    cin >> x;
}
