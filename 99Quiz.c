/*      This program is free software: you can redistribute it and/or modify 
 *      it under the terms of the GNU General Public License as published by 
 *      the Free Software Foundation, either version 3 of the License, or 
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful, 
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General 
 *      Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along 
 *      with this program. If not, see <https://www.gnu.org/licenses/>. 
 *
 * ---------------------------------------------------------------------
 * al-Asma al-Husna Quiz (or 99 Quiz)
 *
 * This program administers a quiz on the Names of Allah(subhanahu wa ta'la).
 * It's a sort of game, really. The player gets 5 points for each correct 
 * answer and a strike for every wrong answer. Once three strikes are 
 * reached the Quiz ends.
 *
 * - Maurice V. 
 * - version 1.0 [ January 30, 2022 ]
 *
*/

#include <stdio.h>
#include <time.h>

#define MAX_LENGTH 300  // Maximum length of a Name or Explanation
#define NUM_STRINGS 99  // Total number of Names and Explanations
                        // The actual number that I have included are fewer than 99

void quiz_menu(char Anames[NUM_STRINGS][MAX_LENGTH], char Aexplanations[NUM_STRINGS][MAX_LENGTH])
{

    int answer;           // This is the index of the correct answer to the question
    int user_choice, correct_choice;  // What the user chooses from the multiple choice
    int choice_b, choice_c;   // Alternate decoy answers
    int strikes = 0;          // Total number of strikes the use has thus far
    int points = 0;           // Points awarded for correct answer in increments of 5

    srand(time(NULL));        // seed the random number generator 

    while (strikes < 3) {     // Continue as long as the player has fewer than 
	                      // 3 wrong answers

    	answer = rand() % 88; // answer is the name chosen to be the correct answer
	                      // We use rand() % 88 to get a number in the range
			      // of 0-87 which will correspond to a name in the 
			      // Anames array.
	
	choice_b = rand() % 88;  // A decoy use to construct the multiple choice 
	                         // questions.  A wrong answer.
	choice_c = rand() % 88;  // "     "             "
	

	// Make sure we don't have repeated choices. There is a better way to 
	// do this I know. But hey, I'm a noob.
	while (answer == choice_b || answer == choice_c || choice_b == choice_c) {
		answer = rand() % 88;  
		choice_b = rand() % 88;
		choice_c = rand() % 88;
        }
        printf("\t\t\t-== 99 Quiz v1.0 ==-");
	printf("\033[0;33m");    // Changes the text color
        printf("\n\nYou have %d strike(s)!\n\n", strikes);
        printf("\033[0m");       // Changes the text color back to default

	// Query the user
	printf("What is the meaning of [ %s ] ?\n\n", Anames[answer]);

	// configuration is a random number between 0 and 2.  I use it to
	// choose one of three orderings for the multiple choice answers
	// so that the answer is not always in the same spot in the list.
        int configuration = rand() % 3;

	if (configuration == 0) {  // First configuration with answer as first choice
           correct_choice = 1;     // index of the correct answer in this config
	   printf("[1] %s\n", Aexplanations[answer]);
	   printf("[2] %s\n", Aexplanations[choice_b]);
	   printf("[3] %s\n", Aexplanations[choice_c]);
	}
	else if (configuration == 1) {  // Answer as second choice
           correct_choice = 2;       
	   printf("[1] %s\n", Aexplanations[choice_b]);
	   printf("[2] %s\n", Aexplanations[answer]);
	   printf("[3] %s\n", Aexplanations[choice_c]);
	}
	else {
	   correct_choice = 3;        // Answer as third choice
	   printf("[1] %s\n", Aexplanations[choice_c]);
	   printf("[2] %s\n", Aexplanations[choice_b]);
	   printf("[3] %s\n", Aexplanations[answer]);
	}
	// Prompt the user for a reponse and also display current point total
        printf("\n\n Answer? [ Points = %d ] ", points);
	scanf("%d", &user_choice);

        if (user_choice == correct_choice) {  // Their choice was the correct answer
		printf("\033[0;32m");  // Change the text color
		printf("\n\nThat is correct! Good job! +5 pts\n\n");
		printf("\033[0m");     // Change it back
		points = points + 5;          // Give 'em 5 points

	} else {  // Otherwise they entered an incorrect choice
          printf("\033[0;31m");              
	  printf("\n\nThat is incorrect.  %s means %s\n\n", Anames[answer], Aexplanations[answer]);
	  printf("\033[0m");
          strikes++; // Add one strike for an incorrect answer
	}
   }
}

int main() {
   
   // Allah_names is self explanatory.  I left out one of "The Guardian" names
   // because it appears twice and I did not know how to distinguish between
   // the two.  Shaykh Abu 'Abdu-r-Rahmaan Naasir as-Sa'dee's (rahimahullah) English 
   // translation of "Explanation to the Beautiful and Perfect Names of Allah"
   // has both listed as "The Guardian."  I did not want to take liberties with
   // the description.  For other Names that are similar I added a line from the 
   // long description for one of the Names.

   char Allah_names[NUM_STRINGS][MAX_LENGTH] = { {"Ar-Rabb"}, 
	                                   {"Allah"},
					   {"al-Malik"},
                                           {"al-Maalik"},
			                   {"Alladhi lahu-l-Mulk"},
					   {"al-Wahid"},
					   {"al-Ahad"},
					   {"as-Samad"},
					   {"al-'Aleem"},
					   {"al-Khabeer"},
					   {"al-Hakeem"},
					   {"ar-Rahmaan"},
					   {"ar-Raheem"},
					   {"al-Barr"},
					   {"al-Kareem"},
					   {"al-Jawwad"},
					   {"ar-Ra'uf"},
					   {"al-Wahhab"},
					   {"as-Samee"},
					   {"al-Baseer"},
					   {"al-Hameed"},
					   {"al-Majeed"},
                                           {"al-Kabeer"},
                                           {"al-Azeem"},
                                           {"al-Jaleel"},
                                           {"al-'Afuww"},
                                           {"al-Ghafur"},
                                           {"al-Ghaffar"},
                                           {"at-Tawwab"},
                                           {"al-Quddus"},
                                           {"as-Salam"},
                                           {"al-'Ali"},
                                           {"al-A'laa"},
                                           {"al-'Azeez"},
                                           {"al-Qawee"},
                                           {"al-Mateen"},
                                           {"al-Jabbaar"},
                                           {"al-Mutakabbir"},
                                           {"al-Khaaliq"},
                                           {"al-Baari'"},
                                           {"al-Musawwir"},
                                           {"al-Mu'min"},
                                           {"al-Muhaymin"},
                                           {"al-Qadeer"},
                                           {"al-Lateef"},
                                           {"al-Haseeb"},
                                           {"al-Raqeeb"},
                                           {"al-Haafiz"},
                                           {"al-Muheet"},
                                           {"al-Qahhaar"},
                                           {"al-Qaahir"},
                                           {"al-Muqeet"},
                                           {"al-Wakeel"},
                                           {"Dhu-l-Jalali wa-l-Ikraam"},
                                           {"al-Wuduud"},
                                           {"al-Fattah"},
                                           {"ar-Razzaq"},
                                           {"al-Hakam"},
                                           {"al-'Adl"},
                                           {"Jaami'u-n-Naas"},
                                           {"al-Hayy"},
                                           {"al-Qayyum"},
                                           {"an-Nuur"},
					   {"Badee' u-s-Samaawaati wa-l-Ard"},
					   {"al-Qaabid"},
					   {"al-Baasit"},
					   {"al-Mu'tee"},
					   {"al-Maani'"},
					   {"ash-Shaheed"},
					   {"al-Mubdee'"},
					   {"al-Mu'eed"},
					   {"al-Fa'aalu-l-Limaa Yureed"},
					   {"al-Ghanee"},
					   {"al-Mughnee"},
					   {"al-Haleem"},
					   {"ash-Shaakir"},
					   {"ash-Shakuur"},
					   {"al-Qareeb"},
					   {"al-Mujeeb"},
					   {"al-Kaafee"},
					   {"al-Awwal"},
					   {"al-AAkhir"},
					   {"al-Zaahir"},
					   {"al-Baatin"},
					   {"al-Waasi'"},
					   {"al-Haadee"},
					   {"ar-Rasheed"},
					   {"al-Haqq"}

   };

   // These are the short explanations of the names in the Allah_names array.
   // The indexes for both arrays match up.  So Allah_exp[0] is the explanation
   // of the name at Allah_names[0].

   char Allah_exp[NUM_STRINGS][MAX_LENGTH] = { {"The Lord and Cherisher"},
	                                          {"The One and Only deity"},
						  {"The King"},
                                                  {"The Master and Owner"},
                                                  {"The One to Whom belongs the dominion"},
                                                  {"The One"},
                                                  {"The One [The Unique]"},
                                                  {"The Self-Sufficient"},
                                                  {"The All-Knowing"},
                                                  {"The All-Aware"},
                                                  {"The All-Wise"},
                                                  {"The All-Merciful"},
                                                  {"The Most Merciful"},
                                                  {"The Generous"},
                                                  {"The Kind [The Generous]"},
                                                  {"The Bestower of Good"},
                                                  {"The Kind"},
                                                  {"The Bestower"},
                                                  {"The All-Hearing"},
                                                  {"The All-Seeing"},
                                                  {"The One Who is Praised"},
                                                  {"The Glorious"},
                                                  {"The Great"},
                                                  {"The Exalted"},
                                                  {"The Noble"},
                                                  {"The Forgiving"},
                                                  {"The Ever-Forgiving"},
                                                  {"The All-Forgiving"},
                                                  {"The Oft-Returning"},
                                                  {"The Holy"},
                                                  {"The Perfect Peace"},
                                                  {"The High"},
                                                  {"The Most High"},
                                                  {"The Almighty"},
                                                  {"The Strong"},
                                                  {"The Powerful"},
                                                  {"The Compeller"},
                                                  {"The Supreme"},
                                                  {"The Creator"},
                                                  {"The Originator"},
                                                  {"The Bestower of Forms"},
                                                  {"The Giver of Security"},
                                                  {"The Ever-Watching"},
                                                  {"All-Powerful, The Able"},
                                                  {"The Most Subtle, The Kind"},
						  {"The Reckoner"},
                                                  {"The All-Watcher"},
                                                  {"The Guardian"},
                                                  {"The Encompassing"},
                                                  {"The Subduer"},
                                                  {"The Irresistible"},
                                                  {"The Powerful-The One who provides everything with what strengthens it"},
                                                  {"The Disposer of Affairs, the One Who is relied upon"},
						  {"The One possessing Majesty and Honour"},
						  {"The Loving"},
						  {"The Judge, The Opener"},
						  {"The Provider"},
						  {"The Judge"},
						  {"The Just"},
						  {"The Gatherer of Mankind"},
						  {"The Living"},
						  {"The Self-Sustaining"},
						  {"The Light"},
                                                  {"The Originator of the heavens and the earth"},
                                                  {"The Taker"},
                                                  {"The Extender"},
                                                  {"The Giver"},
                                                  {"The Preventer"},
                                                  {"The Witness"},
                                                  {"The Starter"},
                                                  {"The Recaller, The One Who repeats creation"},
                                                  {"The One Who does what He Wills"},
                                                  {"The Self-Sufficient, The Rich"},
                                                  {"The Sufficient, Enricher"},
                                                  {"The Forbearing"},
                                                  {"The Recogniser and Rewarder of good"},
                                                  {"The Appreciative"},
                                                  {"The Close"},
                                                  {"The Answerer"},
                                                  {"The Sufficient"},
                                                  {"The First"},
                                                  {"The Last"},
                                                  {"The Manifest"},
                                                  {"The Inward"},
                                                  {"The Vast"},
                                                  {"The Director"},
                                                  {"The Guide"},
                                                  {"The Truth"}
                                                  };
   // call the controlling function
   quiz_menu(Allah_names, Allah_exp);

   return 0;  
}
