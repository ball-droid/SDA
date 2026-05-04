#ifndef KALKULATOR_TREE_H
#define KALKULATOR_TREE_H

#include "boolean.h"

/* Header ADT tree untuk studi kasus kalkulator non-binary. */

#define jml_maks 50
#define token_maks 16
#define nil 0

typedef int address;

typedef struct {
    char info[token_maks];
    address ps_fs;
    address ps_nb;
    address ps_pr;
} nbtree;

typedef nbtree Isi_Tree[jml_maks + 1];

void InitTree(Isi_Tree tree);
boolean BuildExpressionTree(Isi_Tree tree, const char *expression);
void PostOrder(Isi_Tree tree);
void PrintTree(Isi_Tree tree);
boolean EvaluateTree(Isi_Tree tree, int *result);

#endif
