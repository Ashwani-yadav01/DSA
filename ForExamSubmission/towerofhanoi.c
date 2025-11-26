#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Step 1: Move n-1 disks from 'from' to 'aux'
    towerOfHanoi(n - 1, from, aux, to);

    // Step 2: Move the last disk
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Step 3: Move n-1 disks from 'aux' to 'to'
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}
