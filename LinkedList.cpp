#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
    lista = nullptr;
    numnos = 0;
};

LinkedList::~LinkedList(){
    while(!vazia())     // destrutoi tudo
        remove();
};

// insere no FIM da fila -> LinkedList 
void LinkedList::insere(TipoDado x){
    No *novono = new No;
    novono->info = x;
    if(!vazia()){
        novono->prox = lista->prox; // aponta para o inicio
        lista->prox = novono;       // antigo fim aponta para novo fim
    } else novono->prox = novono;   // caso especial (1° nó)
    
    lista = novono;                 // antigo fim passa a ser o novo fim
    ++numnos;
};

TipoDado LinkedList::remove(){
    TipoDado aux;
    if(!vazia()){
        No *rem = lista->prox;
        lista->prox = rem->prox;
        aux = rem->info;
        delete rem;
        --numnos;
        if(numnos == 0) lista = nullptr;
    } else std::cerr << "lista vazia" << std::endl;
    return aux;
};

void LinkedList::imprime() const {
    if(!vazia()){
        No *temp = lista->prox;
        while(temp != lista){
            std::cout << temp->info << " ";
            temp = temp->prox;
        }
        std::cout << temp->info << std::endl;
    }
};