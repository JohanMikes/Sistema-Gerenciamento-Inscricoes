// Importando library iostream e defininfo namespace
#include <iostream>
using namespace std;

// Definindo as structs Nolista(Candidatos), Atividade(Atividades) e
// Descritor(Descritor)
struct Nolista {
  string nome;
  int inscricao;
  string email;
  Nolista *prox;
  Nolista *ant;
};
struct Atividade {
  string atv;
  string tipo_atv;
  string data;
  string hora;
  Atividade *prox;
};
struct Descritor {
  Nolista *ini;
  Nolista *fim;
};

// Funções de inicializar uma lista dupla e uma lista simples
Descritor *criarlista() {
  Descritor *novo = new Descritor;
  novo->ini = NULL;
  novo->fim = NULL;
  return novo;
}

Atividade *criarlistaSimples() { return NULL; }

// Funções para trabalhar na lista de cadastros de atividade e candidatos
void inserir_candidato(Descritor *l, string nome, int inscricao, string email) {
  Nolista *novo = new Nolista;
  novo->nome = nome;
  novo->inscricao = inscricao;
  novo->email = email;
  novo->prox = NULL;
  novo->ant = NULL;
  if (l->ini == NULL) {
    l->ini = novo;
    l->fim = novo;
  } else {
    l->fim->prox = novo;
    novo->ant = l->fim;
    l->fim = novo;
  }
}

void cadastro_atv(Atividade *&l, string atv, string tipo_atv, string data,
                  string hora) {
  Atividade *novo = new Atividade;
  novo->atv = atv;
  novo->tipo_atv = tipo_atv;
  novo->data = data;
  novo->hora = hora;
  novo->prox = NULL;
  if (l == NULL) {
    l = novo;
  } else {
    novo->prox = l;
    l = novo;
  }
}

// Funções para imprimir a lista de atividades (imprimirSimples) e a de candidatos (imprimir) *TEMPORARIO E SERA RETIRADO OU MODIFICADO NO FUTURO*
void imprimirSimples(Atividade *l) {
  Atividade *p = l->prox;
  do {
    cout << p->atv << " - ";
    cout << p->tipo_atv << " - ";
    cout << p->data << " - ";
    cout << p->hora << endl;
    p = p->prox;
  } while (p != NULL);
}

void imprimir(Descritor *l) {
  Nolista *p = l->ini;
  do {
    cout << p->nome << " - ";
    cout << p->inscricao << " - ";
    cout << p->email << endl;
  } while (p->prox != NULL);
}

// Função main
int main() {
  Descritor *lista_candidado = criarlista(); // Criando lista candidatos
  Atividade *lista_atividade = criarlistaSimples(); // Criando lista atividades
  // Variaveis em declaração
  string nome, email;
  int inscricao;
  string atv, tipo_atv, data, hora;
  // ----------------------*
  cout << "Digite o nome do canditado: " << endl;
  cin >> atv;
  while (atv != "fim") {
    if (atv != "fim") {
      cout << "Digite o tipo da atividade: " << endl;
      cin >> tipo_atv;
      cout << "Digite a data: " << endl;
      cin >> data;
      cout << "Digite a hora: " << endl;
      cin >> hora;
    }
    cadastro_atv(lista_atividade, atv, tipo_atv, data, hora);
    cout << "Digite a atividade: " << endl;
    cin >> atv;
  }
  imprimirSimples(lista_atividade);
}
