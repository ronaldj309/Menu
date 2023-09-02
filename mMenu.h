//  Menu project overall header file mMenu.h
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MaxMenuItems 40
#define MaxMainMenuITems 30
#define PathToAutoIt "C:/Users/ronal/Documents/SpeachToText/AutoIt/autoit-v3/install/"
#define MaxTextLength 260
#define MaxStringLength 256

extern char	SelectedText[MaxStringLength];
extern char	ValueText[MaxStringLength];
extern char	sxBlanks[MaxStringLength];
extern char	sLeadingCaps[MaxStringLength];
extern char	sCommand[MaxStringLength];
extern char	FileToOpen[MaxStringLength];
extern char	TextOut[MaxTextLength];
extern char	TextRecd[MaxTextLength];

extern void PutString( char *s );
extern void GetString( char *s );
extern void SelectedString( char *s );
extern void TextReceived( char *s );
extern void NoBlanks( char *s );
extern void SansBlanks( char *s );
extern void LeadingCaps( char *s );
extern void LeadingCapsSelect( char *s );
extern void OpenNotePad( char *s);
extern void AutoOpenNotePad( char *s );
extern void DoNone( char *s );
// >:)
