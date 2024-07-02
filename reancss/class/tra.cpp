   
// #include <stdio.h>
// #include <conio.h>
// #include <string.h>

// int n = 0, i, b;
// char id[100][5], title[100][20], op;
// char x[20];
// int qty[100];

// int main() {
//     do {

// 	printf("1/ Input Book information :\n");
// 	printf("2/ Output and Sort Book information by title\n");
// 	printf("3/ Search information by title \n");
// 	printf("4/ Delete Book information by ID\n");
// 	printf("5/ Exit the Program \n");
// 		printf("Enter Option: "); scanf(" %c", &op);
// 	switch (op) {
// 	    case '1':
// 		printf("Enter Book Id: ");
// 		scanf("%s", id[n]);
// 		printf("Enter Your Title: ");
// 		scanf("%s", title[n]);
// 		printf("Enter Your Qty: ");
// 		scanf("%d", &qty[n]);
// 		n = n + 1;
// 		break;
// 	    case '2':
// 		for (i = 0; i < n; i++) {
// 		    for (int j = i + 1; j < n; j++) {
// 			if (strcmp(title[i],title[j]) > 0) {

// 			    strcpy(x,title[i]);
// 			    strcpy(title[i],title[j]);
// 			    strcpy(title[j],x);

// 			    strcpy(x,id[i]);
// 			    strcpy(id[i],id[j]);
// 			    strcpy(id[j],x);

// 			    b = qty[i]; qty[i] = qty[j]; qty[j] = b;
// 			}
// 		    }
// 		}
// 		printf("%10s%20s%10s\n", "B_ID", "Title", "Qty");
// 		for (i = 0; i < n; i++) {
// 		    printf("%10s%20s%10d\n", id[i], title[i], qty[i]);
// 		}
// 		getch();
// 		break;
// 	    case '3':
// 			printf("Enter Book Title to Search: "); scanf("%s", x);
// 		b = 0;
// 			printf("%10s%20s%10s\n", "B_ID", "Title", "Qty");
// 		for (i = 0; i < n; i++) {
// 		    if (strcmp(title[i], x) == 0) {
// 			b = 1;
// 			printf("%10s%20s%10d\n", id[i], title[i], qty[i]);
// 		    }
// 		}
// 		if (b == 0) {
// 		    printf("Book Title Not Found\n");
// 		}
// 		getch();
// 		break;
// 	    case '4':
// 			printf("\tBefore Delete\n");
// 			printf("%10s%20s%10s\n", "B_ID", "Title", "Qty");
// 		for (i = 0; i < n; i++) {
// 		    printf("%10s%20s%10d\n",id[i],title[i],qty[i]);
// 		}
// 			printf("Enter ID to delete: ");	scanf("%s", x);
// 		b = 0;
// 		for (i = 0; i < n; i++) {
// 		    if (strcmp(id[i], x) == 0) {
// 			b = 1;
// 			for (int j = i; j < n - 1; j++) {
// 			    strcpy(id[j],id[j + 1]);
// 			    strcpy(title[j],title[j + 1]);
// 			    qty[j] =qty[j + 1];
// 			}
// 			n--;
// 			break;
// 		    }
// 		}
// 		if (b == 0) {
// 		    printf("\tDelete not complete\n");
// 		} else {
// 		    printf("\tDelete complete\n");
// 		}
// 		printf("\tAfter Delete\n");
// 		printf("%10s%20s%10s\n", "B_ID", "Title", "Qty");
// 		for (i = 0; i < n; i++) {
// 		    printf("%10s%20s%10d\n", id[i], title[i], qty[i]);
// 		}
// 		getch();
// 		break;
// 	}
//     } while (op != '5');
	
//     getch();
//    }

    
    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int n = 0, i, b;
char id[100][5], title[100][20], op;
char x[20];
int qty[100];
char name[100][20];

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void inputBookInformation() {
    clearScreen();
    printf("Enter Book Id: ");
    scanf("%s", id[n]);
    printf("Enter Book Title: ");
    scanf("%s", title[n]);
    printf("Enter Book Quantity: ");
    scanf("%d", &qty[n]);
    printf("Enter name : ");
    scanf("%s",name[n]);
    n=n+1;
}

void outputAndSortBooksByTitle() {
    clearScreen();
    for (i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(title[i], title[j]) > 0) {
                // Swap titles
                strcpy(x, title[i]);
                strcpy(title[i], title[j]);
                strcpy(title[j], x);
                // Swap IDs
                strcpy(x, id[i]);
                strcpy(id[i], id[j]);
                strcpy(id[j], x);
                // Swap quantities
                b = qty[i]; qty[i] = qty[j]; qty[j] = b;
                // swap name
                strcpy(x,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],x);
            }
        }
    }
    printf("%10s%20s%10s%20s\n", "B_ID", "Title", "Qty","Name");
    for (i = 0; i < n; i++) {
        printf("%10s%20s%10d%20s\n", id[i], title[i], qty[i],name[i]);
    }
    getch();
}

void searchBookByTitle() {
    clearScreen();
    printf("Enter Book Title to Search: ");
    scanf("%s", x);
    b = 0;
    printf("%10s%20s%10s%20s\n", "B_ID","Title", "Qty","Name");
    for (i = 0; i < n; i++) {
        if (strcmp(title[i], x) == 0) {
            b = 1;
            printf("%10s%20s%10d%20s\n", id[i], title[i], qty[i],name[i]);
        }
    }
    if (b == 0) {
        printf("Book Title Not Found\n");
    }
    getch();
}

void deleteBookById() {
    clearScreen();
    printf("\tBefore Delete\n");
    printf("%10s%20s%10s%20s\n", "B_ID", "Title", "Qty","Name");
    for (i = 0; i < n; i++) {
        printf("%10s%20s%10d%20s\n", id[i], title[i], qty[i],name[i]);
    }
    printf("Enter ID to delete: ");
    scanf("%s", x);
    b = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(id[i], x) == 0) {
            b = 1;
            for (int j = i; j < n - 1; j++) {
                strcpy(id[j], id[j + 1]);
                strcpy(title[j], title[j + 1]);
                qty[j] = qty[j + 1];
                strcpy(name[j],name[j + 1]);
            }
            n=n-1;
            break;
        }
    }
    if (b == 0) {
        printf("\tDelete not complete\n");
    } else {
        printf("\tDelete complete\n");
    }
    printf("\tAfter Delete\n");
    printf("%10s%20s%10s%20s\n", "B_ID", "Title", "Qty","Name");
    for (i = 0; i < n; i++) {
        printf("%10s%20s%10d%20s\n", id[i], title[i], qty[i],name[i]);
    }
    getch();
}

int main() {
    do {
        clearScreen();
        printf("1/ Input Book information :\n");
        printf("2/ Output and Sort Book information by title\n");
        printf("3/ Search information by title\n");
        printf("4/ Delete Book information by ID\n");
        printf("5/ Exit the Program\n");
        printf("Enter Option: ");
        scanf(" %c", &op);

        switch (op) {
            case '1':
                inputBookInformation();
                break;
            case '2':
                outputAndSortBooksByTitle();
                break;
            case '3':
                searchBookByTitle();
                break;
            case '4':
                deleteBookById();
                break;
        }
    } while (op != '5');

    return 0;
}
