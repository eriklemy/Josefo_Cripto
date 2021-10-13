#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

using TipoDado = char;

struct No {
    TipoDado info;
    No *prox;
};

class LinkedList {
    public:
        LinkedList();                   // construtor
        ~LinkedList();                  // destrutor
        // modificador
        void insere(TipoDado x);        // ok
        TipoDado remove();              // ok  
        // seletores 
        bool vazia() const { return (lista == nullptr); };      // lista->prox == lista;
        TipoDado frente() const { return lista->info; };    
        unsigned int tam() const { return numnos; };            // ok
        void imprime() const;                                   // ok
    
    private:
        No *lista;
        unsigned int numnos;
};

#endif // !_LINKEDLIST_H
