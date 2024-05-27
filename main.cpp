#include <iostream>

using namespace std;


struct Nolista{
     string nome;
     int inscricao;
     string email;
     Nolista *prox;
     Nolista *ant;
};

struct Atividade{
     string atv;
     string tipo_atv;
     string data;
     string hora;
     Atividade *prox;
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


Atividade * criarlistaSimples(){
     return NULL;
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

void cadastro_atv(Atividade *&l, string atv, string tipo_atv, string data, string hora){
     Atividade *lista_atv = criarlistaSimples();
     Atividade *novo = new Atividade;
    
     novo -> atv = atv;
     novo -> tipo_atv = tipo_atv;
     novo -> data = data;
     novo -> hora = hora;
     novo -> prox = NULL;

     if(l -> prox == NULL){
          l = novo;
     }
     else{
          novo -> prox = l;
          novo = l;
     }     
}


void imprimirSimples(Atividade *l){
     Atividade *q = l;
     while (q -> prox != NULL){
          cout<<"Entrei"<<endl;
          cout<< q -> atv<<" - ";
          cout<< q -> tipo_atv <<" - ";
          cout<< q -> data <<" - ";
          cout<< q -> hora <<endl;
          q = q -> prox;
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
     Atividade *lista_atividade = criarlistaSimples();
     
     //
     string nome, email;
     int inscricao;

     //Variavéis da lista de atividade 
     string atv, tipo_atv, data, hora;

     cout<<"Digite o nome do canditado: "<<endl;
     cin>>atv;
     while(atv != "fim"){
          if (atv != "fim"){
               cout<<"Digite o tipo da atividade: "<<endl;
               cin >> tipo_atv;

               cout<<"Digite a data: "<<endl;
               cin >> data;

               cout<<"Digite a hora: "<<endl;
               cin >> hora;

               
          }

          cadastro_atv(lista_atividade, atv, tipo_atv, data, hora);
          cout<<"Digite a atividade: "<<endl;
          cin >> atv;
     }


     imprimirSimples(lista_atividade);

     
}