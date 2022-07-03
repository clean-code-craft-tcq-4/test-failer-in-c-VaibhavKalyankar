typedef enum
{
  WHITE,
  RED,
  BLACK,
  YELLOW,
  VIOLET
}MajorColor;

typedef enum
{
  BLUE,
  ORANGE,
  GREEN,
  BROWN,
  SLATE
}MinorColor;

typedef struct
{
  MajorColor majorColor;
  MinorColor minorColor;
}ColorPair;

#define MAX_COLORPAIR 16

  
