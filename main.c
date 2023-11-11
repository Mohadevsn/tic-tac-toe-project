//powered by wadestudiogame
#include <stdio.h>


void printBoard();
void resetBoard();
int checkfreeSpace() ;
int checkfreeSpaceReturn;
void playerOneMove() ;
void playerTwoMove() ;
int checkWinner() ;
void tableauScore() ;
int codeFinJeu;
int endGame ;
char board[3][3];
int playerX = 1 ;
int playerO = 0 ;
int i , j ;
int x, y, manche, scoreX, scoreY ;
int freeSpaces ;
int choice ;
int choice_2 ;

int main()//voici la fonction principale
{


    scoreX = 0 ;
    scoreY = 0 ;
    freeSpaces = 9 ; //nombre de deplacement possible

    printf("\t\t|------------------------------------|\n");
    printf("\t\t|              TIC TAC TOE           |\n");
    printf("\t\t|------------------------------------|\n");

    printf("\t\t\tMenu general\n");
    printf("\t\t1- Jouer \n");
    printf("\t\t0- Quitter le jeu \n");
    printf("\n\n\n\t\tPowered by WadestudioGame \n");

    printf("Entrez votre choix :");
    scanf("%d", &choice);
    

    switch (choice)
    {
    case 1 : {
         printf("\t\t|------------------------------------|\n");
    printf("\t\t|              TIC TAC TOE           |\n");
    printf("\t\t|------------------------------------|\n");
    printf("\t\t\tle joueur 1 prendra : X\n");
    printf("\t\t\tle joueur 2 prendra : O\n");

    printf("La partie va se derouler en X manches choisies au prealable \n");
    do
    {
        printf("Combien de manches voulez vous jouer 1 ou 3 ? : ");
        scanf("%d", &manche);
    }while(manche < 0 || manche > 3 || (manche % 2 == 0));


    while(scoreX + scoreY < manche && freeSpaces != 0) //tant que la somme des scores ne depace pas le nombre de manche le jeu continue
    {
        resetBoard();
        printBoard();
        checkWinner();
        while(checkWinner() < 1)//tant qu'il reste de l'espace vide le jeu continue et s'arrete ici des que les 9 cases sont occuppees
        {
                for(i=0; i < 9 ; i++) 
                {
                    //pour le tour des joueurs on place des conditions telles que si le modulo est pair X joue sinon O joue
                        if(i % 2 == 0)
                        {   
                            checkfreeSpace();
                            playerOneMove();
                            checkWinner();
                            printBoard();
                        }
        
                        
                        else
                        {
                            checkfreeSpace();
                            playerTwoMove();
                            checkWinner();
                            printBoard();
                        }

                        if(checkWinner() == 1){
                            printf("**************Le joueur 1 remporte la manche ************\n");
                            scoreX = scoreX + 1 ; //cette affectation permet de sortir de la boucle : fin du jeu
                            tableauScore();
                            i = 10 ;
                            if(scoreX + scoreY == manche && scoreX > (manche / 2)){
                            codeFinJeu = 1 ;
                            }
                        }
                        else if(checkWinner() == 2)
                        {
                            printf("**************Le joueur 2 remporte la manche *************\n");
                            scoreY = scoreY + 1;
                            tableauScore();
                            i = 10 ;
                            if(scoreX + scoreY == manche && scoreY > (manche / 2)){
                            codeFinJeu = 1 ;
                            }
                        }
                        else if(checkWinner() == 3){
                            printf("************** Nul *************\n");
                            i = 10 ;
                            codeFinJeu = 1 ;
                        }


                }
                        
        }
    }

        if(scoreX > scoreY){
            printf("*********Le joueur(se) 1 remporte le jeu ***********\n");
        }
        else if(scoreY > scoreX){
            printf("*********Le joueur(se) 2 remporte le jeu ***********\n");
        }
        else{
            printf("*********La partie est nulle ***********************\n");
        }

        
    
        }
            break;
        break;
        
        default:
        
            break;
        }
    return 0 ;    
}
   

    


//initialisation du tableau
void resetBoard(){
    for(  i = 0 ; i < 3 ; i++)
    {
        for( j = 0 ; j < 3 ; j++)
        {
            board[i][j] =  '.'  ;
        }
    }
}

//affichage tableau
void printBoard(x, y)
{
            tableauScore() ;
            printf("\t\tY");
            printf("\n\t\t   X");
            printf("        0    1     2\n");
            printf("\t\t\t|-----|-----|-----|\n");
            printf("\t\t0\t|  %c  |  %c  |  %c  |\n", board[0][0] ,board[0][1],board[0][2]);
            printf("\t\t\t|-----|-----|-----|\n");
            printf("\t\t1\t|  %c  |  %c  |  %c  |\n", board[1][0] ,board[1][1],board[1][2]);
            printf("\t\t\t|-----|-----|-----|\n");
            printf("\t\t2\t|  %c  |  %c  |  %c  |\n", board[2][0] ,board[2][1],board[2][2]);
            printf("\t\t\t|-----|-----|-----|\n");
            printf("\n");
            
}
//tour du joueur un 1 'X'
void playerOneMove()
{
        do
        {
            printf("Tour du joueur 1 \n");
            printf("Veuiller choisir le numero de la ligne que vous voulez placer X (0-2) :");
            scanf("%d", &x);
            printf("Veuiller choisir le numero de la colonne que vous voulez placer X (0-2) :");
            scanf("%d", &y);
        }while(x < 0 || x > 2 || y < 0 || y > 2);
            
            while(checkfreeSpace() == 0){
                printf("Cette case est occupée!!!\n");
                do
                {
                    printf("Veuillez rechoisir le numero de la ligne que vous voulez placer X (0-2) :");
                    scanf("%d", &x);
                    printf("Veuillez rechoisir le numero de la colonne que vous voulez placer X (0-2) :");
                    scanf("%d", &y);
                        
                }while(x < 0 || x > 2 || y < 0 || y > 2 && checkfreeSpace(x, y) == 1);
            }
        
            
                board[x][y] = 'X' ;

            
            freeSpaces-- ;
}
//tour du joueur 2 'O'
void playerTwoMove()
{   
        do
        {
            printf("Au tour du joueur 2\n");
            printf("Veuiller choisir le numero de la ligne que vous voulez placer O (0-2) :");
            scanf("%d", &x);
            printf("Veuiller choisir le numero de la colonne que vous voulez placer O (0-2) :");
            scanf("%d", &y);
        }while(x < 0 || x > 2 || y < 0 || y > 2);
            
           while(checkfreeSpace(x, y)== 0){
                printf("Cette case est occupée!!!\n");
                do
                {
                    printf("Veuillez rechoisir le numero de la ligne que vous voulez placer O (0-2) :");
                    scanf("%d", &x);
                    printf("Veuillez rechoisir le numero de la colonne que vous voulez placer O (0-2) :");
                    scanf("%d", &y);
                        
                }while(x < 0 || x > 2 || y < 0 || y > 2 && checkfreeSpace(x, y) == 1);

            }
            
            
            board[x][y] = 'O' ;
            freeSpaces-- ;
   
}
//verification de la case voulue si elle est vide
int checkfreeSpace(){
            if(board[x][y] == 'X'){
                checkfreeSpaceReturn = 0 ;
            }
            if(board[x][y] == 'O'){
                checkfreeSpaceReturn = 0 ;
            }

            if(board[x][y] == '.'){
                checkfreeSpaceReturn = 1 ;
            }
            return checkfreeSpaceReturn ;
}
//Verification du vainqueur 
int checkWinner(){
    endGame = 0 ;
    //victoire joueur 1
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
    {
        endGame = 1 ;
    }
    if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){

        endGame = 1 ;
    }
    if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){

        endGame = 1 ;
    }
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X'){

        endGame = 1 ;
    }
    if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X'){

        endGame = 1 ;
    }
    if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X'){

        endGame = 1 ;
    }
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){

        endGame = 1 ;
    }
    if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X'){

        endGame = 1 ;
    }
    if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){

        endGame = 1 ;
    }
    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){

        endGame = 1 ;
    }
    if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){

        endGame = 1 ;
    }
//victoire joueur 2
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
    {
        endGame = 2 ;
    }
    if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        endGame = 2 ;
    }
    if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        endGame = 2 ;
    }
    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'){
        endGame = 2 ;
    }
    if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'){
        endGame = 2 ;
    }
    if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'){
        endGame = 2 ;
    }
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
        endGame = 2 ;
    }
    if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O'){
        endGame = 2 ;
    }
    if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){

        endGame = 2 ;
    }
    if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){

        endGame = 2 ;
    }
    if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){

        endGame = 2 ;
    }
    if(freeSpaces == 0 && endGame == 0){
        endGame = 3 ;
    }

    return endGame ;
    
}
//affichage du score
void tableauScore(){
    printf("Nombre de manches à jouer : %d\n", manche);
    printf("\t\t\tLe tableau des scores \n");
    printf("\t\t\t     X         O    \n");
    printf("\t\t\t|---------|--------|\n");
    printf("\t\t\t|    %d    |   %d    |\n", scoreX , scoreY);
    printf("\t\t\t|---------|--------|\n");
}













//powered by wadestudiogame 