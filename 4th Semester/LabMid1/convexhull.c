#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    int x, y;
};

struct Point p0;

struct Point secondTop(struct Point stack[], int *top)
{
    return stack[*top - 1];
}

int squaredDist(struct Point p1, struct Point p2)
{
    return ((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int direction(struct Point a, struct Point b, struct Point c)
{
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0)
        return 0;
    else if (val < 0)
        return 2;
    return 1;
}

int compare(const void *vp1, const void *vp2)
{
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;

    int dir = direction(p0, *p1, *p2);
    if (dir == 0)
        return (squaredDist(p0, *p2) >= squaredDist(p0, *p1)) ? -1 : 1;
    return (dir == 2) ? -1 : 1;
}

void swap(struct Point *a, struct Point *b)
{
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

void findConvexHull(struct Point points[], int n)
{
    int minY = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < minY) || (minY == y && points[i].x < points[min].x))
        {
            minY = points[i].y;
            min = i;
        }
    }

    swap(&points[0], &points[min]);

    p0 = points[0];

    qsort(&points[1], n - 1, sizeof(struct Point), compare);

    struct Point stack[n];
    int top = -1;

    stack[++top] = points[0];
    stack[++top] = points[1];
    stack[++top] = points[2];

    for (int i = 3; i < n; i++)
    {
        while (top >= 1 && direction(secondTop(stack, &top), stack[top], points[i]) != 2)
            top--;
        stack[++top] = points[i];
    }

    printf("Boundary points of convex hull are:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d) ", stack[i].x, stack[i].y);
}

int main()
{
    struct Point points[] = {
        {-7, 8}, {-4, 6}, {2, 6}, {6, 4}, {8, 6}, {7, -2}, {4, -6}, {8, -7}, {0, 0}, {3, -2}, {6, -10}, {0, -6}, {-9, -5}, {-8, -2}, {-8, 0}, {-10, 3}, {-2, 2}, {-10, 4}};
    int n = 18;
    findConvexHull(points, n);
    return 0;
}
