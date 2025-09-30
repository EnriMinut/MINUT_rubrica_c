#include <stdio.h>
#include <string.h>

#define MAX_CONATTATTI 100

struct Contatto{
    char nome[30];
    char cognome[30];
    char telefono[10];
};

int main() {
    Contatto rubrica[MAX_CONTATTI];
    int n = 0;

    while (scelta != 5){
        printf("\nRUBRICA \n");
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