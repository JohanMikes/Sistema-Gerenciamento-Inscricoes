#include <iostream>

using namespace std;

struct Nolista{
     string nome;
     int inscricao;
     string email;
     Nolista *prox;
     Nolista *ant;
};

struct Descritor{
     Nolista *ini;
     Nolista *fim;
};

Descritor * criarlista(){
     Descritor *novo = new Descritor;
     novo -> ini = NULL;
     novo -> fim = NULL;
}

void inserir_candidato(Descritor *l, string nome, int inscricao, string email){
     Nolista *novo = new Nolista;
     novo -> nome = nome;
     novo -> inscricao = inscricao;
     novo -> email = email;
     novo -> prox = NULL;
     novo -> ant = NULL;

     if(l -> ini == NULL){
          l -> ini = novo;
          l -> fim = novo;
     }
     else{
          l -> fim -> prox = novo;
          novo -> ant = l -> fim;
          l -> fim = novo;
     }
}

void imprimir(Descritor *l){
     Nolista *p = l -> ini;
    do
    {     
          cout<<p -> nome<<" - ";
          cout<<p -> inscricao<<" - ";
          cout<<p -> email<<endl;
    } while (p -> prox != NULL);

}


int main(){
     Descritor *lista_candidado = criarlista();
     string nome, email;
     int inscricao;
     cout<<"Digite o nome do canditado: "<<endl;
     cin>>nome;
     while(nome != "fim"){
          
          cout<<"Digite o numero de inscricao"<<endl;
          cin>>inscricao;

          cout<<"Digite o seu e-mail"<<endl;
          cin >> email;

          inserir_candidato(lista_candidado, nome, inscricao, email);

          cout<<"Digite o nome do canditado: "<<endl;
          cin>>nome;

     }

     imprimir(lista_candidado);


     
}