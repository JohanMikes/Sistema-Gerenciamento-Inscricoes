#include <iostream>
using namespace std;
// Definindo as structs Nolista(Candidatos), Atividade(Atividades) e Matrix
struct Nolista{
     string nome;
     int inscricao;
     string email;
     string curso;
     Nolista *prox;
     Nolista *ant;
     int freq; // Adicionado para organizar a frequencia dos candidatos ao sorteio
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

bool** Matrix_Atividades; // Definindo ponteiro de boleanas junto as structs para melhor organização

// Funções de inicialização das duas listas
Descritor * criarlistaDupla(){
     Descritor *novo = new Descritor;
     novo -> ini = NULL;
     novo -> fim = NULL;
     return novo;
}
Atividade * criarlistaSimples(){
     return NULL;
}
//Função para preencher a lista de candidatos
void inserir_candidato(Descritor *&l, string nome, int inscricao, string email, string curso){
     Nolista *novo = new Nolista;
     novo -> nome = nome;
     novo -> inscricao = inscricao;
     novo -> email = email;
     novo -> curso = curso;
     novo -> prox = NULL;
     novo -> ant = NULL;
     // int freq não sera definido nesta função, sendo lixo até sua função ser chamada

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

void imprimirCandidatos(Descritor *l){
     Nolista *p = l -> ini;
     while (p != NULL){
          cout << p->nome << " - ";
          cout << p->email << " - ";
          cout << p->inscricao<< " - ";
          cout << p->curso<< endl;
          p = p -> prox;
     }

}

// Função para prencher a lista de atividade e ler sua leitura

Atividade* gerarlista_atv(Atividade *&l, string atv, string tipo_atv, int hora, string data){
  Atividade *atv_bloco = new Atividade;
  atv_bloco -> atv = atv;
  atv_bloco -> tipo_atv = tipo_atv;
  atv_bloco -> data = data;
  atv_bloco -> hora = hora;
  atv_bloco -> prox = NULL;
  if (l == NULL){
    l = atv_bloco;
  }else{
    atv_bloco -> prox = l;
    l = atv_bloco;
  }
  return atv_bloco;
}

void imprimir_atv(Atividade* l){
  Atividade* aux = l;
  while (aux -> prox != NULL){
    cout << "Atividade: " << aux -> atv << endl;
    cout << "Tipo " << aux -> tipo_atv << endl;
    cout << "Data: " << aux -> data << endl;
    cout << "Hora: " << aux -> hora << endl << endl;
    aux = aux -> prox;
  }
    cout << "Atividade: " << aux -> atv << endl;
    cout << "Tipo " << aux -> tipo_atv << endl;
    cout << "Data: " << aux -> data << endl;
    cout << "Hora: " << aux -> hora << endl << endl;
}

// Função da Matrix -----------------

bool** trabalho_matrix(int contador_A, int contador_C, Atividade* l, Descritor* lista_candidado){
  bool** Matrix_Atividades = new bool*[contador_A];
  for (int i = 0; i < contador_A; i++){
    Matrix_Atividades[i] = new bool[contador_C];
  }
  // Inicializando Matriz em FALSE
  for (int i = 0; i < contador_A; i++){
    for (int j = 0; j < contador_C; j++){
      Matrix_Atividades[i][j] = false;
    }
  }
  // Fazendo comparação
  Nolista* aux = lista_candidado -> ini;
  Atividade* aux2 = l;
  for (int i = 0; i < contador_A; i++){
    for (int j = 0; j < contador_C; j++){
      if (aux -> curso == l -> atv){
        Matrix_Atividades[i][j] = true;
        aux2 = aux2 -> prox;
      }else{
        Matrix_Atividades[i][j] = false;
      }
    }
    aux = aux -> prox;
  }
  return Matrix_Atividades;
}

// Função para trabalhar na frequencia, agindo direto no ponteiro l com uso de (&)
void inserir_freq(Descritor *&l, int contador_C){
  int freq = 0;
  Nolista* aux = l -> ini; // Iniciando ponteiro para escrever
  for (int i = 0; i < contador_C; i++){
    cout << "Por favor insira a frequencia de cada dandidato em ordem (entre 0 e 100): ";
    cin >> freq;
    if (freq < 0 || freq > 100){
      cout << endl << "DIGITO INVALIDO!" << endl;
      i -= 1;
    }else{
      aux -> freq = freq;
      aux = aux -> prox;
    }
  }
  aux = l -> ini; // Resetando ponteiro para leitura
  for (int j = 0; j < contador_C; j++){
    cout << endl << "Freq: " << aux -> freq << "*" << endl;
    aux = aux -> prox;
  }
}

int main(){
     //Criando lista candidatos e ponteiro atividade
     Descritor *lista_candidado = criarlistaDupla(); // Descritor
     Atividade *l = criarlistaSimples(); // Ponteiro L simples
     //Variáveis da lista de candidados, atividades e main
     string nome, email, curso, atv, tipo_atv, data;
     int inscricao, hora, contador_C = 0, contador_A = 0;
     // INSERIR ATIVIDADES -----------//
     cout << "Digite o nome da atividade (Fim para sair): " << endl;
     cin >> atv;
     while (atv != "Fim"){
       cout << "Digite o tipo da atividade: " << endl;
       cin >> tipo_atv;
       cout << "Digite a data: " << endl;
       cin >> data;
       cout << "Digite a hora em formato 24h sem minutos: " << endl;
       cin >> hora;
       contador_A++;
       gerarlista_atv(l, atv, tipo_atv, hora, data);
       cout << "Digite o nome da atividade (Fim para sair): " << endl;
       cin >> atv;
     }
     //INSERIR CANDIDATO ---------- //
     cout<<"Digite o nome do candidato (Fim para sair): "<<endl;
     cin>>nome;
     while (nome != "Fim"){
          cout<<"Digite o email do usuario: "<<endl;
          cin>>email;
          cout<<"Digite o numero da inscrição: "<<endl;
          cin>>inscricao;
          imprimir_atv(l);
          cout<<"Digite a atividade desejada (Sem erros de escrita): "<<endl;
          cin >> curso;
          contador_C++;
          inserir_candidato(lista_candidado, nome, inscricao, email, curso);
          cout<<"Digite o nome do candidato  (Fim para sair): "<<endl;
          cin>>nome;
     }
     imprimirCandidatos(lista_candidado);
     // CRIANDO MATRIX DE BOOL -----------//
     cout << endl << "Gerando Matrix..." << endl;
     trabalho_matrix(contador_A, contador_C, l, lista_candidado);
     // TRABALHANDO FREQUENCIA
     cout << endl << "Iniciando frequencia..." << endl; // Escrita trabalhada direno na função
     inserir_freq(lista_candidado, contador_C);

     // A FAZER!!!! CRIAR OS ITEMS DO SORTEIO E REALIZAR O SORTEIO USANDO COMO CRITERIO O VALOR DA FREQUENCIA SER 
     // MAIOR QUE 75% (75 INT)
     // :D boa sorte!!!!
}
