/***************************************************************************************
* PROG:             PE Implementaçao                                                   *
* AUTOR:            Jesse Silva                                                        *
* DATA:             01/09/2023                                                         *
* ATUALIZADO EM:    00/00/2023  00:00                                                  *
***************************************************************************************/
#include "operacoes.h"

/********************************** MEDIA ARITMETICA **********************************/
void media_nao_agrupada(){
    system("cls");
    float *elementos;
    int n;
    printf("\tMedia nao Agrupada\n\n");
    n=PriNum("Escreva o numero de elementos: ");
    elementos = (float *)malloc(n*sizeof(float)); // determina o tam do vetor 
    putchar('\n');
    for(int i=0;i<n;i++){
        elementos[i]=PriNumf("Escreva o elemento: ");  
    }system("cls");
    printf("\nMedia = %.2f",media(n,elementos));
}
void media_agrupada(){
    system("cls");
    float *elementos,*frequencia,aux1,aux2;
    int n,op;
    printf("\tMedia Agrupada\n\n");
    n=PriNum("Escreva o numero de elementos: ");
    elementos = (float *)malloc(n*sizeof(float)); // determina o tam do vetor 
    frequencia = (float *)malloc(n*sizeof(float)); // determina o tam do vetor 
    putchar('\n');
    do{
        printf("\tTem Amplitude?\n\n");
        printf("1- Sim\n2- Nao\n");
        op=PriNum("Escolha uma das opcoes acima: ");
    }while(op!=1&&op!=2);
    if(op==1){
        for(int i=0;i<n;i++){
        aux1=PriNumf("De: ");
        aux2=PriNumf("Ate: ");
        elementos[i]=(aux2+aux1)/2;
        frequencia[i]=PriNumf("Escreva a frequencia: ");
        }  
    }else{
        for(int i=0;i<n;i++){
        elementos[i]=PriNumf("Escreva o elemento: ");
        frequencia[i]=PriNumf("Escreva a frequencia: ");
        }  
    }system("cls");
    printf("\nMedia = %.2f",media_agr(n,elementos,frequencia));
}
/*************************************** MEDIANA ***************************************/
void mediana_nao_agrupada(){
    system("cls");
    float *elementos;
    int n;

    printf("\tMediana nao Agrupada\n\n");
    n=PriNum("Escreva o numero de elementos: ");
    elementos = (float *)malloc(n*sizeof(float));
    putchar('\n');
    for(int i=0;i<n;i++){
    elementos[i]=PriNumf("Escreva o elemento: ");
    }system("cls");
    printf("\nMediana = %.2f",mediana(n,elementos));
    
}/**O PROBLEMA É AQUI**/
void mediana_agrupada(){
    system("cls");
    float *elementos,*frequencia,*LI,LS;
    int n,op;
    printf("\tMedia Agrupada\n\n");
    n=PriNum("Escreva o numero de elementos: ");
    elementos = (float *)malloc(n*sizeof(float));
    frequencia = (float *)malloc(n*sizeof(float));
    LI = (float *)malloc(n*sizeof(float));
    putchar('\n');
    do{
        printf("\tTem Amplitude?\n\n");
        printf("1- Sim\n2- Nao\n");
        op=PriNum("Escolha uma das opcoes acima: ");
    }while(op!=1&&op!=2);
    if(op==1){
        for(int i=0;i<n;i++){
        LI[i]=PriNumf("De: "); // Limite imferio
        LS=PriNumf("Ate: ");// Limite superior
        elementos[i]=LS-LI[i]; // Virou amplitude
        frequencia[i]=PriNumf("Escreva a frequencia: ");
        }  
    }else{
        for(int i=0;i<n;i++){
        elementos[i]=PriNumf("Escreva o elemento: ");
        frequencia[i]=PriNumf("Escreva a frequencia: ");
        }
    
    }system("cls");
    printf("\nMedia = %.2f",mediana_agr(n,elementos,frequencia,LI,op));
}
int main(){

    int op=0;
    do{
        system("cls");
        printf("\tImplementacao da materia de Probabilidade Estatistica\n\n");
        printf("1- Media\n2- Mediana\n3- Moda\n");
        op=PriNum("Escolha uma das opcoes acima: ");
    }while(op!=1&&op!=2&&op!=3);
    if(op==1){
        do{
        system("cls");
        printf("\tCalculo de Media\n\n");
        printf("1- Nao Agrupada\n2- Agrupada\n");
        op=PriNum("Escolha uma das opcoes acima: ");
        }while(op!=1&&op!=2);
        if(op==1){
            media_nao_agrupada();
        }else{
            media_agrupada();
        }
    }else if(op==2){
        do{
        system("cls");
        printf("\tCalculo de Mediana\n\n");
        printf("1- Nao Agrupada\n2- Agrupada\n");
        op=PriNum("Escolha uma das opcoes acima: ");
        }while(op!=1&&op!=2);
        if(op==1){
            mediana_nao_agrupada();
        }else{
            mediana_agrupada();
        }
    }
}