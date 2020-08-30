#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARSIZE  1000

int main(void)
{
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    for(i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    if((iofile = fopen(file, "wb")) == NULL)    //  尝试以二进制更新模式打开文件
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    //以二进制格式把数据写入文件
    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if((iofile = fopen(file,"rb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    //从文件中读取选定内容
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while(scanf("%d", &i) == 1 && i > 0 && i < ARSIZE - 1)
    {
        pos = (long) i * sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    
    fclose(iofile);
    puts("Bye!");
    
    return 0;
}