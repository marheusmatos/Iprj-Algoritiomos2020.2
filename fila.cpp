#include<iostream>
using namespace std;

typedef struct node
{
  int data;
  struct node *next;
} NODE, *PNODE;

class Fila
{
  PNODE cabeca;
  int ct;
public:
    Fila ();	
   ~Fila ();	

  void Adicionar (int);

  void Imprimir ();		
  void Soma ();
};

Fila::Fila ()
{
  cabeca = NULL;
  ct = 0;
}

void
Fila::Imprimir ()
{
  PNODE temp = cabeca;
  while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
}

void
Fila::Adicionar (int n)
{
  PNODE temp = cabeca;
  PNODE novo = new node;
  novo->data = n;
  novo->next = NULL;
  if (cabeca == NULL)
    {
      cabeca = novo;
    }
  else
    {
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = novo;
    }
}

bool
parOuImpar (int n)
{
  if ((n % 2) == 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

void
Fila::Soma ()
{
  PNODE temp = cabeca;

  int somaPar = 0;
  int somaImpar = 0;

  while (temp != NULL)
    {
      if (parOuImpar (temp->data))
	{
	  somaPar += temp->data;
	}
      else
	{
	  somaImpar += temp->data;
	}

      temp = temp->next;
    }
	cout<<endl;
  cout <<"Soma dos Pares: "<< somaPar << "\n Soma dos Impares: " << somaImpar;
}

Fila::~Fila ()
{
  PNODE temp = cabeca;
  if (cabeca == NULL)
    return;
  else if (cabeca != NULL)
    {
      while (cabeca != NULL)
	{
	  cabeca = cabeca->next;
	  delete temp;
	  temp = cabeca;
	}
    }
}

int
main ()
{

  Fila f;

  f.Adicionar (1);
  f.Adicionar (2);
  f.Adicionar (3);
  f.Adicionar (4);
  f.Adicionar (5);
  f.Adicionar (6);

  f.Imprimir ();
  f.Soma ();

  return 0;
}
