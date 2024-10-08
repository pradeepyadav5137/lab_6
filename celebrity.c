#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define N 4 // Define matrix size

// Function to find the celebrity using a stack
int findCelebrity(int M[N][N]) {
    int stack[N];
    int top = -1;
    int i;
    int candidate;
    // Step 1: Push all people to the stack
    for ( i = 0; i < N; i++) {
	stack[++top] = i;
    }

    // Step 2: Determine potential celebrity
    while (top > 0) {
	int A = stack[top--];
	int B = stack[top--];

	if (M[A][B] == 1) {
	    // A knows B, so A is not a celebrity; push B
	    stack[++top] = B;
	} else {
	    // A doesn't know B, so B is not a celebrity; push A
	    stack[++top] = A;
	}
    }

     candidate = stack[top];

    // Step 3: Verify candidate
    for ( i = 0; i < N; i++) {
	if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
	    return -1; // No celebrity found
	}
    }
    return candidate; // Candidate is the celebrity
}

int main() {
    int M[N][N] = {{0, 0, 1, 0},
		   {0, 1, 1, 0},
		   {0, 0, 1, 0},
		   {0, 0, 1, 0}};

    int result = findCelebrity(M);
    if (result == -1) {
	printf("There is no celebrity at the party.\n");
    } else {
	printf("The celebrity is person %d\n", result);
    }
    getch();
    // clrscr();
    return 0;
}
