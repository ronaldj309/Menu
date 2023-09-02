#include "mMenu.h"

void PutString( char *s )
{
	while( *s != '\0') { putch( *s ); s++; }
	// putch( '\n' );
}

void GetString( char *s )
{	int iIn, nIn = 0;
	char * sSave = s;
 
	system( "cls");
	PutString( "Enter new selected text\n");
	while ( (nIn < MaxStringLength) && (iIn = getch() ) != (int)'\r' )
	{ *s = (char)iIn; putch(iIn); s++; nIn++; }
	*s = '\0';
	strcpy( TextRecd, sSave );
	LeadingCaps( sSave );
	SansBlanks( sLeadingCaps );
}

void SelectedString( char *s ) { strcpy( s, SelectedText);	}
void TextReceived( char *s ) { strcpy( s, TextRecd ); }
void LeadingCapsSelect( char *s ) { strcpy( s, sLeadingCaps );}
void NoBlanks( char *s ) { strcpy( s, sxBlanks ); }

void SansBlanks( char *s )
{	int	i = 0, d = 0;

	while (*(s + i) != '\0' )
	{	if ( (*(s + i) == ' ' ) ) i++;
		else {	sxBlanks[d] = *(s + i); d++; i++;	}
	 }
	 sxBlanks[d] = '\0';
}

void LeadingCaps( char *s )
{	int	i = 0, d = 0;

	while (*(s + i) != '\0' )
	{	if ( (*(s + i) == ' ') && isascii(*(s + i + 1) ))
		{	sLeadingCaps[d++] = ' '; sLeadingCaps[d] = (char)toupper( (int)(*(s + i++ + 1)) ); }
		else sLeadingCaps[d] = *(s + i);
		i++; d++;
	 }
	 sLeadingCaps[d] = '\0';
}

void OpenNotePad( char *s)
{	strcpy( sCommand, "notepad.exe " ); strcat( sCommand, s);
	system( sCommand );
}

void AutoOpenNotePad( char *s )
{	strcpy( sCommand, PathToAutoIt ); strcat( sCommand, "AutoIt3.exe " );
	strcat( sCommand, PathToAutoIt );
	strcat( sCommand, "examples/notepad1.au3" );
	system( sCommand );
}

void DoNone( char *s ) { strcpy( s, " " ); }
