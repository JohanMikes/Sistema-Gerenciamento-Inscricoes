#include <iostream>
using namespace std;

// Structs Nolista(Users), Atividade(Atividades) e Descritor(Descritor) --------* 
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
     int hora; 
     Atividade *prox;
};

struct Descritor{
     Nolista *ini;
     Nolista *fim;
};

// --------------------------------------------------*

// Criando descritor, lista das atividades em NULL, lista de candidatos e cadastro das atividades ----------*
Descritor * criarlista(){
     Descritor *novo = new Descritor;
     novo -> ini = NULL;
     novo -> fim = NULL;
}

Atividade * criarlistaSimples(){ // Atividades é uma lista simples
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

void cadastro_atv(Atividade *&l, string atv, string tipo_atv, string data, int hora){
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
// --------------------------------------------------*

// TEMPORARIO IMPRIMIR LISTA DE USUARIOS!!! APAGAR APOS TESTES DE DEBUG ---------*
void imprimir(Descritor *l){
     Nolista *p = l -> ini;
    do
    {   
          cout<<p -> nome<<" - ";
          cout<<p -> inscricao<<" - ";
          cout<<p -> email<<endl;
    } while (p -> prox != NULL);

}
// --------------------------------------------------*

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
