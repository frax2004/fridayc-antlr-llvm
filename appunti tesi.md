- Paragrafo 2.1 - 2.3 ha senso che siano spostati nel capitolo 3
- Refuso: indice che contiene descrizioni immagini
- Per le immagini: rimuovere bordi e aggiungere colonna di padding
- dettagli tecnici : semplificare (togliere narrowing)
- le definizioni di parole (tipo classi di contesto) vanno vicino la spiegazione
- inserire esempietti piccoli (es. tra un non terminale e il contesto) (esempi di antlr e di llvm).
- 2.24 : specificare anche l'allocazione dinamica
- definire memcpy, alignof, explicit this (dare una definizione piuttosto che fornire solo il tipo).
- dare esempio su explicit this (tutte le forme).
- spiegare AOT e JIT
- utilizzo file (esempio da mettere nel defer) da compattare
- quando si fa di riferimento alla classe di contesto, spiegare che si rieferisce alla classe. (fase di risoluzione dei tipi).
- esempi su fase di analisi statica (analisi dei tipi) e cambiare un po la forma (pagina 29).
- le formule da renderizzare in latex.
- anziche dimostrare i grafi di dipendenze, citare wikipedia (mettere in risalto esempi e citare l'ordine topologico).
- aggiungere il grafo di dipendenza delle strutture (corretto e non corretto).
- sostituire l'algoritmo di lookup con pseudo codice delll'algoritmo (codice completo in appendice).
- esempi di conversioni ammesse e conversioni proibite (sintassi corretta e sintassi sbagliata).
- inserire riferimento al repository.
- Confronto con linguaggi (esempi piccoli e interlacciati): una sola sezione e spiegare che cosa è un allocatore. confrontare con zig in una tabella che mostra i casi d'uso e riferimenti all appendice del resto del codice.
- la prima volta che spuntano dei termini si scrivono in corsivo o in bold.
- spiegazione delle TU e moduli nel capitolo 2.

- il caso del game of life è da presentazione (da togliere)

- appendice va dopo i riferimenti bibliografici e sono due cose separate e unificare gli indici con le descrizioni per esteso.

- dblp per le citazioni
- notazione x.y.z per i paragrafi


Presentazione:
- 5 slide max
  - 1 descrizione del problema (motivazione): problemi dei linguaggi c-like
  - 2 come si risolvono (approcci grafici su defer e la pila delle istruzioni)
  - 3 benchmarking (specificando gli strumenti utilizzati)

- niente codice o pseudo codice (max 1 riga)
