/* 下面是程序的一部分：
 * //pe12-8.c
 * #include <stdio.h>
 * int * make_array(int elem, int val);
 * void show_array(const int ar [], int n);
 * 
 * int main(void)
 * {
 *     int * pa;
 *     int size, value;
 *     
 *     printf("Enter the number of elements:");
 *     while(scanf("%d", &size) == 1 && size > 0)
 *     {
 *         printf("Enter the initialization value: ");
 *         scanf("%d", value);
 *         pa = make_array(size, value);
 *         if(pa)
 *         {
 *            show_array(pa, size);
 *            free(pa);
 *         }
 *         printf("Enter the number of elements (<1 to quit): ");
 *     }
 *     printf("Done!\n");
 *     return 0;
 * }
 * 提供make_array()和show_array()函数的定义，完成该程序。make_array()函数接
 * 受两个参数，第一个参数是int类型数组的元素个数，第二个参数是要赋给每个元素的
 * 值。该函数调用mallco()创建一个大小合适的数组，将其每个元素设置为指定值，并
 * 返回一个指向该数组的指针。show_array()函数显示数组的内容，一行显示8个数。
 */


#include <stdio.h>
#include <stdlib.h>

int * make_array(int elem, int val);
void show_array(const int ar [], int n);
  
int main(void)
{
    int * pa;
    int size, value;
      
    printf("Enter the number of elements:");
    while(scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if(pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    } 
    printf("Done!\n");
    return 0;
}

int * make_array(int elem, int val)
{
    int * pt;
    pt = (int *) malloc(elem * sizeof(int));
    for(int i = 0; i < elem; i++)
        pt[i] = val;
    return pt;
}

void show_array(const int ar[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%4d", ar[i]);
        if(i % 8 == 7)
            printf("\n");
    }
    printf("\n");
}