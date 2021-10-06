#include <stdio.h>
#include <stdlib.h>
int A[100000];
int count =0;
int n;
void printMenu(){
   printf("0. Quit\n");
   printf("1. Generate Random Array\n");
   printf("2. Display the Array\n");
   printf("3. Sort in Ascending using Max-Heap\n");
   printf("4. Sort in Descending order\n");
   printf("5. Time Complexity to sort in Ascending from Random\n");
   printf("6. Time Complexity to sort in Ascending from already sorted in Ascending\n");
   printf("7. Time Complexity to sort in Ascending from sorted Descending\n");
   printf("8. Print Table for Time Complexity to sort in Ascending for n= 5000 to 50000, step =5000\n");
   printf("9. Extract largest element\n");
   printf("10. Replace a value at a given node with new value\n");
   printf("11. Insert a new element\n");
   printf("12. Delete an element\n");
}
void RANDOM(int A[],int n){
for(int i=0;i<n;i++)
    A[i]= rand();
}

void descSort(int A[],int n){
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(A[j]>A[i]){
            int temp = A[j];
            A[j]=A[i];
            A[i]=temp;
        }
    }
}
}

int PARENT(int i){
   if(i%2==0)
    return (i/2)-1;
   else
    return i/2;
}

int LEFT(int i){
   return (i*2)+1;
}

int RIGHT(int i){
   return (i*2)+2;
}

void MAX_HEAPIFY(int A[],int n,int i){
    count++;
int l = LEFT(i);
count++;
int r = RIGHT(i);
count++;
int largest = 0;
count++;
if(l<n && A[l]>A[i]){
        count++;
    largest = l;
}
else{
    count++;
    largest = i;
}
count++;
if(r<n && A[r]>A[largest]){
    count++;
    largest = r;
}
count++;
if(largest != i){
    count++;
    int temp = A[largest];
    count++;
    A[largest]=A[i];
    count++;
    A[i]=temp;
    count++;
    MAX_HEAPIFY(A,n,largest);
}
}

void heapSort(int A[],int n){
    count++;
    for(int i=n/2-1;i>=0;i--){
            count++;
            count++;
        MAX_HEAPIFY(A,n,i);
    }
    count++;
    for(int i=n-1;i>0;i--){
        count++;
        count++;
        int temp = A[0];
        count++;
        A[0]=A[i];
        count++;
        A[i]=temp;
        count++;
        MAX_HEAPIFY(A,i-1,0);
    }
}

void MAX_HEAP_CHANGE(int A[],int n,int i,int key){
       if(i<0 || i>n-1){
          printf("Please enter a valid index\n");
          return;
       }

       for(int j=n/2-1;j>=0;j--){
        MAX_HEAPIFY(A,n,j);
    }

       A[i]=key;
       while(1){
         if(A[i]>A[PARENT(i)] && i>0){
            int temp = A[PARENT(i)];
            A[PARENT(i)] = A[i];
            A[i] =temp;
            i = PARENT(i);
         }
         else if(A[LEFT(i)]>A[i] || A[RIGHT(i)]>A[i])
            MAX_HEAPIFY(A,n,i);

         else
            break;
       }
}

void MAX_HEAP_INSERT(int A[],int n,int key){
      n++;
      A[n-1] = key;
      int i = n-1;
      while(i>0 && A[PARENT(i)]<A[i]){
         int temp = A[PARENT(i)];
            A[PARENT(i)] = A[i];
            A[i] =temp;
            i = PARENT(i);
      }
}

int MAX_HEAP_DELETE(int A[],int n,int i){
     if(i<0 || i>n-1){
         printf("Enter a valid index.\n");
         return -1;
     }

      for(int j=n/2-1;j>=0;j--){
        MAX_HEAPIFY(A,n,j);
    }

    int x = A[i];
    A[i] = A[n-1];
    n--;
    MAX_HEAPIFY(A,n,i);
    return x;
}

void display(int A[],int n){
    printf("Array: \n");
for(int i=0;i<n;i++)
    printf("%d ",A[i]);

    printf("\n");
}
int main()
{
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    RANDOM(A,n);
    int i = -1;
    while(1){
        printMenu();
        printf("Enter your choice: ");
        scanf("%d",&i);
        switch(i){
        case 0:{
            printf("Program is close.\n");
            break;
        }

        case 1: {
            RANDOM(A,n);
            break;
        }

        case 2:{
            display(A,n);
            break;
        }

        case 3:{
            heapSort(A,n);
            break;
        }

        case 4:{
           descSort(A,n);
           break;
        }

        case 5:{
           RANDOM(A,n);
           count =0;
           heapSort(A,n);
           printf("TC for Random to Ascending: %d\n",count);
           count =0;
           break;
        }

        case 6:{
           heapSort(A,n);
           count =0;
           heapSort(A,n);
           printf("TC for Ascending to Ascending: %d\n",count);
           count =0;
           break;
        }

        case 7:{
           descSort(A,n);
           count =0;
           heapSort(A,n);
           printf("TC for Descending to Ascending: %d\n",count);
           count =0;
           break;
        }

        case 8:{
           printf("Input\t\tAscending\tDescending\tRandom\n");
           printf("------------------------------------------------------------\n");
           for(int i=5000;i<=50000;i+=5000){
                RANDOM(A,i);
           count =0;
           heapSort(A,i);
           int c3 = count;
           count =0;

           heapSort(A,i);
           count =0;
           heapSort(A,i);
           int c1 = count;
           count =0;

           descSort(A,i);
           count =0;
           heapSort(A,i);
           int c2 = count;
           count =0;

           printf("%d\t\t%d\t\t%d\t\t%d\n",i,c1,c2,c3);
           }
           printf("-------------------------------------------------------------\n");
           break;
        }

        case 9:{
           heapSort(A,n);
           printf("Largest value is %d\n",A[0]);
           break;
        }

        case 10:{
           int i,key;
           printf("Enter value and position where to replace: \n");
           scanf("%d%d",&key,&i);
           MAX_HEAP_CHANGE(A,n,i,key);
           break;
        }

        case 11:{
            int key;
           printf("Enter new value: \n");
           scanf("%d",&key);
           MAX_HEAP_INSERT(A,n,key);
           break;
        }

        case 12:{
           int i,x;
           printf("Enter the index from where element must be deleted:\n");
           scanf("%d",&i);
           x = MAX_HEAP_DELETE(A,n,i);
           printf("%d is deleted from the list.\n");
           break;
        }

        default: {
           printf("Enter a valid choice.\n");
           break;
        }

        }
        if(i==0)
            break;
    }
    return 0;
}