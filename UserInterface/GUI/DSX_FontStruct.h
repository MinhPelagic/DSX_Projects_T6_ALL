#ifndef _DSX_FONT_ASSIGN_H
#define _DSX_FONT_ASSIGN_H
/*Decalare the struct of fonts to be used in each Opcode*/
typedef struct FontSize {
    int Size_1;
    int Size_2;
    int Size_3;
    int Size_4;
    int Size_5;
    int Size_6;
    int Size_7;
    int Size_8;
    int Size_9;
    // int Size_10;
    // int Size_11;
} FontSize_ts;
/*Extern the variables in each Opcode*/
extern const FontSize_ts FontSize_General;
#endif