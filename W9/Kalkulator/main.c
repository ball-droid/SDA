#include <stdio.h>
#include "tree.h"

int main(void) {
    Isi_Tree tree;
    int hasil;
    const char *ekspresi = "10 + 5 + 3 - 2";

    printf("Kalkulator Non-Binary Tree\n");
    printf("Ekspresi: %s\n\n", ekspresi);

    InitTree(tree);
    if (!BuildExpressionTree(tree, ekspresi)) {
        printf("Tree gagal dibuat\n");
        return 1;
    }

    PrintTree(tree);
    printf("PostOrder: ");
    PostOrder(tree);

    if (!EvaluateTree(tree, &hasil)) {
        printf("Perhitungan gagal\n");
        return 1;
    }

    printf("Hasil akhir: %d\n", hasil);
    return 0;
}
