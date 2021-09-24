//
//  main.c
//  rivista musicale
//Si vuole simulare la gestione automatizzata di uno scaffale di riviste musicali. Si suppone di avere un massimo di n tipi di riviste con il proprio titolo, codice identificativo, prezzo, quantità in scorta, il genere specifico della rivista (jazz, rock, pop, punk, ...) e dagli strumenti trattati (batteria, chitarra, tromba … fino ad un massimo di m).   Permettere all’utente di:  • Acquistare se è possibile una rivista dato il nome (controllare se la quantità è zero).• Dato un genere visualizzare tutte le riviste corrispondenti.  • Dato un strumento musicale visualizzare le riviste in cui è inserito, con il costo e la disponibilità.//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


 /* generiamo la nostra struct scaffale dove abbiamo codice, titolo, prezzo, quantità, generi musicali e strumenti delle riviste.*/
struct scaffale {
    int       codice_id;
    char      titolo[50] ;
    float     prezzo;
    int       quantità;
    char      generi[50];
    char      strumenti[50];
}SCAFFALE[]={
        {001,"Jazzit",20.00,10,"Jazz","sax,batteria,piano"},
        {002,"RollingStone",30.50,20,"Rock","chitarra,batteria"},
        {003,"America",20.00,10,"Jazz",",sax,batteria,piano"},
        {004,"Decibel Magazine",19.00,5,"Rock","chitarra,basso,batteria"},
        {005,"StoMagazine",15.00,15,"HipHop","batteria,chitarra"},
        {006,"Pop Magazine",33.50,11,"Pop","chitarra,piano,batteria"},
        {007,"FreePop",35.00,0,"Pop","chitarra,piano"},
        {0010,"Vibe",25.00,10,"HipHop","batteria,basso"},
        {0011,"Metal",45.00,30,"Metal","chitarra,piano,batteria"},
        {012,"Vice",32.50,0,"HipHop","batteria,basso"}
};

int main(){
   
    
    char strumento [30];
    char genere[20];
    int menù;
    char rivista[20];
    int i;
    printf("QUESTO E' UNO SCAFFALE AUTOMATIZZATO DI RIVISTE MUSICALI\n"); //Sviluppiamo l'interfaccia del nostro menù
    printf("ECCO LE RIVISTE DISPONIBILI E I RISPETTIVI PREZZI\n");
    for (i=0;i<10;i++){
        printf( "%s %f\n\n",SCAFFALE[i].titolo,SCAFFALE[i].prezzo);} //con questo ciclo for andiamo a visualizzare tutto il menù(titoli e prezzi).
    printf("1)COMPRA LA TUA RIVISTA RICERCANDOLA COL NOME\n"); //caso 1 switch.
    printf ("2)INSERIRE IL GENERE PER VISUALIZZARE LE RIVISTE CORRISPONDENTI\n");//caso 2.
    printf("3)INSERIRE STRUMENTO MUSICALE PER VISUALIZZARE LE RIVISTE IN CUI E' INSERITO, CON PREZZO E GENERE\n");//caso 3.
    scanf("%d",&menù);
    switch (menù) {
        case 1:
            printf("quale rivista vuoi?\n");
            scanf("%s",&rivista);
             
            for (i=0; i<10; i++) { //ciclo che ricerca la rivista tramite nome.
                if (strcmp (SCAFFALE[i].titolo,rivista)==0){
                    if (SCAFFALE[i].quantità==0)
                        printf("La rivista non è più disponibile... torna a trovarci al più presto!\n");
                    else{
                            printf("La rivista è disponibile.. Hai appena acquistato una copia!\n");
                        SCAFFALE[i].quantità--;
                }
                    break;
                }
    
            }
             if (i==10)
                 printf("Non esiste nessuna rivista con questo nome,riprova.\n");}
    switch (menù) {
        
     
        case 2:
            printf("Inserire il genere per visualizzare le riviste corrispondenti ****ATTENZIONE ALLE LETTERE MAIUSCOLE\n");
            scanf("%s",&genere);
            for (i=0;i<10;i++){ //ciclo che ricerca le riviste inserendo il genere.
               
                if (strcmp (SCAFFALE[i].generi,genere)==0){
                    printf("%s\n\n",SCAFFALE[i].titolo);}
                
                  
            }
            break;
                }
    switch (menù) {
        case 3:
            printf("Inserire lo strumento per visualizzare rivista,prezzo e disponibilità\n");
            scanf("%s",&strumento); 
            for(i=0;i<10;i++){ //ciclo che ricerca le riviste inserendo gli strumenti.
                if(strcmp(SCAFFALE[i].strumenti,strumento)==0)
                    printf("%s,%f,%d\n\n",SCAFFALE[i].titolo,SCAFFALE[i].prezzo,SCAFFALE[i].quantità);
                    
                    
                    
                    
                    
                    
                }
            
            
            
            break;
    }
    printf("Grazie per aver utilizzato la nostra rivista\n\n\n\n"); //fine del menù.
  
   
}

