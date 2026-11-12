
# include <stdlib.h>
# include <stdio.h>
int compare(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int solution(int A[], int N){
//You’re given an array A of N integers. You may change up to three of its elements, each to any integer value you like. 
//Your goal is to make the difference between the largest and smallest values in the array (its “amplitude”) as small as possible.

    // the idea here is to look at the N-3 values and add the average of them 3 times while eliminating 
    //{-6, -3, -1, 0, 11} after 3 chnages we can make this arrays amplitude 1.
    //{0,20,30,49,50} not always the middle values, here keeping 50 and 49 allows us to achieve amplitude 1
    qsort(A,N,sizeof(A[0]),compare);
    
    // keep the N-3 so the middle numbers
    //int *bad = calloc(3, sizeof(int));
    
    if (N <= 3){
        return 0;
    }
    
    int head = N - 1;
    int tail = 0;
    int headcount = 0;
    
    for (int i = 1; i <= 3 ; i++){
        if (abs(A[tail + 1] - A[tail]) < abs(A[head] - A[head - 1]) ){
            //bad [i - 1] = A[head];
            head = head - 1;
            headcount += 1;
        }
        else{
            //bad [i - 1] = A[tail];
            tail = tail + 1;
            
        }
    }
    
    if (headcount == 0){
        A[0] = A[N - 1 - headcount];
        A[1] = A[N - 1 - headcount];
        A[2] = A[N - 1 - headcount];
        return (A[N - 1 - headcount] - A[3]);
    }
    
    if (headcount == 1){
        A[0] = A[N - 1 - headcount];
        A[1] = A[N - 1 - headcount];
        A[N - 1] = A[N - 1 - headcount];
        return (A[N - 1 - headcount] - A[2]);
    }
    
    if (headcount == 2){
        A[0] = A[N - 1 - headcount];
        A[N - 2] = A[N - 1 - headcount];
        A[N - 1] = A[N - 1 - headcount];
        return (A[N - 1 - headcount] - A[1]);
    }
    
    if (headcount == 3){
        A[N - 3] = A[N - 1 - headcount];
        A[N - 2] = A[N - 1 - headcount];
        A[N - 1] = A[N - 1 - headcount];
        return (A[N - 1 - headcount] - A[0]);
    }
    
    
    
    
}
   



int main(void){
    int A[] = {0,20,30,49,50};
    // {0, 1, 2, 3, 4, 5, 6}
    // {-6, -3, -1, 0, 11}
    int N = sizeof(A)/sizeof(A[0]);
    
    int sol = solution(A,N);
    
    printf("%d\n", sol);
    
    return 0;
}
