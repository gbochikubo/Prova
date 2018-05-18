#include <iostream>
#include <cstdlib> 

using namespace std;
typedef int Dado;

class noh{
    friend class fila;
    private:
        noh* proximo;
        Dado valor;
    public:
        noh(Dado v);
};

noh :: noh(Dado v){
    this->proximo = NULL;
    this->valor = v;
}

class fila{
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        fila();
        ~fila();
        void enfilera(Dado v);
        inline bool vazia();
        Dado desenfilera();
        void empilha(Dado v);
        Dado desempilha();
        int getTamanho();
        
};

fila :: fila(){
    this->primeiro = NULL;
    this->ultimo = NULL;
    this->tamanho = 0;
}

fila :: ~fila(){
    while(primeiro != NULL){
        noh* aux = primeiro;
        primeiro = primeiro->proximo;
        delete aux;
    }
}

inline bool fila :: vazia(){
    return primeiro == NULL;
}

void fila :: enfilera(Dado v){
    noh* novo = new noh(v);
    if (vazia()){
        primeiro = novo;
        ultimo = novo;
    }
    else {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

Dado fila :: desenfilera(){

    if(not vazia()){
        Dado aux;
    if(primeiro == ultimo){
        noh* temp = primeiro;
        primeiro = NULL;
        ultimo = NULL;
         aux = temp->valor;
        delete temp;
    }
    else {
       noh* temp = primeiro;
        primeiro = primeiro->proximo;
        aux = temp->valor;
        delete temp;
    }
    tamanho--;
    return aux;
    }
    else {
        cerr << "FILA VAZIA" << endl;
        exit(EXIT_FAILURE);
    }
}
        
void fila :: empilha (Dado v){
    enfilera(v);
}

int fila :: getTamanho(){
    return tamanho;
}

Dado fila :: desempilha(){
    fila aux;
    int tam = getTamanho();
    for(int i = 0; i < tam-1; i++){
       noh temp = desenfilera();
       Dado x = temp.valor;
       aux.enfilera(x);
    }
    int tamAux = aux.getTamanho();
    noh temp = desenfilera();
    Dado x = temp.valor;
    for(int i = 0; i < tamAux; i++){
        noh temp = aux.desenfilera();
        int auxiliar = temp.valor;
        enfilera(auxiliar);
    }
    return x;
}
    
int main () {
    
    fila f;
    f.enfilera(1);
    f.enfilera(2);
    f.enfilera(3);
    f.enfilera(4);
    f.enfilera(5);
    //~ cout << f.desempilha();
    for(int i = 0 ; i <5 ; i++){
    cout << f.desempilha() << endl;
}
    return 0;
}


    
