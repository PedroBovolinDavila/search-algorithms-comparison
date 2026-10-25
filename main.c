#include "stdio.h"
#include "stdlib.h"

void populate(int* vec, int n);
int binary_search(int* vec, int n, int target, int* comp);
int sequential_search(int* vec, int n, int target, int* comp);

int main() {
    int vec_len;

    printf("Informe o tamanho do vetor: ");
    scanf_s("%d", &vec_len);
    if (vec_len <= 0) return 1;

    int* vec = malloc(vec_len * sizeof(*vec));
    if (vec == NULL) return 1;

    populate(vec, vec_len);

    int target;
    
    printf("Informe o alvo que deseja procurar: ");
    scanf_s("%d", &target);

    int binary_comp, sequential_comp;

    int binary_index = binary_search(vec, vec_len, target, &binary_comp);
    int sequential_index = sequential_search(vec, vec_len, target, &sequential_comp);

    printf("\tN\tTarget\tIndex\tComparacoes\n");
    printf("B\t%d\t%d\t%d\t%d\n", vec_len, target, binary_index, binary_comp);
    printf("S\t%d\t%d\t%d\t%d\n", vec_len, target, sequential_index, sequential_comp);

    free(vec);

    return 0;
}

void populate(int* vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }
}

int binary_search(int* vec, int n, int target, int* comp) {
    *comp = 0;

    int start = 0, end = n - 1;

    while (start <= end) {
        int center = (start + end) / 2;

        (*comp)++;

        if (vec[center] == target) return center;
        if (vec[center] > target) end = center - 1;
        if (vec[center] < target) start = center + 1;
    }

    return -1;
}

int sequential_search(int* vec, int n, int target, int* comp) {
    *comp = 0;

    for (int i = 0; i < n; i++) {
        (*comp)++;

        if (vec[i] == target) return i;
    }

    return -1;
}
