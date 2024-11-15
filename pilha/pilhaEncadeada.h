#ifndef PILHAENCADEADA_H_INCLUDED
#define PILHAENCADEADA_H_INCLUDED

template<typename TIPO>
struct TElementoP {
    TIPO dado;
    TElementoP<TIPO>*proximo;
};

template<typename TIPO>
struct TPilha {
    TElementoP<TIPO>*topo;
};

template<typename TIPO>
bool inicializaPilha(TPilha<TIPO>& p) {
    p.topo = NULL;
    return true;
}

template<typename TIPO>
void imprimirPilha(TElementoP<TIPO>*p){
    while(p != NULL) {
        cout<< p->dado << " ";
        p= p->proximo;
    }
    cout<<endl;
}

template<typename TIPO>
TElementoP<TIPO> *novoElemento(TIPO dado){
    TElementoP<TIPO> *novo = new TElementoP<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;
    return novo;
}

template<typename TIPO>
bool pushInsereInicio(TPilha<TIPO>&p, TIPO dado) {
    TElementoP<TIPO>*novo = novoElemento(dado);
    novo->proximo = p.topo;
    p.topo = novo;
    return true;
}

template<typename TIPO>
TIPO popRemoveInicio(TPilha<TIPO>& p) {
    if(p.topo == NULL) return 0;
    TElementoP<TIPO>* nav = p.topo;
    p.topo = nav->proximo;
    TIPO dado = nav->dado;
    delete nav;
    return dado;
}


#endif // PILHAENCADEADA_H_INCLUDED
