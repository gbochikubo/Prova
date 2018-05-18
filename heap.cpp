#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Dado;

class MaxHeap{
    private:
        int _tamanho;
        int _capacidade;
        Dado *dado;
        void arruma();
        void corrigeDescendo(int i);
        void corrigeSubindo(int i);
    public:
        MaxHeap(int cap);
        MaxHeap(Dado vet[], int tam, int cap = 0);
        ~MaxHeap();
        int pai(int i);
        int esquerdo(int i);
        int direito(int i);
        Dado espiaRaiz();
        void insere(Dado d);
        inline bool cheio();
        inline bool vazio();
        Dado retiraRaiz();
       // void heapSort(Dado vet[],int tam);
        void imprime();
};

MaxHeap :: MaxHeap(int cap){
    this->_tamanho = 0;
    this->_capacidade = cap;
    dado = new Dado[_capacidade];
   
} 

MaxHeap :: MaxHeap(Dado vet[], int tam, int cap){
    if(cap == 0){
        _capacidade = tam;
    }
    else {
        _capacidade = cap;  
        
    }
    _tamanho = 0;
   dado = new Dado[_capacidade];
   for(int i = 0; i < tam; i++){
       dado[i] = vet[i];
       _tamanho ++;
   }
   arruma();
   
}

MaxHeap :: ~MaxHeap(){
    delete[] dado;
}

int MaxHeap:: pai(int i){
    return (i-1)/2;
}

int MaxHeap :: direito(int i){
    return (2*i)+2;
}

int MaxHeap :: esquerdo(int i){
    return (2*i)+1;
}

void MaxHeap :: corrigeDescendo(int i){
    int esq = esquerdo(i);
    int dir = direito (i);
    int maior = i;
    if((esq < _tamanho) and (dado[esq] > dado[i])){
        maior = esq;
    }
    if((dir < _tamanho) and (dado[dir] > dado[maior])){
        maior = dir;
    }
    if(maior != i){
        swap(dado[i],dado[maior]);
        corrigeDescendo(maior);
    }
}

void MaxHeap :: corrigeSubindo(int i){
    int p = pai(i);
    if(dado[i] > dado[p]){
        swap(dado[i],dado[p]);
        corrigeSubindo(p);
    }
}

Dado MaxHeap :: espiaRaiz(){
    return dado[0];
}

void MaxHeap :: arruma(){
    for(int i = (_tamanho/2)-1; i >= 0; i--){
        corrigeDescendo(i);
    }
}

inline bool MaxHeap :: cheio(){
    return _tamanho == _capacidade;
}


void MaxHeap :: insere(Dado d){
    if(not cheio()){
        dado[_tamanho] = d;
        _tamanho++;
    }
    else{
        cerr << "HEAP CHEIA" << endl;
        exit(EXIT_FAILURE);
    }
}

void MaxHeap :: imprime(){
    for(int i = 0 ; i < _tamanho; i++){
        cout << dado[i] << " ";
    }
    cout << endl;
}

inline bool MaxHeap :: vazio(){
    return _tamanho == 0;
}


Dado MaxHeap :: retiraRaiz(){
    if(not vazio()){
        Dado aux = dado[0];
        swap(dado[0],dado[_tamanho-1]);
        _tamanho--;
        corrigeDescendo(0);
        return aux;
    }
    else {
        cerr << "HEAP VAZIA" << endl;
        exit(EXIT_FAILURE);
    }
}

void heapSort(Dado vet[],  int tam){
        
        MaxHeap *aux = new MaxHeap(vet,tam);
        for(int i = tam-1 ; i >=0; i--){
            
            vet[i] = aux->retiraRaiz();
        }
}

            
        
    
        

int main (){
    
    int tam = 13;

    Dado vet[] = {50,2,90,20,230,43,8,34,66,100,110,3,13};
    
    //~ MaxHeap *h = new MaxHeap(vet,tam);
	
    //~ for(int i = 0; i < 13; i++){
        
    //~ cout << h->retiraRaiz() << " ";
   //~ }
    heapSort(vet,tam);
    for(int i = 0 ; i < 13; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
    
    
}
