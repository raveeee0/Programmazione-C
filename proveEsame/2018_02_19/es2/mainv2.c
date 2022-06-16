#include<stdio.h>
#include<stdlib.h>

#define N 3
#define M 4

void stampa_somma_righe_pari_dispari_ricorsiva(int mat[][M], int x /* 0 */, int y /* 0 */, int sumpari /* 0 */, int sumdispari /* 0 */);

int main(){
    int mat[N][M] = {{0, 0, 0, 6},
                     {4, 5, 6, 7},
                     {0, 2, 110, 3},
                    };

    stampa_somma_righe_pari_dispari_ricorsiva(mat, 0, 0, 0, 0);

    return EXIT_SUCCESS;

}


void stampa_somma_righe_pari_dispari_ricorsiva(int mat[][M], int x /* 0 */, int y /* 0 */, int sumpari /* 0 */, int sumdispari /* 0 */){
    // Se arrivo alla fine di una riga (ultima colonna)
    if(y == M - 1) {
        // Righe dispari
        if (x % 2 == 0) {
            // Se ci sono altre righe dispari
            if(x + 2 < N)
                return stampa_somma_righe_pari_dispari_ricorsiva(mat, x + 2, 0, sumpari, sumdispari + mat[x][y]);

            else {
            //  Inizio della somma delle righe pari (indice x dispari)
                return stampa_somma_righe_pari_dispari_ricorsiva(mat, 1, 0, sumpari, sumdispari + mat[x][y]);
            }
        } else {    // Righe pari
            // Se ci sono altre righe pari
            if(x + 2 < N)
                return stampa_somma_righe_pari_dispari_ricorsiva(mat, x + 2, 0, sumpari + mat[x][y], sumdispari);

            //Fine
            fprintf(stdout, "Somma righe pari: %d\t\tSomma righe dispari: %d\n", sumpari + mat[x][y], sumdispari);
            return;
        }
    }

    // Scorrimento, verifico su quale tipo di riga (pari/dispari) devo aggiornare la somma
    if (x % 2 == 0)
        return stampa_somma_righe_pari_dispari_ricorsiva(mat, x, y + 1, sumpari, sumdispari + mat[x][y]);
    return stampa_somma_righe_pari_dispari_ricorsiva(mat, x, y + 1, sumpari + mat[x][y], sumdispari);
}