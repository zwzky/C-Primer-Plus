/* fields.c -- 定义并使用字段 */

#include <stdio.h>
#include <stdbool.h>

/* 线的样式 */
#define SOLID   0
#define DOTTED  1
#define DASHED  2

/* 三原色 */
#define RED     1
#define GREEN   2
#define BLUE    4

/* 混合色 */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box_props {
    bool opaque   : 1;
    unsigned int fill_color : 3;
    unsigned int  : 4;
    bool show_boder   : 1;
    unsigned int boder_color  : 3;
    unsigned int boder_style  : 2;
    unsigned int  : 2;
};

void show_setting(const struct box_props *pb);

int main(void)
{
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};

    printf("Original box setting:\n");
    show_setting(&box);

    box.opaque = false;
    box.fill_color = WHITE;
    box.boder_color = MAGENTA;
    box.boder_style = SOLID;
    printf("\nModified box settings:\n");
    show_setting(&box);
    
    return 0;
}

void show_setting(const struct box_props *pb)
{
    printf("Box is %s\n", pb->opaque ? "opaque" : "transparent");
    printf("The fill color is %s\n", colors[pb->fill_color]);
    printf("Boder is %s\n", pb->boder_style == true ? "shown" : "not shown");
    printf("The boder style is ");
    switch (pb->boder_style)
    {
        case SOLID : printf("solid.\n"); break;
        case DOTTED: printf("dotted.\n"); break;
        case DASHED: printf("dashed\n"); break;
        default : printf("unkonwn type.\n");
    }
}
