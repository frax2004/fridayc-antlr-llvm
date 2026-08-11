(Titolo ancora da definire)
# Il linguaggio di programmazione Friday: next-gen C

## Indice degli argomenti trattati
### Che cos'e' il Friday
Introduzione al linguaggio di programmazione e al suo compilatore.
### Da dove nasce l'esigenza di un nuovo linguaggio di programmazione C-like
Confronto con altri linguaggi C-like moderni che mirano agli stessi obiettivi e presentazione della motivazione alla base del progetto friday come "il meglio di tutti i mondi".
### Obiettivi del linguaggio volti a risolvere problemi legati storicamente al C
- Introduzione ai problemi legati al C e "best practises" per un codice pulito.
- Come friday mira ad eliminare tali problemi.
- Il principio Zero (Runtime) Overhead Abstractions.

### Design del linguaggio Friday
#### Sintassi
Descrizione sintattica del linguaggio friday
#### Semantica
Descrizione semantica del linguaggio friday
#### Memory Layout / Memory Management
- Allocatori
- Esecuzione differita
- Allocazione Stack Vs Allocazione Heap
#### Friday Standard Library
Libreria standard che accompagna il linguaggio
### Architettura implementativa
#### Strumentologia
##### Il Software ANTLR
Breve introduzione ad antlr4, funzionalita, cosa mi ha permesso di fare e confronto con altri generatori automatici di parser e lexer (come quello visto al corso di compilatori flex-bison)
##### Tecnologia LLVM
Breve descrizione del progetto llvm, applicazioni esistenti, vantaggi dell'uso di tale componente software per la realizzazione del backend di fridayc e confronti con altre possibili soluzioni.
- Use case: Clang
#### Algoritmi e strutture dati
Questa sezione descrive gli algoritmi e le strutture dati (non banali) che sono stati impiegati per risolvere i problemi precedentemente descritti

### Compatibilita con C e con tutti i linguaggi che hanno LLVM come target backend
- Foreign Function Interface built-in
- Esempi di esecuzione in un ambiente multi-linguaggio

### Presentazione di esempi pratici e valutazione delle performance rispetto a C/C++
- Allocazione dinamica
- Cast impliciti
- Overflow numerico
- Benchmarking rispetto a C/C++
