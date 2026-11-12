
# include <stdlib.h>
# include <stdio.h>
int compare(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int solution(int A[], int N){
//that, given an array A of N integers, returns the biggest value X which occurs in A exactly X times. 
//If there is no such value, the function should return 0.
    
    // the key Idea is that inorder to show up exactly X times in an array, 
    //the integer X needs to be smaller than N
    int *count = calloc(N + 1, sizeof(int));
    if (!count){
        return 0;
    }
    
    for (int i = 0; i<N; i++){
        if (A[i] <= N){
            count[A[i]]++; 
            // this is a tally. look closely it only increases by 1 each pass
            //this says go to the A[i]th position inside of count and increase the value by one everytime you see A[i]
            // its liek a frequency table
        }
    }
    
    int result = 0;
    for (int x = N; x >= 1; x--){
        if (count[x] == x){
            result = x;
        }
    }
    return result;
}
   



int main(void){
    int A[] = {1,1, 2, 2};
    // {0, 1, 2, 3, 4, 5, 6}
    // {2, 2, 3, 3, 3, 3, 8}
    int N = sizeof(A)/sizeof(A[0]);
    
    int sol = solution(A,N);
    
    printf("%d\n", sol);
    
    return 0;
}
