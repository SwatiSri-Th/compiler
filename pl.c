#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


/* Function for Playfair Cipher encryption  */
void Playfair(char str[], char keystr[]) {
    char keyMat[5][5];
    // Key & plainText
    char ks = strlen(keystr);
    char ps = strlen(str);
    void toUpperCase(char encrypt[], int ps) {
        int i;
		for (i= 0; i < ps; i++) {
            if (encrypt[i] > 96 && encrypt[i] < 123)
                encrypt[i] -= 32;
        }
    }
    int removeSpaces(char* plain, int ps) {
        int i, count = 0;
        for (i = 0; i < ps; i++)
            if (plain[i] != ' ')
                plain[count++] = plain[i];
        plain[count] = '\0';
        return count;
    }
    /* this function will create a 5 by 5 matrix. */
    void createMatrix(char keystr[], int ks, char keyMat[5][5]) {
        int flag = 0, *dict;
        /* here we are creating a hashmap for alphabets */
        dict = (int*)calloc(26, sizeof(int));
        int i, j, k;
        for (i = 0; i < ks; i++) {
            if (keystr[i] != 'j')
                dict[keystr[i] - 97] = 2;
        }
        dict['j' - 97] = 1;
        i = 0, j = 0;
        for (k = 0; k < ks; k++) {
            if (dict[keystr[k] - 97] == 2) {
                dict[keystr[k] - 97] -= 1;
                keyMat[i][j] = keystr[k];
                j++;
                if (j == 5) {
                    i++;
                    j = 0;
                }
            }
        }
        for (k = 0; k < 26; k++) {
            if (dict[k] == 0) {
                keyMat[i][j] = (char)(k + 97);
                j++;
                if (j == 5) {
                    i++;
                    j = 0;
                }
            }
        }
    }
    /*this function looks for a digraph's characters in the key matrix and returns their positions.*/
    void search(char keyMat[5][5], char a, char b, int arr[]) {
        int i,j;
		if (a == 'j')
            a = 'i';
        else if (b == 'j')
            b = 'i';
        for(i = 0; i < 5; i++) {
            for( j = 0; j < 5; j++) {
                if (keyMat[i][j] == a) {
                    arr[0] = i;
                    arr[1] = j;
                }
                else if (keyMat[i][j] == b) {
                    arr[2] = i;
                    arr[3] = j;
                }
            }
        }
    }
    /* This function avoids duplication and levels out the length of plain text by making it even.*/
    int prep(char str[], int p) {
        int i, j, sub = p;
        for ( i = 0; i < sub; i += 2) {
            if(str[i]==str[i+1]){
                for(j=sub; j>i+1; j--){
                   str[j]=str[j-1];
                }
                str[i+1]='x';
                sub+=1;
            }
        }
        str[sub]='\0';
        if (sub % 2 != 0) {
            str[sub++] = 'z';
            str[sub] = '\0';
        }
        return sub;
    }
    // Here, the encryption is done.
    void encrypt(char str[], char keyMat[5][5], int pos) {
        int i, a[4];
        for( i=0; i<pos; i+=2){
            search(keyMat, str[i], str[i + 1], a);
            if (a[0] == a[2]) {
                str[i] = keyMat[a[0]][(a[1] + 1)%5];
                str[i + 1] = keyMat[a[0]][(a[3] + 1)%5];
            }
            else if (a[1] == a[3]) {
                str[i] = keyMat[(a[0] + 1)%5][a[1]];
                str[i + 1] = keyMat[(a[2] + 1)%5][a[1]];
            }
            else {
                str[i] = keyMat[a[0]][a[3]];
                str[i + 1] = keyMat[a[2]][a[1]];
            }
        }
    }
    ks = removeSpaces(keystr, ks);
    ps = removeSpaces(str, ps);
    ps = prep(str, ps);
    createMatrix(keystr, ks, keyMat);
    encrypt(str, keyMat, ps);
    toUpperCase(str, ps);
    /* str is the final encrypted string in uppercase */
    printf("Cipher text: %s\n", str);
}


int main() {
    char string[200], keyString[200];
    printf("Enter key: ");
    scanf("%[^\n]s", &keyString);
    printf("Enter plaintext: ");
    scanf("\n");
    scanf("%[^\n]s", &string);
    
    //Playfair Cipher Program in C functional call
    Playfair(string, keyString);
    return 0;
}
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
long int p,q,n,t,flag,e[100],d[100],temp[100],j,m[100],en[100],i; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
void encrypt(); 
void decrypt(); 
int main() 
{ 
    printf("\nENTER FIRST PRIME NUMBER\n"); 
    scanf("%ld",&p); 
    flag=prime(p); 
    if(flag==0) 
    { 
        printf("\nWRONG INPUT\n"); 
        exit(1); 
    } 
    printf("\nENTER ANOTHER PRIME NUMBER\n"); 
    scanf("%ld",&q); 
    flag=prime(q); 
    if(flag==0||p==q) 
    { 
        printf("\nWRONG INPUT\n"); 
        exit(1); 
    } 
    printf("\nENTER MESSAGE\n"); 
    fflush(stdin); 
    scanf("%s",msg); 
    for(i=0;msg[i]!=NULL;i++) 
        m[i]=msg[i]; 
    n=p*q; 
    t=(p-1)*(q-1); 
    ce(); 
    printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
    for(i=0;i<j-1;i++) 
        printf("\n%ld\t%ld",e[i],d[i]); 
    encrypt(); 
    decrypt(); 
    return 0; 
}
 
int prime(long int pr) 
{ 
    int i; 
    j=sqrt(pr); 
    for(i=2;i<=j;i++) 
    { 
        if(pr%i==0) 
            return 0; 
    } 
    return 1; 
}
 
void ce() 
{ 
    int k; 
    k=0; 
    for(i=2;i<t;i++) 
        {
            if(t%i==0)
                continue;
                flag=prime(i);
            if(flag==1&&i!=p&&i!=q)
            {
                e[k]=i; flag=cd(e[k]);
                if(flag>0) 
        { 
            d[k]=flag; 
            k++; 
        } 
        if(k==99) 
            break; 
        } 
    } 
}
 
long int cd(long int x) 
{ 
    long int k=1; 
    while(1) 
    { 
        k=k+t; 
        if(k%x==0) 
            return(k/x); 
    } 
} 
void encrypt() 
{ 
    long int pt,ct,key=e[0],k,len; 
    i=0; 
    len=strlen(msg); 
    while(i!=len) 
    { 
        pt=m[i]; 
        pt=pt-96; 
        k=1; 
        for(j=0;j<key;j++) 
        { 
            k=k*pt; 
            k=k%n; 
        } 
        temp[i]=k; 
        ct=k+96; 
        en[i]=ct; 
        i++; 
    } 
    en[i]=-1; 
    printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
    for(i=0;en[i]!=-1;i++) 
        printf("%c",en[i]); 
} 
void decrypt() 
{ 
    long int pt,ct,key=d[0],k; 
    i=0; 
    while(en[i]!=-1) 
    { 
        ct=temp[i]; 
        k=1; 
        for(j=0;j<key;j++) 
        { 
            k=k*ct; 
            k=k%n; 
        } 
        pt=k+96; 
        m[i]=pt; 
        i++; 
    } 
    m[i]=-1; 
    printf("\nTHE DECRYPTED MESSAGE IS\n"); 
    for(i=0;m[i]!=-1;i++) 
        printf("%c",m[i]); 
}

