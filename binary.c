#include <stdio.h>

int main() {
    int n, a[10];
    printf("Enter number of elements (max 10):\n");
    scanf("%d", &n);

    printf("Enter elements in \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int ele, pos = -1;
    printf("Enter element to search:\n");
    scanf("%d", &ele);

    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ele == a[mid]) {
            pos = mid;
            break;
        } else if (ele < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (pos == -1) {
        printf("Element not present\n");
    } else {
        printf("Element found at position %d\n", pos);
    }

    return 0;
}
