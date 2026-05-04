#include <stdio.h>
#include "tree.h"

static void visit_pre(Isi_Tree P, int i) {
    if (i == nil || P[i].info == '\0') return;
    printf("%c ", P[i].info);
    visit_pre(P, P[i].ps_fs);
    visit_pre(P, P[i].ps_nb);
}

static void visit_in(Isi_Tree P, int i) {
    int child;
    if (i == nil || P[i].info == '\0') return;
    child = P[i].ps_fs;
    if (child) {
        visit_in(P, child);
        child = P[child].ps_nb;
    }
    printf("%c ", P[i].info);
    while (child) {
        visit_in(P, child);
        child = P[child].ps_nb;
    }
}

static void visit_post(Isi_Tree P, int i) {
    if (i == nil || P[i].info == '\0') return;
    visit_post(P, P[i].ps_fs);
    visit_post(P, P[i].ps_nb);
    printf("%c ", P[i].info);
}

void Create_tree(Isi_Tree X, int Jml_Node) {
    int i;
    for (i = 0; i <= jml_maks; ++i) {
        X[i].info = '\0';
        X[i].ps_fs = X[i].ps_nb = X[i].ps_pr = nil;
    }
    if (Jml_Node > jml_maks) Jml_Node = jml_maks;
    for (i = 1; i <= Jml_Node; ++i) {
        printf("Node ke-%d\n", i);
        printf("  info   : "); scanf(" %c", &X[i].info);
        printf("  fs     : "); scanf("%d", &X[i].ps_fs);
        printf("  nb     : "); scanf("%d", &X[i].ps_nb);
        printf("  parent : "); scanf("%d", &X[i].ps_pr);
    }
}

boolean IsEmpty(Isi_Tree P) { return P[1].info == '\0'; }

void PreOrder(Isi_Tree P) { visit_pre(P, 1); printf("\n"); }

void InOrder(Isi_Tree P) { visit_in(P, 1); printf("\n"); }

void PostOrder(Isi_Tree P) { visit_post(P, 1); printf("\n"); }

void Level_order(Isi_Tree P, int Maks_node) {
    int q[jml_maks + 1], front = 0, rear = 0, i, child;
    if (IsEmpty(P)) return;
    if (Maks_node > jml_maks) Maks_node = jml_maks;
    q[rear++] = 1;
    while (front < rear) {
        i = q[front++];
        if (i == nil || i > Maks_node || P[i].info == '\0') continue;
        printf("%c ", P[i].info);
        child = P[i].ps_fs;
        while (child) {
            q[rear++] = child;
            child = P[child].ps_nb;
        }
    }
    printf("\n");
}

void PrintTree(Isi_Tree P) {
    int i;
    if (IsEmpty(P)) return;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info == '\0') continue;
        printf("[%d] info=%c fs=%d nb=%d pr=%d\n",
               i, P[i].info, P[i].ps_fs, P[i].ps_nb, P[i].ps_pr);
    }
}

boolean Search(Isi_Tree P, infotype X) {
    int i;
    for (i = 1; i <= jml_maks; ++i) if (P[i].info == X) return true;
    return false;
}

int nbElmt(Isi_Tree P) {
    int i, n = 0;
    for (i = 1; i <= jml_maks; ++i) if (P[i].info != '\0') n++;
    return n;
}

int nbDaun(Isi_Tree P) {
    int i, n = 0;
    for (i = 1; i <= jml_maks; ++i) if (P[i].info != '\0' && P[i].ps_fs == nil) n++;
    return n;
}

int Level(Isi_Tree P, infotype X) {
    int i, level;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info == X) {
            level = 0;
            while (P[i].ps_pr != nil) {
                level++;
                i = P[i].ps_pr;
            }
            return level;
        }
    }
    return -1;
}

int Depth(Isi_Tree P) {
    int i, level, max = 0;
    for (i = 1; i <= jml_maks; ++i) {
        if (P[i].info == '\0') continue;
        level = Level(P, P[i].info);
        if (level > max) max = level;
    }
    return max;
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}
