#include "mMenu.h"
#include "mMain.h"

int main( int nArgs, char *Args[] )
{	int		iIn, iMenu = 0, nMenuItems;
	enum { eNone=0, ePutString, eGetString, eOldText, eTextRecd, eSelectedText, eLeadCap, eNoBlanks, eNotePad, eAutoNotePad } eMain;
	MainItems[iMenu++] = (MenuItem){  "Selected Text", eSelectedText, eNone };
	MainItems[iMenu++] = (MenuItem){  "Get text", eTextRecd, eGetString };
	MainItems[iMenu++] = (MenuItem){  "Old text", eTextRecd, eOldText };
	MainItems[iMenu++] = (MenuItem){  "No blanks", eNoBlanks, eNoBlanks };
	MainItems[iMenu++] = (MenuItem){  "Leading caps", eLeadCap, eLeadCap };
	MainItems[iMenu++] = (MenuItem){  "Open Notepad", eSelectedText, eNotePad };
	MainItems[iMenu++] = (MenuItem){  "AutoIt Open NotePad", eSelectedText, eAutoNotePad };
	nMenuItems = iMenu;
	pMainVF[eSelectedText] = SelectedString;
	pMainVF[eTextRecd] = TextReceived;
	pMainVF[eLeadCap] = LeadingCapsSelect;
	pMainVF[eAutoNotePad] = AutoOpenNotePad;
	pMainVF[eNoBlanks] = NoBlanks;
	pMainVF[eNone] = DoNone;
	pMainAF[eNone] = DoNone;
	pMainAF[eGetString] = GetString;
	pMainAF[eOldText] = TextReceived;
	pMainAF[eNoBlanks] = NoBlanks;
	pMainAF[eNotePad] = OpenNotePad;
	pMainAF[eLeadCap] = LeadingCapsSelect;
	pMainAF[eAutoNotePad] = AutoOpenNotePad;

	sprintf( TextOut,"\nnMenuItems: %d\n\n", nMenuItems);
	PutString(TextOut );
	getch();
	do
	{	system( "cls");
		for( iMenu = 0; iMenu < nMenuItems; iMenu++ )
		{	pMainVF[ MainItems[iMenu].Value ]( ValueText);
			sprintf( TextOut, "%2d %-30.30s %-40.40s\n", iMenu, MainItems[iMenu].Text, ValueText );
			PutString( TextOut );
		}
		iIn = getch();
		iMenu = iIn - (int)'0';
		if( iIn != (int)'x' && iMenu > (nMenuItems - 1) ) 
		{ putch(iIn); PutString( " ? (Hit a key to proceed)\n" ); getch(); }
		else pMainAF[ MainItems[iMenu].Action ]( SelectedText );
	} while ( iIn != (int)'x' );
	
	PutString( "\nNormal exit\n >:)\n" );
}
