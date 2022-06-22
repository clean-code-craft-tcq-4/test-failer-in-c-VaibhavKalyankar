#include <stdio.h>
#include <assert.h>
enum MajorColor {WHITE,RED,BLACK,YELLOW,VIOLET};
enum MinorColor {BLUE,ORANGE,GREEN,BROWN,SLATE};
int GetPairNumberFromColor(MajorColor, MinorColor);
void TestPairtoNumber(MajorColor, MinorColor,int);
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

int GetPairNumberFromColor(MajorColor Majorcolor, MinorColor Minorcolor)
{
    return Majorcolor * 5 + Minorcolor + 1;
}

void TestPairtoNumber(MajorColor Majorcolor, MinorColor Minorcolor,int ExpPairNumber)
{
    int PairNumber;
    PairNumber = GetPairNumberFromColor(Majorcolor,Minorcolor);
    assert(PairNumber == ExpPairNumber);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    TestPairtoNumber(WHITE,BROWN,4);
    printf("All is well (maybe!)\n");
    return 0;
}
