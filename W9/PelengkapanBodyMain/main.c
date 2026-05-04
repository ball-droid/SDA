#include <stdio.h>
#include "tree.h"

int main(void) {
    Isi_Tree tree, tree2;
    int i, menu, jumlah, level;
    char node;

    for (i = 0; i <= jml_maks; i++) {
        tree[i].info = '\0';
        tree[i].ps_fs = tree[i].ps_nb = tree[i].ps_pr = nil;
    }

    tree[1].info = 'A'; tree[1].ps_fs = 2;
    tree[2].info = 'B'; tree[2].ps_fs = 4; tree[2].ps_nb = 3; tree[2].ps_pr = 1;
    tree[3].info = 'C'; tree[3].ps_fs = 6; tree[3].ps_pr = 1;
    tree[4].info = 'D'; tree[4].ps_nb = 5; tree[4].ps_pr = 2;
    tree[5].info = 'E'; tree[5].ps_fs = 9; tree[5].ps_pr = 2;
    tree[6].info = 'F'; tree[6].ps_nb = 7; tree[6].ps_pr = 3;
    tree[7].info = 'G'; tree[7].ps_nb = 8; tree[7].ps_pr = 3;
    tree[8].info = 'H'; tree[8].ps_pr = 3;
    tree[9].info = 'I'; tree[9].ps_nb = 10; tree[9].ps_pr = 5;
    tree[10].info = 'J'; tree[10].ps_pr = 5;

    do {
        printf("\nADT Non Binary Tree\n");
        printf("1. Traversal PreOrder\n");
        printf("2. Traversal InOrder\n");
        printf("3. Traversal PostOrder\n");
        printf("4. Traversal Level Order\n");
        printf("5. Print Tree\n");
        printf("6. Search node Tree\n");
        printf("7. Jumlah Daun/Leaf\n");
        printf("8. Mencari Level node Tree\n");
        printf("9. Kedalaman Tree\n");
        printf("10. Membandingkan 2 Tree\n");
        printf("11. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("PreOrder: ");
                PreOrder(tree);
                break;
            case 2:
                printf("InOrder: ");
                InOrder(tree);
                break;
            case 3:
                printf("PostOrder: ");
                PostOrder(tree);
                break;
            case 4:
                printf("LevelOrder: ");
                Level_order(tree, jml_maks);
                break;
            case 5:
                PrintTree(tree);
                break;
            case 6:
                printf("Masukkan node: ");
                scanf(" %c", &node);
                if (Search(tree, node)) printf("Node %c ditemukan\n", node);
                else printf("Node %c tidak ditemukan\n", node);
                break;
            case 7:
                printf("Jumlah daun: %d\n", nbDaun(tree));
                break;
            case 8:
                printf("Masukkan node: ");
                scanf(" %c", &node);
                level = Level(tree, node);
                if (level == -1) printf("Node %c tidak ditemukan\n", node);
                else printf("Level node %c = %d\n", node, level);
                break;
            case 9:
                printf("Kedalaman tree: %d\n", Depth(tree));
                break;
            case 10:
                printf("Jumlah node tree pembanding: ");
                scanf("%d", &jumlah);
                Create_tree(tree2, jumlah);
                for (i = 1; i <= jml_maks; i++) {
                    if (tree[i].info != tree2[i].info ||
                        tree[i].ps_fs != tree2[i].ps_fs ||
                        tree[i].ps_nb != tree2[i].ps_nb ||
                        tree[i].ps_pr != tree2[i].ps_pr) {
                        break;
                    }
                }
                if (i > jml_maks) printf("Kedua tree sama\n");
                else printf("Kedua tree tidak sama\n");
                break;
            case 11:
                printf("Program selesai.\n");
                break;
            default:
                printf("Menu tidak valid\n");
        }
    } while (menu != 11);

    return 0;
}
