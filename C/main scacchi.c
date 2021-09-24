
/*Lo scopo di questo progetto è quello di simulare il gioco degli scacchi, generiamo una scacchiera 8x8, inseriamo i pedoni nella scacchiera e infine la regina, facendo attenzione a non sovrascrivere i pedoni. La nostra Regina potrà mangiare i pedoni in tutte le direzioni(su,giù,sinistra,destra,diagonale...)
 Infine visualizzeremo quali pedoni può mangiare e in che posizioni si trovano.*/
/*
Librerie incluse per l'utilizzo di vare function all'interno del programma.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*
Prototipi delle funzioni.
*/
void printfscacchi(char [][8]);
void PedoneSu(char [][8],char [], int, int);
void PedoneGiu(char [][8],char [], int, int);
void PedoneDestra(char [][8],char [], int, int);
void PedoneSinistra(char [][8],char [], int, int);
void PedoneDiag1(char [][8], char [], int, int);
void PedoneDiag2(char [][8], char [], int, int);
void PedoneDiag3(char [][8], char [], int, int);
void PedoneDiag4(char [][8], char [], int, int);


int main()
{
    /*
    Dichiarazione delle variabili.
    */
    int i; /* Contatore per i cicli while.*/
    int pos_riga = 0, pos_col = 0; /* Variabili utilizzate per riempire la scacchiera in modo pseudo-random*/
    srand(time(NULL)); /* Funzione che inizializza lo pseudo-random. Se non ci fosse, ad ogni avvio del programma
                          la posizione dei pedoni e della regina, sarebbe sempre la stessa.*/
    char colonne[8] = {'a','b','c','d','e','f','g','h'}; /*Dichiarazione e inizializzazione della stringa utilizzata
                                                         per definire le colonne della scacchiera.*/
   
    
    char scacchiera[][8] =
    {{'b','n','b','n','b','n','b','n'},
    {'n','b','n','b','n','b','n','b'},
    {'b','n','b','n','b','n','b','n'},
    {'n','b','n','b','n','b','n','b'},
    {'b','n','b','n','b','n','b','n'},
    {'n','b','n','b','n','b','n','b'},
    {'b','n','b','n','b','n','b','n'},
    {'n','b','n','b','n','b','n','b'}}; /* Dichiarazione e inizializzazione della scacchiera.*/
    
    i = 0; /* Inizializzazione del contatore.*/

    while(i<8)
    {
        pos_riga = rand()%8;
        pos_col = rand()%8;

        if(scacchiera[pos_riga][pos_col] == 'b' || scacchiera[pos_riga][pos_col] == 'n')
        {
            scacchiera[pos_riga][pos_col] = 'P';
            i++;
        }
    } /* Ciclo while: ripete il clclo finchè la condizione resta soddisfatta.
         Posiziona randomicamente i pedoni (8) nella scacchiera, facendo in modo da non sovrascrivere
         eventuali pedoni. Alla fine, il contatore viene autoincrementato.*/
    
    i = 0; /* Il contatore viene nuovamente azzerato in modo da poterlo riutilizzare.*/


    while(i<1)
    {
        pos_riga = rand()%8;
        pos_col = rand()%8;

        if(scacchiera[pos_riga][pos_col] == 'b' || scacchiera[pos_riga][pos_col] == 'n')
        {
            scacchiera[pos_riga][pos_col] = 'R';
            i++;
        }
    } /* Altro ciclo while: Posiziona in modo casuale la regina nella scacchiera, facendo attenzione a non eliminare
         eventuali pedoni.*/

    printf("Regina in %c%d puo' catturare i seguenti pedoni: \n\n",colonne[pos_col],8-pos_riga); /* Stampiamo la posizione della
                                                                                                  regina.*/
    PedoneSu(scacchiera,colonne,pos_riga,pos_col);/* Richiamo della funzione PedoneSu.*/
    PedoneGiu(scacchiera,colonne,pos_riga,pos_col);/* Richiamo della funzione PedoneGiu.*/
    PedoneDestra(scacchiera,colonne,pos_riga,pos_col);/* Richiamo della funzione PedoneDx.*/
    PedoneSinistra(scacchiera,colonne,pos_riga,pos_col);/* Richiamo della funzione PedoneSx.*/
    PedoneDiag1(scacchiera, colonne, pos_riga, pos_col);
    PedoneDiag2(scacchiera, colonne, pos_riga, pos_col);
    PedoneDiag3(scacchiera, colonne, pos_riga, pos_col);
    PedoneDiag4(scacchiera, colonne, pos_riga, pos_col);
    printfscacchi(scacchiera);/* Richiamo della funzione StampaScacchiera*/
   
  
}


void printfscacchi(char scacchiera[][8]) /* Funzione StampaScacchiera, a cui passiamo la matrice "scacchiera" di tipo char.*/
{
    int i,j; /* Dichiarazione di due variabili interne alla funzione, quindi locali ad essa.*/

    printf("\n");
    printf("   a b c d e f g h\n\n");
    for(i=0;i<8;i++) /*Ciclo for: inizializza la variabile i, la incrementa ad ogni ciclo fatto, e si ferma quando
                             l'indice raggiunge il valore "8".*/
    {
        printf("%d ",8-i);
        for(j=0;j<8;j++)
        {
            printf(" %c", scacchiera[i][j]);
            
        }
        printf("\n");
    }
}


void PedoneSu(char scacchiera[][8], char colonne[], int posRiga, int posCol){
   
   int i = posRiga;
   int pedoneTrovato = 0;
   
   while(i >= 0 && pedoneTrovato == 0){
      
      if(scacchiera[i][posCol] == 'P'){
         printf("Pedone in %c%d\n", colonne[posCol], 8 - i);
         pedoneTrovato = 1;
      }
      else
         i--;
   }
}

void PedoneGiu(char scacchiera[][8], char colonne[], int posRiga, int posCol){
   
   int i = posRiga;
   int pedoneTrovato = 0;
   
   while(i < 8 && pedoneTrovato == 0){
      
      if(scacchiera[i][posCol] == 'P'){
         printf("Pedone in %c%d\n", colonne[posCol], 8 - i);
         pedoneTrovato = 1;
      }
      else
         i++;
   }
}





void PedoneDestra(char scacchiera[][8], char colonne[], int pos_riga, int pos_col){

   int i = pos_col;
   int pedoneTrovato = 0;
   
   while(i < 8 && pedoneTrovato == 0){
      
      if(scacchiera[pos_riga][i] == 'P'){
         printf("pedone in %c%d\n", colonne[i], 8 - pos_riga);
         pedoneTrovato = 1;
      }
      else
         i++;
   }
}

void PedoneSinistra(char scacchiera[][8], char colonne[], int pos_riga, int pos_col){
   
   int i = pos_col;
   int pedoneTrovato = 0;
   
   while(i >= 0 && pedoneTrovato == 0){
      
      if(scacchiera[pos_riga][i] == 'P'){
         printf("pedone in %c%d\n", colonne[i], 8 - pos_riga);
         pedoneTrovato = 1;
      }
      else
         i--;
   }
}

void PedoneDiag1(char scacchiera[][8], char colonne[], int pos_riga, int pos_col){
   
   int i = pos_riga, j = pos_col;
   int pedoneTrovato=0;

   while(j >= 0 && i < 8 && pedoneTrovato == 0){
      
      if(scacchiera[i][j] == 'P'){
         printf("Pedone in %c%d\n", colonne[j], 8 - i);
         pedoneTrovato = 1;
      }
      else{
         j--;
         i++;
      }
   }
}

void PedoneDiag2(char scacchiera[][8], char colonne[], int pos_riga, int pos_col){
   
   int i = pos_riga, j = pos_col;
   int pedoneTrovato = 0;
   
   while(i >= 0 && j < 8 && pedoneTrovato == 0){
      
      if(scacchiera[i][j] == 'P'){
         printf("Pedone in %c%d\n", colonne[j], 8 - i);
         pedoneTrovato = 1;
      }
      else{
         i--;
         j++;
      }
   }
}

void PedoneDiag3(char scacchiera[][8], char colonne[], int pos_riga, int pos_col){
   
   int i = pos_riga, j = pos_col;
   int pedoneTrovato = 0;
   
   while(i >= 0 && j >= 0 && pedoneTrovato == 0){
      
      if(scacchiera[i][j] == 'P'){
         printf("pedone in %c%d\n", colonne[j], 8 - i);
         pedoneTrovato = 1;
      }
      else{
         i--;
         j--;
      }
   }
}

void PedoneDiag4(char scacchiera[][8], char colonne [], int pos_riga, int pos_col){
   
   int i = pos_riga, j = pos_col;
   int pedoneTrovato = 0;
   
   while(i < 8 && j < 8 && pedoneTrovato == 0){
      
      if(scacchiera[i][j] == 'P'){
         printf("Pedone in %c%d\n", colonne[j], 8 - i);
         pedoneTrovato = 1;
      }
      else{
         i++;
         j++;
      }
   }
}
