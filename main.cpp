// Importando library iostream e defininfo namespace

#include <iostream>

using namespace std;

// Definindo as structs Nolista(Candidatos), Atividade(Atividades)

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

// Descritor(Descritor)

struct Descritor{
     Nolista *ini;
     Nolista *fim;
};

// Função de inicializar uma lista duplamente

Descritor * criarlista(){
     Descritor *novo = new Descritor;
     novo -> ini = NULL;
     novo -> fim = NULL;
     return novo;

}


//Função de inicialização de lista simples 
Atividade * criarlistaSimples(){
     return NULL;
}

//Função para preencher a lista de candidatos

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

//Função para preencher a lista de atividade
void cadastro_atv(Atividade *&l, string atv, string tipo_atv, string data, string hora){
     Atividade *novo = new Atividade;
     novo -> atv = atv;
     cout<<novo -> atv<<endl;
     novo -> tipo_atv = tipo_atv;
     novo -> data = data;
     novo -> hora = hora;
     novo -> prox = NULL;
     if(l == NULL){
          l = novo;
     }
     else{
          novo -> prox = l;
          l = novo;
     }     
}

//Função para imprimir a lista de atividade
void imprimirSimples(Atividade *q){
     Atividade *p = q;
    do{   
          cout<<p -> atv<<" - ";
          cout<<p -> tipo_atv<<" - ";
          cout<<p -> data<< " - ";
          cout<<p -> hora<<endl;
          p = p -> prox;

    } while (p != NULL);

}

//Função para imprimir a lista de candidatos
void imprimir(Descritor *l){
     Nolista *p = l -> ini;
     while (p -> prox != NULL){
          cout << p->nome << " - ";
          cout << p->inscricao << " - ";
          cout << p->email << endl;

          p = p -> prox;
     }
     //ERRO: NÃO ESTÁ IMPRINDO A ULTIMA POSIÇÃO 
}

int main(){
     //Criando as listas
     Descritor *lista_candidado = criarlista();
     Atividade *lista_atividade = criarlistaSimples();
     
     //Variáveis da lista de candidados 
     string nome, email;
     int inscricao;

     //Variavéis da lista de atividade 
     string atv, tipo_atv, data, hora;

     cout<<"Digite o nome do candidato: "<<endl;
     cin>>nome;

     while (nome != "fim"){
          cout<<"Digite o email do usuario: "<<endl;
          cin>>email;

          cout<<"Digite o numero da inscrição: "<<endl;
          cin>>inscricao;

          inserir_candidato(lista_candidado, nome, inscricao, email);

          cout<<"Digite o nome do candidato: "<<endl;
          cin>>nome;
     }
     
     cout<<"Digite o nome da atividade: "<<endl;
     cin>>atv;

     while(atv != "fim"){
          cout<<"Digite o tipo da atividade: "<<endl;
          cin >> tipo_atv;

          cout<<"Digite a data: "<<endl;
          cin >> data;

          cout<<"Digite a hora: "<<endl;
          cin >> hora;

          cadastro_atv(lista_atividade, atv, tipo_atv, data, hora);
          
          cout<<"Digite a atividade: "<<endl;
          cin >> atv;
     }


     imprimir(lista_candidado);
     imprimirSimples(lista_atividade);

     
}