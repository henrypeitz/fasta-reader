# FASTA Sequence Reader

## Overview
A lightweight command-line utility written in C for parsing and processing FASTA-formatted biological sequence data. 

This project explores low-level memory management and custom data structures in C through the implementation of a FASTA parser tailored for bioinformatics workloads.

## Current Architecture
The parser currently relies on a custom Linked List implementation to store sequences in memory. The core mechanism involves reading the FASTA file line-by-line and dynamically appending sequence data to the nodes. 

In the future, I hope to upgrade the sequence buffer from a fixed-size array to a dynamically allocated using `malloc` and `realloc`. This removes artificial buffer caps and allows the program to scale up to the limits of available system memory.

## Known Limitations & Trade-offs
While functional, this project is still evolving. Here are the current main technical limitations:
* **Fixed-Size Headers and Sequences:** The FASTA header currently uses a fixed buffer (`char header[256]`) and FASTA sequences uses a `char data[4096]`. Unusually long metadata lines might be truncated.
* **Full In-Memory Processing:** The application currently loads the entire sequence into RAM. This is inefficient for extremely large datasets (e.g., full human genomes) on machines with limited memory.
* **Architectural Choices:** Most of the core functions currently reside within the `linkedlist` module. This architecture was chosen for rapid prototyping, but it limits modularity.

* **Error Handling & Validation**
    * **Input Sanitization:** Invalid nucleotide characters within the sequence body are not currently validated or filtered.
    * **Structural Integrity:** Malformed FASTA structures (e.g., missing `>` header indicators) are not explicitly caught and may lead to undefined behavior.
    * **File Operations:** File I/O errors and resource allocation failures are only partially handled.

## Future Roadmap
To elevate this project quality, the following architectural upgrades are planned:

1. **Defensive Parsing:** Enforce explicit validation of the FASTA structure and implement robust input sanitization to detect and handle invalid characters gracefully.
2. **Error Propagation:** Improve file I/O and memory allocation error reporting to safely handle resource exhaustion and prevent memory corruption.
3. **Algorithmic Optimization:**
Replace linear codon table lookup with direct index mapping to reduce constant overhead.
4. **Data Structure Refactoring:** Based on further evaluation, a dynamic array is likely a more appropriate data structure than a linked list and will be implemented in v2. This will prevent truncation and eliminate the 4KB sequence limit.
5. **GUI Implementation:** Develop a lightweight Graphical User Interface to make the tool accessible to end-users outside the terminal.

## Build
``` 
gcc main.c ./ll/linkedlist.c ./utils/func_utils.c -o fasta_reader
```
## Running

```
./fasta_reader <example>.fasta
```

## Output
Choosing the translated sequence function, will output:

```terminal
--------- YOUR ANALYSIS START HERE ---------
>NC_045512.2 Severe acute respiratory syndrome coronavirus 2 isolate Wuhan-Hu-1, incomplete genome
ANALYSIS 1:
Ile Lys Gly Leu Tyr Leu Pro Arg STOP Gln Thr Asn Gln Leu Ser Ile Ser Cys Arg Ser Val Leu STOP Thr Asn Phe Lys Ile Cys Val Ala Val Thr Arg Leu His Ala STOP Cys Thr His Ala Val STOP Leu Ile Thr Asn Tyr Cys Arg STOP Gln Asp Thr Ser Asn Ser Ser Ile Phe Cys Arg Leu Leu Thr Val Ser Ser Val Leu Gln Pro Ile Ile Ser Thr Ser Arg Phe Arg Pro Gly Val Thr Glu Arg STOP Asp Gly Glu Pro Cys Pro Trp Phe Gln Arg Glu Asn Thr Arg Pro Thr Gln Phe Ala Cys Phe Thr Gly Ser Arg Arg Ala Arg Thr Trp Leu Trp Arg Leu Arg Gly Gly Gly Leu Ile Arg Gly Thr Ser Thr Ser STOP Arg Trp His Leu Trp 

>X06719.1 Hop stunt viroid citrus isolate (HSV-cit) complete genome (variant 2)
ANALYSIS 2:
Leu Gly Asn Ser Arg Val Ala Ala Trp Ala Ser Lys Glu Lys Thr Arg Gln Gly Gly Asp Leu Pro Glu Lys Gly Ala Pro Gly Gln Leu Phe Ser Glu Ser Ser Glu Arg Arg Arg Arg Glu Gly Arg Gly Ala Leu Glu STOP Arg Leu Leu Ala Ser Lys His His Arg Ser Ser Leu Leu Leu Leu Pro Ser Pro Gly Ser Ser Asp Glu Thr Arg Pro Val Ala Ser Pro Leu Gly Ser Ser Ser Asn Leu Leu Phe Val Tyr Leu Ser Leu Cys Arg Gly Ser Ser Leu Glu Pro 


--------- YOUR ANALYSIS ENDED HERE ---------
Press ENTER to return to menu.
```
