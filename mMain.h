// Project header fire for the mMain.c file & other of the Project files as required.
#include "mMenu.h"

char	SelectedText[MaxStringLength];
char	ValueText[MaxStringLength];
char	sxBlanks[MaxStringLength];
char	sLeadingCaps[MaxStringLength];
char	sCommand[MaxStringLength];
char	FileToOpen[MaxStringLength];
char	TextOut[MaxTextLength];
char	TextRecd[MaxTextLength];

typedef struct mItem
{	char * Text;
	int		Value;
	int		Action;
} MenuItem;
struct mItem	MainItems[MaxMainMenuITems];

#define MaxMainValueFunctions 20
typedef void (*pFunctionType)( char * );
pFunctionType pMainVF[MaxMainValueFunctions];
#define MaxMainActionFunctions 20
pFunctionType pMainAF[MaxMainActionFunctions];
