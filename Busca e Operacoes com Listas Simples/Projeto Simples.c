#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 255

struct pessoa{
    char nome[TAM];
    int rg;
};

void limpaTela(){
    system("CLS");
}

void imprimeSequencial(struct pessoa *ponteiroSequencial,int tamanhoDaLista){
    int i;

    for(i = 0; i < tamanhoDaLista; i++){
        printf("%d-%s, %d \n", i,ponteiroSequencial[i].nome, ponteiroSequencial[i].rg);
    }

}

void addComecoSequencial(struct pessoa **ponteiroSequencial,int *tamanhoDaLista, char nome[], int rg){

    if(*tamanhoDaLista == 0){
        //caso a lista ja tenha membros.
        struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa));

        //insere o primeiro novo elemento no novo vetor vazio
        strcpy(novaListaSequencial[0].nome, nome);
        novaListaSequencial[0].rg = rg;

        // limpa antiga lista.
        free(*ponteiroSequencial);

        //atualiza o ponteiro para a lista nova;
        *ponteiroSequencial = novaListaSequencial;
    }else{
        //caso a lista ja tenha membros.
        struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista + 1));

        //insere o primeiro novo elemento no novo vetor vazio
        strcpy(novaListaSequencial[0].nome, nome);
        novaListaSequencial[0].rg = rg;

        //passa os elementos do vetor antigo para um novo.
        int cont;
        for(cont = 0; cont < *tamanhoDaLista; cont++){
            strcpy(novaListaSequencial[cont + 1].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
            novaListaSequencial[cont + 1].rg = (*ponteiroSequencial)[cont].rg;
        }

        // limpa antiga lista.
        free(*ponteiroSequencial);

        //atualiza o ponteiro para a lista nova;
        *ponteiroSequencial = novaListaSequencial;

    }

    //incrementa o tamanho da lista em 1.
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void addFimSequencial(struct pessoa **ponteiroSequencial,int *tamanhoDaLista, char nome[], int rg){

    //a ideia é criar um vetor maior com mais um node e preencheer esse novo vetor
    //com os mesmos valores antigos porem deixando um espaço no final para colocar o valor.

    struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista + 1));

    //passa os elementos do vetor antigo para um novo.
    int cont;

    //adiciona os valores
    for(cont = 0; cont < *tamanhoDaLista; cont++){
        strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
        novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont].rg;
    }

    //posiciona o ultimo elemento. "tamanhoDaLista + 1 está errado pois o indice comeca pelo 0

    strcpy(novaListaSequencial[*tamanhoDaLista].nome, nome);
    novaListaSequencial[*tamanhoDaLista].rg = rg;

    // limpa antiga lista.
    free(*ponteiroSequencial);

    //atualiza o ponteiro para a lista nova;
    *ponteiroSequencial = novaListaSequencial;

    //incrementa a lista.
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void addPosicaoSequencial(struct pessoa **ponteiroSequencial, int *tamanhoDaLista, char nome[], int rg, int posicao){
    int cont;
    //cria um vetor com um tamanho maior (+1)
    struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista + 1));

    //Passando todos os valores da lista antiga para a nova normalmente ate a uma posição anterior a referenciada (cont < posicao).
    for(cont = 0; cont < posicao; cont++){
        strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
        novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont].rg;
    }

    //adiciona o novo registro na posição correta.
    strcpy(novaListaSequencial[posicao].nome, nome); //ponteiro de ponteiro para mudar no escopo global.
    novaListaSequencial[posicao].rg = rg;

    //coloca o resto dos valores antigos a diante.
    for(cont = posicao + 1; cont < (*tamanhoDaLista + 1); cont++){

    //contador - 1, para a nova lista pegar um valor anterior
    strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont - 1].nome);
    novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont - 1].rg;
    }

    // limpa antiga lista.
    free(*ponteiroSequencial);

    //atualiza o ponteiro para a lista nova;
    *ponteiroSequencial = novaListaSequencial;

    //incrementa a lista.
    *tamanhoDaLista = *tamanhoDaLista + 1;
}

void removeInicioSequencial(struct pessoa **ponteiroSequencial, int *tamanhoDaLista){
    int cont;

    //cria um vetor com um tamanho menor (-1)
    struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista - 1));

    //adiciona os valores, [cont - 1] para colocar o indice da nova lista no zero
    for(cont = 1; cont < *tamanhoDaLista; cont++){
        strcpy(novaListaSequencial[cont - 1].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
        novaListaSequencial[cont - 1].rg = (*ponteiroSequencial)[cont].rg;
    }

    // limpa antiga lista.
    free(*ponteiroSequencial);

    //atualiza o ponteiro para a lista nova;
    *ponteiroSequencial = novaListaSequencial;

    //incrementa a lista.
    *tamanhoDaLista = *tamanhoDaLista - 1;

}

void removeFimSequencial(struct pessoa **ponteiroSequencial, int *tamanhoDaLista){

    int cont;

    //cria um vetor com um tamanho menor (-1)
    struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista - 1));

    //adiciona os valores, [cont - 1] para colocar o indice da nova lista no zero
    for(cont = 0; cont < (*tamanhoDaLista - 1); cont++){
        strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
        novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont].rg;
    }

    // limpa antiga lista.
    free(*ponteiroSequencial);

    //atualiza o ponteiro para a lista nova;
    *ponteiroSequencial = novaListaSequencial;

    //incrementa a lista.
    *tamanhoDaLista = *tamanhoDaLista - 1;
}

void removePosicaoSequencial(struct pessoa **ponteiroSequencial, int *tamanhoDaLista, int posicao){
    int cont;
    //cria um vetor com um tamanho menor (-1)
    struct pessoa *novaListaSequencial = malloc(sizeof(struct pessoa) * (*tamanhoDaLista - 1));

    for(cont = 0; cont < *tamanhoDaLista - 1; cont++){
        if(cont < posicao){
                //Faz uma copia dos elementos ate a posicao
                strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont].nome); //ponteiro de ponteiro para mudar no escopo global.
                novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont].rg;
            }else{
                //Faz uma copia dos elementos ate a posicao
                strcpy(novaListaSequencial[cont].nome, (*ponteiroSequencial)[cont + 1].nome); //ponteiro de ponteiro para mudar no escopo global.
                novaListaSequencial[cont].rg = (*ponteiroSequencial)[cont + 1].rg;
            }
    }



    // limpa antiga lista.
    free(*ponteiroSequencial);

    //atualiza o ponteiro para a lista nova;
    *ponteiroSequencial = novaListaSequencial;

    //incrementa a lista.
    *tamanhoDaLista = *tamanhoDaLista - 1;


}

char* retornaNomeSequencial(struct pessoa **ponteiroSequencial, int *tamanhoDaLista, int rg){

    //busca simples pelo nome com o rg digitado.
    int i;char nome[] = "NaoEncontrado";

    for(i = 0; i < *tamanhoDaLista; i++){

        if((*ponteiroSequencial)[i].rg == rg){

            return (*ponteiroSequencial)[i].nome;
        }
    }

    return nome;

}

int main(){
    //Localizando em PT_BR
    setlocale(LC_ALL, "Portuguese");

    //variaveis
    int funcaoDesejada = 1;

    //ponteiro para lista sequencial.
    struct pessoa *ponteiroSequencial;

    //tamamho da lista.
    int tamanhoDaLista = 0;

    //mostrando o MENU.
    while(funcaoDesejada < 10 && funcaoDesejada > 0 ){

    printf("\n");
    imprimeSequencial(ponteiroSequencial, tamanhoDaLista);
    printf("\n");

    //mostrando o menu
    printf("Operações. \n");
    printf("1 - Inserção de um node no inicio da lista\n");
    printf("2 - Insercao de um node no fim da lista \n");
    printf("3 - Insercao de um node na posicao N \n");
    printf("4 - Retirar um node do inicio da lista \n");
    printf("5 - Retirar um node no fim da lista \n");
    printf("6 - Retirar um node na posicao N \n");
    printf("7 - Procurar um node com o campo RG \n");
    printf("8 - Imprimir a Lista. \n");
    printf("9 - Sair do sistema. \n");
    printf("\nEscolha um numero e pressione ENTER: \n");
    scanf("%d", &funcaoDesejada);
    limpaTela();

    char nome[TAM];
    int rg,posicao;
    switch(funcaoDesejada){

        case 1:
            printf("Função escolhida : 1 - Inserção de um node no inicio da lista\n");

            //obtendo nome do usuario.
            printf("Digite um nome: ");
            getchar();
            scanf("%[^\n]", nome);

            //obtendo rg do usuario.
            printf("Digite um rg: ");
            scanf("%d", &rg);

            //ponteiro para a lista e o tamanho dela são enviados como referencia.
            addComecoSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg);

            break;

        case 2:
            printf("Função escolhida : 2 - Inserção de um node no fim da lista\n");

            //obtendo nome do usuario.
            printf("Digite um nome: ");
            getchar();
            scanf("%[^\n]", nome);

            //obtendo rg do usuario.
            printf("Digite um rg: ");
            scanf("%d", &rg);

            if(tamanhoDaLista == 0){
                addComecoSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg);
                break;
            }else{
                //adiciona na posição especifica.
                addFimSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg);
                break;
            }

        case 3:

            printf("Função escolhida :3 - Insercao de um node na posicao N \n");

            //obtendo nome do usuario.
            printf("Digite um nome: ");
            getchar();
            scanf("%[^\n]", nome);

            //obtendo rg do usuario.
            printf("Digite um rg: ");
            scanf("%d", &rg);

            printf("Digite a posição: ");
            scanf("%d", &posicao);

            //se estiver no comeco ou fim.
            if(posicao == 0){
                //quando quer adicionar no inicio.
                addComecoSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg);
                break;
            }else if(posicao == tamanhoDaLista){
                //quando quer adicionar no fim.
                addFimSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg);
                break;
            }else{
                addPosicaoSequencial(&ponteiroSequencial,&tamanhoDaLista,nome,rg,posicao);
                break;
            }

        case 4:
            printf("Função escolhida : 4 - Retirar um node do inicio da lista \n");

            if(tamanhoDaLista == 0){
                printf("Lista vazia!");
                break;
            }else{
                removeInicioSequencial(&ponteiroSequencial, &tamanhoDaLista);
                break;
            }


        case 5:
            printf("Função escolhida : 5 - Retirar um node no fim da lista \n");

            if(tamanhoDaLista == 0){
                printf("Lista vazia!");
                break;
            }else{
                removeFimSequencial(&ponteiroSequencial, &tamanhoDaLista);
                break;
            }

        case 6:
            printf("Função escolhida : 6 - Retirar um node na posicao N \n");

            printf("Digite a posição: ");
            scanf("%d", &posicao);

            if(tamanhoDaLista == 0){
                printf("Lista vazia!");
                break;
            }else{
                removePosicaoSequencial(&ponteiroSequencial, &tamanhoDaLista, posicao);
                break;
            }

        case 7:
            printf("Função escolhida : 7 - Procurar um node com o campo RG \n");

            printf("Digite um rg: ");
            scanf("%d", &rg);

            printf("%s\n ",retornaNomeSequencial(&ponteiroSequencial, &tamanhoDaLista, rg));

        }
    }
}
