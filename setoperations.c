#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 25

int superset[MAX_SIZE], supersetsize=0;
int setA[MAX_SIZE], setAsize=0;
int setB[MAX_SIZE], setBsize=0;
int bitstringA[MAX_SIZE], bitstringB[MAX_SIZE];



void getuniversalset();
void getset(int arr[], int *size);
int checkifuniversal(int arr[], int size);
void bitstring();
void setunion();
void setintersection();
void diffA_B();
void diffB_A();
void printbitstring(int arr[], int size);
void printsetfrombitstring(int arr[], int size);



void getuniversalset() {
        printf("Enter size of the universal set (max %d): ", MAX_SIZE);
        scanf("%d", &supersetsize);
        if (supersetsize>MAX_SIZE) {
                printf("Size exceeds maximum\n");
                exit(1);
        }
        printf("Enter the elements for the universal Set:\n");
        for (int i=0;i<supersetsize;i++) {
                scanf("%d", &superset[i]);
        }
}

void getset(int arr[], int *size) {
        printf("Enter elements:\n");
        for (int i=0;i<*size;i++) {
                scanf("%d", &arr[i]);
        }
}




int checkifuniversal(int arr[], int size) {
        for (int i=0;i<size;i++) {
                int found=0;
                for (int j=0;j<supersetsize;j++){
                        if (arr[i]==superset[j]){
                                found=1;
                                break;
                        }
                }
                if (!found) {
                printf("Element is not found in universal Set.Try again.\n");
                return 0;
                }
        }
        return 1;
}
void bitstrings() {
        for (int i=0;i<supersetsize;i++) {
                bitstringA[i]=0;
                bitstringB[i]=0;
        }

        for (int i=0;i<setAsize;i++) {
                for (int j=0;j<supersetsize;j++) {
                        if (setA[i]==superset[j]) {
                                bitstringA[j] = 1;
                                break;
                        }
                }
        }

        for (int i=0;i<setBsize;i++) {
                for (int j=0;j<supersetsize;j++) {
                        if (setB[i]==superset[j]) {
                                bitstringB[j] = 1;
                                break;
                        }
                }
        }

        printf("Set A Bit String: ");
        printbitstring(bitstringA,supersetsize);
        printf("Set B Bit String: ");
        printbitstring(bitstringB,supersetsize);
}

void setunion() {
        int bitstringunion[MAX_SIZE];
        for (int i=0;i<supersetsize;i++) {
                bitstringunion[i] = bitstringA[i] | bitstringB[i];
        }
        printf("Union bit string: ");
        printbitstring(bitstringunion,supersetsize);
        printf("Union values: ");
        printsetfrombitstring(bitstringunion,supersetsize);
}




void setintersection() {
         int bitstringintersection[MAX_SIZE];
        for (int i=0;i<supersetsize;i++) {
                bitstringintersection[i] = bitstringA[i] & bitstringB[i];
        }
        printf("Intersection bit string: ");
        printbitstring(bitstringintersection,supersetsize);
        printf("Intersection  values: ");
        printsetfrombitstring(bitstringintersection,supersetsize);
}

void diffA_B() {
        int bitstringdifferenceAminusB[MAX_SIZE];
        for (int i=0;i<supersetsize;i++) {
                bitstringdifferenceAminusB[i] = bitstringA[i] & (1 - bitstringB[i]);
        }
        printf("Difference A - B: ");
        printbitstring(bitstringdifferenceAminusB,supersetsize);
        printf("Difference A - B values: ");
        printsetfrombitstring(bitstringdifferenceAminusB,supersetsize);
}



void diffB_A() {
    int bitstringdifferenceBminusA[MAX_SIZE];
    for (int i=0;i<supersetsize;i++) {
        bitstringdifferenceBminusA[i] = bitstringB[i] & (1 - bitstringA[i]);
    }
    printf("Difference B - A: ");
    printbitstring(bitstringdifferenceBminusA,supersetsize);
    printf("Difference B - A values): ");
    printsetfrombitstring(bitstringdifferenceBminusA,supersetsize);
}

void printbitstring(int arr[], int size) {
    printf("{");
    for (int i=0;i<size;i++) {
        printf("%d", arr[i]);
        if (i<size-1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void printsetfrombitstring(int arr[], int size) {
    int first = 1;
    printf("{");
    for (int i=0;i<size;i++) {
        if (arr[i]==1) {
            if (!first) {
                printf(", ");
            }
            printf("%d",superset[i]);
            first = 0;
        }
    }
    printf("}\n");
}
int main() {
    getuniversalset();

    do {
        printf("Enter Set A Size (maximum %d): ",supersetsize);
        scanf("%d", &setAsize);
        if (setAsize>supersetsize) {
            printf("Set A size is more than universal Set size.\n");
        }
    } while (setAsize>supersetsize);

    do {
        getset(setA, &setAsize);
    } while (checkifuniversal(setA, setAsize) == 0);

    do {
        printf("Enter Set B Size (maximum %d): ", supersetsize);
        scanf("%d", &setBsize);
        if (setBsize >supersetsize) {
            printf("Set B size is more than universal Set size.\n");
        }
    } while (setBsize>supersetsize);

    do {
        getset(setB, &setBsize);
    } while (checkifuniversal(setB, setBsize) == 0);

    bitstrings();
    setunion();
    setintersection();
    diffA_B();
    diffB_A();

    return 0;
}
