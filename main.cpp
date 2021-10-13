#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;
void cripto(LinkedList &lista, int M);
void decripto(LinkedList &cripto, int M);

int main(){    
    int M;
    string nome;
    LinkedList lista; 

    cout << "digite o nome do arquivo.txt: " << endl; 
    cin >> nome; 

    cout << "digite o valor de M: " << endl; 
    cin >> M; 
    
    char ch;
    ifstream fIn(nome);
    if(fIn) {
        while(fIn.get(ch)){
            if(ch != '\n')
                lista.insere(ch);
            else cripto(lista, M);
        }
    } else cout << "arquivo nao encontrado!!" << endl;
    fIn.close();
   
    char c;
    LinkedList dcripto;
    cout << "\nsaida decripto: " << endl;
    ifstream jcripto("arq.jcripto");
    if(jcripto){
        while(jcripto.get(c)){
            if(c != '\n')
                dcripto.insere(c);
            else decripto(dcripto, M);
        }
    }
    jcripto.close();
}

// completo
void cripto(LinkedList &lista, int M){
    ofstream fOut("arq.jcripto", ofstream::app);
    while(!lista.vazia()){
        for (int i = 0; i < M - 1; i++)
			lista.insere(lista.remove());
        fOut << lista.remove();
    }
    fOut << "\n";
    fOut.close();
}

// em progresso
void decripto(LinkedList &cripto, int M){
    while(!cripto.vazia()){
        for (int i = 0; i < M*2; i++){
			cripto.insere(cripto.remove());
        }
        cout << cripto.remove();
    }
    cout << endl;
}