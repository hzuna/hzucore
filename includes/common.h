#ifndef __COMMON_H__
#define __COMMON_H__

#include <includes/types.h>

void printk(const char *str){
    uint16_t *VideoMem = (uint16_t*)0xb8000;    //80*25 video memory
    static uint8_t x=0, y=0;
    for(int i=0; str[i]; i++){
        if(str[i]=='\n'||str[i]=='\r'){
            x=0;
            y++;
        }
        VideoMem[80*y+x] = (VideoMem[80*y+x] & 0xff00) | str[i];
        x++;
        if(x>80){
            x=0;
            y++;
        }
        if(y>25){
            clear_screen();
            x=y=0;
        }
    }
}

void clear_screen()
{
    uint16_t *VideoMem = (uint16_t*)0xb8000;

    for (int i = 0; i < 80 * 25; i++) {
          VideoMem[i] = (VideoMem[i] & 0xff00) | ' ';
    }
}

#endif //__COMMON_H__