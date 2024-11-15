#ifndef FILAENCADEADAGEN_H_INCLUDED
#define FILAENCADEADAGEN_H_INCLUDED

#include <iostream>

template<typename TIPO>
struct TElementoF {
    TIPO dado;
    TElementoF<TIPO> *proximo;
};

template<typename TIPO>
struct TFila {
    TElementoF<TIPO> *comeco;
};

template<typename TIPO>
bool inicializaFila(TFila<TIPO>& f){
    f.comeco = NULL;
    return true;
}

template<typename TIPO>
void imprimirFila(TElementoF<TIPO>*f){
    while(f != NULL) {
        cout<< f->dado << " ";
        f = f->proximo;
    }
    cout<<endl;
}

template<typename TIPO>
TElementoF<TIPO> *novoElemento(TIPO dado) {
    TElementoF<TIPO> *novo = new TElementoF<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

template<typename TIPO>
bool queueInsereFim(TFila<TIPO>& f, TIPO dado) {
    TElementoF<TIPO> *nav = f.comeco;
    TElementoF<TIPO> *novo = novoElemento(dado);
    if(f.comeco != NULL){
        while(nav->proximo != NULL){
            nav = nav->proximo;
        }
        novo->proximo = nav->proximo;
        nav->proximo = novo;
        return true;
    }else {
        novo->proximo = f.comeco;
        f.comeco = novo;
        return true;
    }
}

template<typename TIPO>
bool dequeueRemoveInicio(TFila<TIPO>& f){
    if(f.comeco == NULL) return false;
    TElementoF<TIPO> * apagar = f.comeco;
    f.comeco = apagar->proximo;
    TIPO valorRemovido = apagar->dado;
    delete apagar;
    return valorRemovido;

}



#endif // FILAENCADEADAGEN_H_INCLUDED
