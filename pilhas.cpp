
#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE 99

typedef struct estruturaPilha{
    int items[CAPACIDADE];
    int top;
}pilha;

pilha* initpilha();
int estaVazia(pilha *s);
int estaCheia(pilha *s);
int adiciona(pilha *s, int valor);
int pop(pilha *s, int *x);
int escolhe(pilha *s, int *x);
int pilhasIguais(pilha *p1, pilha *p2);

int main()
{
    pilha *p1 = initpilha();
    pilha *p2 = initpilha();

    adiciona(p1, 1);
    adiciona(p1,2);
    adiciona(p1,3);

    adiciona(p2, 3);
    adiciona(p2,2);
    adiciona(p2,1);

    printf("O resultado é: %d\n", pilhasIguais(p1,p2));
    return 0;
}

pilha* initpilha(){
    pilha *s = (pilha*)malloc(sizeof(pilha));
    s->top = -1;
    return s;
}
int estaVazia(pilha *s){
    if(s->top == -1){
        return 1;
    }else{
        return 0;
    }
}

int estaCheia(pilha *s){
    if(s->top == CAPACIDADE - 1){
        return 1;
    }else{
        return 0;
    }
}

int adiciona(pilha *s, int valor){
    if(estaCheia(s)){
        return 0;
    }else{
        s->items[++s->top] = valor;
        return 1;
    }
}

int pop(pilha *s, int *x){
    if(estaVazia(s)){
        return 0;
    }else{
        *x = s->items[s->top--];
        return 1;
    }
}

int escolhe(pilha *s, int *x){
    if(estaVazia(s)){
        return 0;
    }else{
        *x = s->items[s->top];
        return 1;
    }
}

int pilhasIguais(pilha *p1, pilha *p2){   
    if(p1->top != p2->top){
        return 0;
    }else{
        int primeira;
        int segunda;
        pilha *pilhaTemporarea = initpilha();

        while(!estaVazia(p1)){
            escolhe(p1, &primeira);
            escolhe(p2, &segunda);
            if(primeira != segunda){
                return 0;
            }
            else{
                adiciona(pilhaTemporarea, primeira);
                pop(p1, &primeira);
                pop(p2, &segunda);
            }
        }
        if(!estaVazia(p1)){
            return 0;
        }else{
           return 1;
        }
    }
}