#include <stdio.h>
#include <string.h>

#define MAX_CONATTATTI 100

struct Contatto{
    char nome[30];
    char cognome[30];
    char telefono[11];
};

int main() {
    Contatto rubrica[MAX_CONTATTI];
    int n = 0;

    while (scelta != 5){
        printf("\n***RUBRICA***\n");
        printf("1. Aggiungi contatto\n");
        printf("2. Visualizza tutti i contatti\n");
        printf("3. Ricerca contatto per cognome\n");
        printf("4. Elimina contatto per cognome\n");
        printf("5. Esci\n");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                aggiungiContatto(rubrica, &n);
                break;
            case 2:
                visualizzaContatti(rubrica, n);
                break;
            case 3:
                cercaContatto(rubrica, n);
                break;
            case 4:
                eliminaContatto(rubrica, &n);
                break;
            case 5:
                printf("Uscita dal programma.\n");
                break;
            default:
                printf("Scelta non valida!\n");
        }
    };

    return 0;
}

void aggiungiContatto(Contatto rubrica[], int *n) {
    if (*n >= MAX_CONTATTI) {
        printf("Rubrica piena!\n");
        return;
    }

    printf("Inserisci nome: ");
    scanf("%29s", rubrica[*n].nome);

    printf("Inserisci cognome: ");
    scanf("%29s", rubrica[*n].cognome);

    printf("Inserisci telefono: ");
    scanf("%10s", rubrica[*n].telefono);

    (*n)++;
    printf("Contatto aggiunto con successo!\n");
}

void visualizzaContatti(Contatto rubrica[], int n) {
    if (n == 0) {
        printf("Rubrica vuota.\n");
        return;
    }

    printf("\n***ELENCO CONTATTI***\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s %s - %s\n", i + 1, rubrica[i].nome, rubrica[i].cognome, rubrica[i].telefono);
    }
}

void cercaContatto(Contatto rubrica[], int n) {
    char cognome[30];
    int trovato = 0;

    printf("Inserisci cognome da cercare: ");
    scanf("%29s", cognome);

    for (int i = 0; i < n; i++) {
        if (strcmp(rubrica[i].cognome, cognome) == 0) {
            printf("Contatto trovato: %s %s - %s\n",
                   rubrica[i].nome, rubrica[i].cognome, rubrica[i].telefono);
            trovato = 1;
        }
    }

    if (!trovato) {
        printf("Nessun contatto trovato %s.\n", cognome);
    }
}

void eliminaContatto(Contatto rubrica[], int *n) {
    char cognome[30];
    int pos = -1;

    printf("Inserisci cognome del contatto da eliminare: ");
    scanf("%29s", cognome);

    for (int i = 0; i < *n; i++) {
        if (strcmp(rubrica[i].cognome, cognome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Nessun contatto trovato %s.\n", cognome);
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        rubrica[i] = rubrica[i + 1];
    }

    (*n)--;
    printf("Contatto eliminato con successo.\n");
}