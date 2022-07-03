#include <stdio.h>
#include <assert.h>
#include <misaligned.h>

enum MajorColor {WHITE,RED,BLACK,YELLOW,VIOLET};
enum MinorColor {BLUE,ORANGE,GREEN,BROWN,SLATE};
int GetPairNumberFromColor(MajorColor, MinorColor);
void TestPairtoNumber(MajorColor, MinorColor,int);
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int NumberofMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int NumberofMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap() {
    int MajorColorCnt,MinorColorCnt=0;
    ColorPair ColorPairRef;
    printf("\nReference Manual\n");
   
    for(MajorColorCnt = 0; MajorColorCnt < NumberofMajorColors; MajorColorCnt++) {
        for(MinorColorCnt = 0; MinorColorCnt < NumberofMinorColors; MinorColorCnt++) {
            ColorPairRef.majorColor = (MajorColor)MajorColorCnt;
            ColorPairRef.minorColor = (MinorColor)MinorColorCnt;
            int PairNumber =  GetPairNumberFromColor(&ColorPairRef);
            
            printf("%d | %s | %s\n", PairNumber, majorColor[MajorColorCnt], minorColor[MinorColorCnt]);
        }
    }
    return MajorColorCnt * MinorColorCnt;
}

int GetPairNumberFromColor(const ColorPair *colorPair)
{
    return colorPair->majorColor * NumberofMinorColors + colorPair->majorColor + 1;
}

void TestPairtoNumber(MajorColor Majorcolor, MinorColor Minorcolor,int ExpPairNumber)
{
    ColorPair colorpair;
    colorpair.majorColor = Majorcolor;
    colorpair.minorColor = Minorcolor;
    int PairNumber;
    PairNumber = GetPairNumberFromColor(Majorcolor,Minorcolor);
    assert(PairNumber == ExpPairNumber);
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    TestPairtoNumber(WHITE,BROWN,4);
    TestPairtoNumber(YELLOW,BROWN,16);
    printf("All is well (maybe!)\n");
    return 0;
}
