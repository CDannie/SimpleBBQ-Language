/******************************************************************************************************************************BS"D
SimpleBBQ interpreter made by Daniel E. ( and the help of my father :) )
GitHub: CDannie
Esolangs.org: DanielE
Happy SimpleBBQ coding!
May 2022
*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define TRUE 1
#define FALSE 0
// Set DEBUG_ME to TRUE for verbose debug information
#define DEBUG_ME FALSE 
#define MAX_INPUT_FILE 100000
#define MAX_PATH_LENGTH 254

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
	{
	 FILE *fp; //file pointer
	 int nugget = 1; //integer used for if-statements
	 int hamburger = 1; //used as main integer in the esolang
	 int sate; //used as command pointer. See line 164.
	 char beef; //used as main char in the esolang
	 char last_char, next_char, prev_char; //symbol count
	 int same_item_count = 0;
	 bool tomato = FALSE;
	 bool comment = FALSE;
		prev_char = last_char;
		next_char = last_char;

	 if(argc > 3) {printf("\nSimpleBBQ: Error: too many arguments\n\n(Stopped)\n"); return -1;} //Don't throw too much on the BBQ!
	 if(argc == 3) hamburger = (int)(*argv[2]);
	 if(argc < 2) {printf("\nSimpleBBQ: Error: please specify filename\n\n(Stopped)\n"); return -1;} //R U gonna use the BBQ anyway?

// Test input
// Belangrijk voor hackers en voor user gemak
// test 1: is er een argument 
// test 2: zijn er meer argumenten meegeven
// test 3: Hoe lang is de string die is meegeven. dus MAX_PATH_LENGTH
//
// 

	 if(argc == 2) fp = fopen(argv[1], "r");
	 if(fp == NULL) {printf("\nSimpleBBQ: Error: empty file\n\n(Stopped)\n"); return -1;} //because real meat is still better than vegan

// Test file
// Seek SEEK_END
// uitlezen index
// als index = 0 gebruiker straffen of fun tonen
// als index > MAX_FILE_SIZE 

	 while(1) //actual interpreter
	 {
	 	last_char = fgetc(fp);
	 	if(feof(fp)) break;

		same_item_count = 0;
		prev_char = last_char;
		next_char = last_char;

		// Count number of same sequential letters
		while ( next_char != EOF && next_char == prev_char)
      	{
        	next_char = fgetc(fp);
       		same_item_count += 1;
      	}

if ( next_char != EOF)
   {
    fseek (fp, -1, SEEK_CUR);
    if (DEBUG_ME) printf("char found: %c n=%d \n", prev_char, same_item_count);
    switch(prev_char)
    {      
	    case 'q':
    		if(tomato == TRUE && nugget == hamburger && comment == FALSE)
    		{
    			switch(same_item_count)
    			{
    				case 1: scanf("%d", &hamburger); break;
    				case 2: scanf("%c", &hamburger); break;
    				case 3: printf("%d", hamburger); hamburger = 1; break; //WERKT NIET
    				case 4: printf("%c", hamburger); hamburger = 1; break;
    				case 5: printf("%d", hamburger); break; //WERKT NIET
    				case 6: printf("%c", hamburger); break;
    				default: printf("\nBibbercode; make it warmer. -Daniel\n"); break;
    			}
    		}
    		if(tomato == FALSE && comment == FALSE)
    		{
    			switch(same_item_count)
    			{
    				case 1: scanf("%d", &hamburger); break;
    				case 2: scanf("%c", &hamburger); break;
    				case 3: printf("%d", hamburger); hamburger = 1; break; //WERKT NIET
    				case 4: printf("%c", hamburger); hamburger = 1; break;
    				case 5: printf("%d", hamburger); break; //WERKT NIET
    				case 6: printf("%c", hamburger); break;
    				default: printf("\nBibbercode; make it warmer. -Daniel\n"); break;
    			}
    		}
    		break;

    	case 'b':
    		if((tomato == TRUE) && (nugget == hamburger) && (comment == FALSE))
    		{
    			switch(same_item_count)
    			{
   					case 1: hamburger++; break;
   					case 2: hamburger--; break;
   					case 3: hamburger = hamburger*2; break;
   					case 4: hamburger = hamburger/2; break;
   					case 5: hamburger = hamburger*hamburger; break;
   					case 6: hamburger = 1; break;
      				default: hamburger = hamburger + same_item_count; break;
    			}
    		}
    		if(tomato == FALSE && comment == FALSE)
    		{
    			switch(same_item_count)
    				{
    					case 1: hamburger++; break;
    					case 2: hamburger--; break;
    					case 3: hamburger = hamburger*2; break;
    					case 4: hamburger = hamburger/2; break;
    					case 5: hamburger = hamburger*hamburger; break;
    					case 6: hamburger = 1; break;
    					default: hamburger = hamburger + same_item_count; break;
    				}
    		}
    		break;

    	case 'B':  // Uppercase Q is used for if-statements
    		if(comment == FALSE)
    		{
    		tomato = TRUE;
    		switch(same_item_count)
    		{
    			case 1: nugget++; break;
    			case 2: nugget--; break;
    			case 3: nugget = nugget*2; break;  
    			case 4: nugget = nugget/2; break;
    			case 5: nugget = nugget*nugget; break;
    			default: nugget = nugget + same_item_count; break;
    		}
    	}
    		break;

    	case 'Q': if(comment == FALSE) {tomato = FALSE; nugget = 1;} break;

    	case 'C': if(comment == FALSE) printf("%d", nugget); break;

    	case 10: break;

    	case '(': comment = TRUE; break;

    	case ')': comment = FALSE; break;

    	case ' ': break;

    	default:
    		if(comment == FALSE)
    		{
    			fseek(fp, 0, SEEK_CUR); sate = ftell(fp);
    			if(last_char == 'g' && (last_char = fgetc(fp)) == 'r' && (last_char = fgetc(fp)) == 'i' && (last_char = fgetc(fp)) == 'l' && (last_char = fgetc(fp)) == 'l')
    				{hamburger = hamburger*hamburger; break;} else fseek(fp, sate, SEEK_SET);
    			if(last_char == 'p' && (last_char = fgetc(fp)) == 'l' && (last_char = fgetc(fp)) == 'a' && (last_char = fgetc(fp)) == 'c' && (last_char = fgetc(fp)) == 'e')
    				{scanf("%d", &hamburger); break;} else fseek(fp, sate, SEEK_SET);
    			if(last_char == 's' && (last_char = fgetc(fp)) == 'e' && (last_char = fgetc(fp)) == 'r' && (last_char = fgetc(fp)) == 'v' && (last_char = fgetc(fp)) == 'e')
    				{printf("%d", hamburger); break;} else fseek(fp, sate, SEEK_SET);


    			printf("\nHamburger cooled off. Just read the description. Greetings from Daniel.\n");
    			break;
    		}
    		if(comment == TRUE) break;
    }

   }

	 }

	 fclose(fp);
	 return 0;
	}