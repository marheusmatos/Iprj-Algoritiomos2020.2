#include <stdio.h>
#include <stdlib.h>

struct node
{
  int num;
  struct node *preptr;
  struct node *proximoptr;
} *stnode, *ennode;


void CriaLista (int n);
void ExibiLista (int qntItens);
int
main ()
{
  int n;
  stnode = NULL;
  ennode = NULL;
  printf (" Digite a quantidade de nós: ");
  scanf ("%d", &n);

  CriaLista (n);
  ExibiLista (n);
  return 0;
}

void
CriaLista (int n)
{
  int i, num;
  struct node *fnNode;

  if (n >= 1)
    {
      stnode = (struct node *) malloc (sizeof (struct node));

      if (stnode != NULL)
	{
	  printf (" Valor do nó 1 : ");
	  scanf ("%d", &num);

	  stnode->num = num;
	  stnode->preptr = NULL;
	  stnode->proximoptr = NULL;
	  ennode = stnode;
	  for (i = 2; i <= n; i++)
	    {
	      fnNode = (struct node *) malloc (sizeof (struct node));
	      if (fnNode != NULL)
		{
		  printf (" Valor do nó %d : ", i);
		  scanf ("%d", &num);
		  fnNode->num = num;
		  fnNode->preptr = ennode;
		  fnNode->proximoptr = NULL;
		  ennode->proximoptr = fnNode;
		  ennode = fnNode;
		}
	      else
		{
		  printf ("Ocorreu um erro.");
		  break;
		}
	    }
	}
      else
	{
	  printf ("Ocorreu um erro.");
	}
    }
}

void
ExibiLista (int qntItens)
{
  struct node *tmp;
  int n = 1;
  int valores[qntItens];
  if (stnode == NULL)
    {
      printf (" Nada encontrado.");
    }
  else
    {
      tmp = stnode;
      printf ("\n Imprimindo valores:");

      while (tmp != NULL)
	{
	  valores[n - 1] = tmp->num;
	  n++;
	  tmp = tmp->proximoptr;
	}
      n -= 2;
      while (n >= 0)
	{
	  printf ("\n nó posicao %d : %d", (n+1), valores[n]);
	  n -= 1;
	}
	printf("\n");
    }

}
