#include "mpi.h"
#include <stdio.h>

/*
Exercicio 1

Escreva um programa que imprima o numero de tarefas, o ranque de cada tarefa e o
nome da maquina em que cada tarefa esta executando.
*/
int main(int argc, char *argv[]) {
    int
        meu_ranque,
        num_procs,
        versao,
        subversao,
        aux,
        ret;
    char maquina[MPI_MAX_PROCESSOR_NAME];

    ret = MPI_Init(&argc, &argv);
    if (ret != MPI_SUCCESS) {
        printf("Erro ao inicializar MPI. Terminando.\n");
        MPI_Abort(MPI_COMM_WORLD, ret);
    }

    MPI_Get_version(&versao, &subversao);
    printf("Versao do MPI: %d.%d \n", versao, subversao);

    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &meu_ranque);

    MPI_Get_processor_name(maquina, &aux);

    printf(
        "numero de tarefas: %d | ranque: %d | executando em: %s\n",
        num_procs,
        meu_ranque,
        maquina);
    
    MPI_Finalize();
    return 0;
}