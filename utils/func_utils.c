#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_utils.h"

const char *get_amino_acid(const char *codon)
{
    static const char *codons[] = {
        "TTT", "TTC", "TTA", "TTG", "CTT", "CTC", "CTA", "CTG",
        "ATT", "ATC", "ATA", "ATG", "GTT", "GTC", "GTA", "GTG",
        "TCT", "TCC", "TCA", "TCG", "CCT", "CCC", "CCA", "CCG",
        "ACT", "ACC", "ACA", "ACG", "GCT", "GCC", "GCA", "GCG",
        "TAT", "TAC", "TAA", "TAG", "CAT", "CAC", "CAA", "CAG",
        "AAT", "AAC", "AAA", "AAG", "GAT", "GAC", "GAA", "GAG",
        "TGT", "TGC", "TGA", "TGG", "CGT", "CGC", "CGA", "CGG",
        "AGT", "AGC", "AGA", "AGG", "GGT", "GGC", "GGA", "GGG"};

    static const char *names[] = {
        "Phe", "Phe", "Leu", "Leu", "Leu", "Leu", "Leu", "Leu",
        "Ile", "Ile", "Ile", "Met", "Val", "Val", "Val", "Val",
        "Ser", "Ser", "Ser", "Ser", "Pro", "Pro", "Pro", "Pro",
        "Thr", "Thr", "Thr", "Thr", "Ala", "Ala", "Ala", "Ala",
        "Tyr", "Tyr", "STOP", "STOP", "His", "His", "Gln", "Gln",
        "Asn", "Asn", "Lys", "Lys", "Asp", "Asp", "Glu", "Glu",
        "Cys", "Cys", "STOP", "Trp", "Arg", "Arg", "Arg", "Arg",
        "Ser", "Ser", "Arg", "Arg", "Gly", "Gly", "Gly", "Gly"};

    for (int i = 0; i < 64; i++)
    {
        if (strcmp(codon, codons[i]) == 0)
        {
            return names[i];
        }
    }
    return "???";
}

char get_complement(char base)
{
    switch (base)
    {
    case 'A':
        return 'T';
    case 'T':
        return 'A';
    case 'C':
        return 'G';
    case 'G':
        return 'C';
    default:
        return '?';
    }
}