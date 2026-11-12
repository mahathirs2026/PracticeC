# include <stdlib.h>
# include <stdio.h>
int compare(const void *a, const void *b){
    return(*(int*)a - *(int*)b);
}

int solution(int A[], int N){
    qsort(A,N,sizeof(A[0]),compare);
    // case 1: gap at the front like {49,48,50,60} - we dont want 51, 
    //or if its the same 50,50,50 repeated
    // we want 1 in both cases
    if (A[0] > 1){
        return 1; // if teh first and therefore the smallest is 2 or bigger regardless of what is after the answer is 1
    }
    
    // case one doesnt account for if we have something like -3,1,50. answer should be int32
    int NegHasOne = 0;
    if (A[0] < 1){ // if the first value is less than 1 we need to check if there is a one elsewhere in the array
        for (int x = 0; x < N; x++){
            if (A[x] == 1){ // a simple flag to let us know if there is a one
                NegHasOne = 1;
            }
        }
        if (NegHasOne == 0){ // if the flag is not triggered and there is no 1, it means we can return 1
        return 1;
        }
    }
    
    
    
    // now consider a case 2 where there is a gap in the middle forexample {1, 1, 2, 3, 4, 6} there is a gap 5
    // I need a way of remembering what I saw to be able to compare it later
    int biggest = A[0];
    
    for (int i = 0; i<N; i++){
        
        if (A[i] > 1 && A[i] > biggest + 1 ){ // this asks if the ith term is more (biggest + 2) or more bigger than the previous term. 
            return (A[i - 1] + 1); // if there is a gap return 1 plus the previus term that is 2 smaller than the current term
        }
        
        biggest = A[i]; // keeps the pointer of biggest moving. its always one behind i
        // this works because we have sorted the list so the next term will be the same or bigger
    }
    
    // case 3: if the code is here that means there is no gap at front, the smallest number is bigger than 0 and there is no gap in the middle
    return (biggest + 1);
}

int main(void){
    int A[] = {-6,-7,-4, 3, 6, 4, 1, 2};
    int N = sizeof(A)/sizeof(A[0]);
    int sol = solution(A,N);
    
    printf("%d\n", sol);
    return 0;
}
