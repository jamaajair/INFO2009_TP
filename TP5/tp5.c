/**
 * TP5 solutions 
 * @author Jamaa Jair
 */

#include <stdio.h>
#include <stdlib.h> 

/**
 * Question 1
 */
double moy(double T[], int N){
    double somme = 0;
    for (int i = 0; i < N; i++)
        somme += T[i];
    return N > 0 ? somme/N : 0;
}

/**
 * Question 2
 * Affiche Triangle de Pascal
 */
void C(int n){
    long **C = malloc((n+1)* sizeof(long*));
    if(!C){
        printf("Erreur malloc\n");
        return;
    }

    for (int i = 0; i <= n; i++){
        C[i] = malloc(sizeof(long)*(n+1));
        if(!C[i]){
            for(int j=0;j<i;j++) free(C[j]);
            free(C);
            printf("Erreur malloc\n");
            return;
        }
    }

    printf("\nTriangle de Pascal (n=%d) :\n", n);
    for(int i=0;i<=n;i++){
        C[i][0] = C[i][i] = 1;

        for(int j=1;j<i;j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];

        for(int j=0;j<=i;j++)
            printf("%ld ", C[i][j]);
        printf("\n");
    }

    for(int i = 0; i <= n; i++)
        free(C[i]);
    free(C);
}

/**
 * Question 3
 */
unsigned max_seq(int t[],unsigned n){
    if(n==0) return 0;

    unsigned max_sequence = 1;
    unsigned current_sequence = 1;

    for(unsigned i=1;i<n;i++){
        if(t[i-1] == t[i]-1){
            current_sequence++;
            if(current_sequence > max_sequence)
                max_sequence = current_sequence;
        } else {
            current_sequence = 1;
        }
    }

    return max_sequence;
}

/**
 * Question 4
 */
int first_diff_index(char* s1, char* s2){
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] != s2[i])
            return i;
        i++;
    }

    if(s1[i] != s2[i])
        return i;

    // ici on retourne -1 parce je ne veux pas retourner une valeur positif prsq
    // si je retourne 0 il y a moyen qu il sera confondu avec 'premier diff est l indice 0 !'
    return -1;
}

/**
 * Question 6
 */
unsigned length(const char *s){
    unsigned i = 0;
    while(s[i] != '\0') i++;
    return i;
}

unsigned largest_common_suffix(const char* s1, const char* s2){
    unsigned len1 = length(s1);
    unsigned len2 = length(s2);
    
    unsigned max_suffix = (len1 < len2 ? len1 : len2);

    for(unsigned i = 1; i <= max_suffix; i++){
        if(s1[len1 - i] != s2[len2 - i])
            return i - 1;
    }
    return max_suffix;
}

/**
 * Question 7
 */
int are_equal_ignore_spaces(char* s1, char* s2){
    while(*s1 || *s2){

        while(*s1 == ' ') s1++;
        while(*s2 == ' ') s2++;

        if(*s1 != *s2)
            return 0;

        if(*s1 == '\0' || *s2 == '\0')
            break;

        s1++; s2++;
    }
    return 1;
}

/**
 * Question 8
 */
int Comparer2tableaux(int A[], int T[], int n){
    for(int i=0;i<n;i++)
        if(A[i] != T[i])
            return 0;
    return 1;
}

/**
 * Question 9
 */
int Prefixe(int A[], int T[], int n){
    int i=0;
    while(i<n && A[i] == T[i]) i++;
    return i;
}

/**
 * Question 5
 */
int palindrome(char *s, int size){
    for(int i=0;i<size/2;i++){
        if(s[i] != s[size-1-i])
            return 0;
    }
    return 1;
}

/**
 * MAIN — tests de toutes les fonctions
 * Pourtant, vous pouvez ajouter autant de tests que vous voulez, 
 * également vous pouvez commenter les tests d'autres fonctions si vous tester 
 * une fonction spécifique pour la lisibilité et la facilite
 */
int main(){

    printf("\n===== TEST 1 — moy =====\n");
    double X[] = {2,4,6,8};
    printf("moyenne = %.2f\n", moy(X, 4));

    printf("\n===== TEST 2 — Triangle de Pascal =====\n");
    C(5);

    printf("\n===== TEST 3 — max_seq =====\n");
    int M1[] = {1,2,3,10,11,12,13};
    printf("max_seq = %u\n", max_seq(M1, 7));

    printf("\n===== TEST 4 — first_diff_index =====\n");
    printf("diff entre 'abc' et 'abd' = %d\n", first_diff_index("abc","abd"));
    printf("diff entre 'abc' et 'abc' = %d\n", first_diff_index("abc","abc")); // ici prq il va rtrn -1 prcq il y a pas d indice de diff
                                                                               // entre les deux mots, ils sont les meme, donc il va rtrner -1
                                                                               // donc pour nous une fois qu on voit que l appelle à la 
                                                                               // fonction retourne -1 donc les deux mots sont les memes

    printf("\n===== TEST 5 — palindrome =====\n");
    char P[] = "abcba";
    printf("abcba est palindrome ? %d\n", palindrome(P, 5));

    printf("\n===== TEST 6 — largest_common_suffix =====\n");
    printf("suffix('manger','danger') = %u\n", largest_common_suffix("manger","danger"));

    printf("\n===== TEST 7 — are_equal_ignore_spaces =====\n");
    printf(" 'a b c' == 'abc' ? %d\n", are_equal_ignore_spaces("a b c","abc"));

    printf("\n===== TEST 8 — Comparer2tableaux =====\n");
    int A[] = {1,2,3};
    int B[] = {1,2,3};
    printf("Compare = %d\n", Comparer2tableaux(A,B,3));

    printf("\n===== TEST 9 — Prefixe =====\n");
    int T1[] = {1,6,9,7,5,6};
    int T2[] = {1,6,9,0,5,6};
    printf("prefixe = %d\n", Prefixe(T1,T2,6));

    return 0;
}
