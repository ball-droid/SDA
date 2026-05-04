#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct {
    char angka[token_maks];
} Token;

static int buatNode(Isi_Tree tree, int *last, const char *isi, int parent) {
    if (*last >= jml_maks) return nil;
    (*last)++;
    strcpy(tree[*last].info, isi);
    tree[*last].ps_pr = parent;
    return *last;
}

static void tambahAnak(Isi_Tree tree, int parent, int child) {
    int i;
    if (tree[parent].ps_fs == nil) {
        tree[parent].ps_fs = child;
        return;
    }
    i = tree[parent].ps_fs;
    while (tree[i].ps_nb != nil) i = tree[i].ps_nb;
    tree[i].ps_nb = child;
}

static boolean isOperator(const char *x) {
    return strlen(x) == 1 && (x[0] == '+' || x[0] == '-');
}

static boolean pecahEkspresi(const char *exp, Token angka[], int *nAngka, char op[], int *nOp) {
    int i = 0, start, len = (int)strlen(exp), tungguAngka = 1;
    *nAngka = 0;
    *nOp = 0;

    while (i < len) {
        if (isspace((unsigned char)exp[i])) {
            i++;
            continue;
        }

        if (tungguAngka) {
            if (!isdigit((unsigned char)exp[i])) return false;
            start = i;
            while (i < len && isdigit((unsigned char)exp[i])) i++;
            snprintf(angka[*nAngka].angka, token_maks, "%.*s", i - start, exp + start);
            (*nAngka)++;
            tungguAngka = 0;
        } else {
            if (exp[i] != '+' && exp[i] != '-') return false;
            op[*nOp] = exp[i];
            (*nOp)++;
            i++;
            tungguAngka = 1;
        }
    }

    return !tungguAngka && *nAngka == *nOp + 1;
}

static int buatSegmen(Isi_Tree tree, Token angka[], char op[], int left, int right, int parent, int *last) {
    char s[2];
    int root, i, child;

    if (left == right) return buatNode(tree, last, angka[left].angka, parent);

    s[0] = op[left];
    s[1] = '\0';
    root = buatNode(tree, last, s, parent);

    i = left;
    while (i < right) {
        if (op[i] != op[left]) {
            child = buatSegmen(tree, angka, op, i, right, root, last);
            tambahAnak(tree, root, child);
            return root;
        }

        child = buatNode(tree, last, angka[i].angka, root);
        tambahAnak(tree, root, child);

        if (i == right - 1) {
            child = buatNode(tree, last, angka[right].angka, root);
            tambahAnak(tree, root, child);
            return root;
        }

        if (op[i + 1] != op[left]) {
            child = buatSegmen(tree, angka, op, i + 1, right, root, last);
            tambahAnak(tree, root, child);
            return root;
        }
        i++;
    }

    return root;
}

static void isiPostOrder(Isi_Tree tree, int idx, char hasil[][token_maks], int *n) {
    int child;

    if (idx == nil || tree[idx].info[0] == '\0') return;

    if (!isOperator(tree[idx].info)) {
        strcpy(hasil[*n], tree[idx].info);
        (*n)++;
        return;
    }

    child = tree[idx].ps_fs;
    isiPostOrder(tree, child, hasil, n);
    child = tree[child].ps_nb;

    while (child != nil) {
        isiPostOrder(tree, child, hasil, n);
        strcpy(hasil[*n], tree[idx].info);
        (*n)++;
        child = tree[child].ps_nb;
    }
}

void InitTree(Isi_Tree tree) {
    int i;
    for (i = 0; i <= jml_maks; i++) {
        tree[i].info[0] = '\0';
        tree[i].ps_fs = tree[i].ps_nb = tree[i].ps_pr = nil;
    }
}

boolean BuildExpressionTree(Isi_Tree tree, const char *expression) {
    Token angka[jml_maks];
    char op[jml_maks];
    int nAngka, nOp, last = 0, root;

    InitTree(tree);
    if (!pecahEkspresi(expression, angka, &nAngka, op, &nOp)) return false;
    root = buatSegmen(tree, angka, op, 0, nAngka - 1, nil, &last);
    return root == 1;
}

void PostOrder(Isi_Tree tree) {
    char hasil[jml_maks][token_maks];
    int i, n = 0;
    isiPostOrder(tree, 1, hasil, &n);
    for (i = 0; i < n; i++) printf("%s ", hasil[i]);
    printf("\n");
}

void PrintTree(Isi_Tree tree) {
    int i;
    printf("Representasi array Non-Binary Tree:\n\n");
    for (i = 1; i <= jml_maks; i++) {
        if (tree[i].info[0] == '\0') continue;
        printf("Node %d\n", i);
        printf("  info         : %s\n", tree[i].info);
        printf("  first son    : %d\n", tree[i].ps_fs);
        printf("  next brother : %d\n", tree[i].ps_nb);
        printf("  parent       : %d\n\n", tree[i].ps_pr);
    }
}

boolean EvaluateTree(Isi_Tree tree, int *result) {
    char post[jml_maks][token_maks];
    int stack[jml_maks];
    int i, n = 0, top = -1, kiri, kanan, hasil;

    isiPostOrder(tree, 1, post, &n);

    printf("PostOrder / postfix: ");
    for (i = 0; i < n; i++) printf("%s ", post[i]);
    printf("\n");

    printf("Simulasi stack:\n");
    for (i = 0; i < n; i++) {
        if (!isOperator(post[i])) {
            stack[++top] = atoi(post[i]);
            printf("PUSH %s\n", post[i]);
        } else {
            if (top < 1) return false;
            kanan = stack[top--];
            kiri = stack[top--];
            if (post[i][0] == '+') hasil = kiri + kanan;
            else hasil = kiri - kanan;
            printf("%d %c %d = %d\n", kiri, post[i][0], kanan, hasil);
            stack[++top] = hasil;
        }
    }

    if (top != 0) return false;
    *result = stack[top];
    return true;
}
