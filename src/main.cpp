#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#include "input.h"
#include "stage.h"
#include "common.h"
#include "art.h"

using namespace std;

void removeEnt(Stage &stage) {
	for (int i = 0; i < stage.ents.size(); i++) {
		if (stage.player == i) {
			continue;
		}

		if (stage.ents[stage.player].x == stage.ents[i].x && stage.ents[stage.player].y == stage.ents[i].y) {
			stage.ents.erase(stage.ents.begin()+i);
			return;
		}
	}
}

void encounter(Stage &stage) {
	bool still = true;
	while(still) {
		stage.render();
		printToilet(stage);
		printMonkey(stage);

		int newVPAD = VPAD + stage.floor.size() + (VPAD*2)+15 + VPAD;
		mvprintw(newVPAD, HPAD,   "It's going to attack you! What should you do?");
		mvprintw(newVPAD+1, HPAD, "1 - Teach it sign language and convince it to join you on the quest");
		mvprintw(newVPAD+2, HPAD, "2 - Perform questionable makeup expirementation");
		mvprintw(newVPAD+3, HPAD, "3 - Fire the Air Force Van 1 Gun");
		mvprintw(newVPAD+4, HPAD, "4 - Blow up the Van...");

		int input = getch();
		switch(input) {
			case KeyEsc: {
				endwin();
				exit(1);
			}
			case Key1: {
				if (rand()%2 == 0) {
					mvprintw(newVPAD+6, HPAD, "It worked! You gain 10 Health!");
					stage.ents[stage.player].health += 10;
					still = false;
					removeEnt(stage);
					
				} else {
					mvprintw(newVPAD+6, HPAD, "How much did you really expect that to work??? Health - 10");
					stage.ents[stage.player].health -= 10;
				}
				break;
			}
			case Key2: {
				mvprintw(newVPAD+6, HPAD, "You give the Monkey a wonderful shade of eyeliner, but it keels over due to the lead...");
				still = false;
				removeEnt(stage);
				break;
			}
			case Key3: {
				mvprintw(newVPAD+6, HPAD, "Wait.... we forgot the Air Force Van 1 Gun! Health - 10");
				stage.ents[stage.player].health -= 10;
				break;
			}
			case Key4: {
				mvprintw(newVPAD+6, HPAD, "Really? That's what you want? Okay.......");
				mvprintw(newVPAD+8, HPAD, "*BOOM*");
				getch();
				stage.ents[stage.player].health = 0;
			}
            default: {
				mvprintw(newVPAD+10, HPAD, "Try again: %d", input);
				break;
            }
		}
		
		if (stage.ents[stage.player].health <= 0) {
			mvprintw(newVPAD+6, HPAD, "Unfortunetely, you've come down with a very minor case of mortality.");
			while(getch()!=KeyEsc);
			endwin();
			exit(1);
		}
	}
}
                          
int main() {
    initscr();
    noecho();
    clear();
    refresh();
    Stage stage;

	mvprintw(VPAD, HPAD,   "You, Melania Trump, have realized the error of your ways!");
	mvprintw(VPAD+1, HPAD, "You now know that is was wrong to plunder your first Solid");
	mvprintw(VPAD+2, HPAD, "Gold Toilet from the Monkey Kingdom! Turns out, they");
	mvprintw(VPAD+3, HPAD, "warshiped it! Now you've yeeted the Solid Gold Toilet into");
	mvprintw(VPAD+4, HPAD, "Air Force Van 1, and are going to take the new Monkey Kingdom");
	mvprintw(VPAD+5, HPAD, "Super Highway across the ocean to return their sacred relic...");
	getch();
	clear();

    while(5>4) {
        stage.render();
        int input = getch();
        clear();

        switch(input) {
            case KeyEsc: {
                endwin();
                exit(1);
                break;
            }
            case KeyW: {
                if (stage.floor[stage.ents[stage.player].y-1][stage.ents[stage.player].x] == '.') 
                    stage.ents[stage.player].y--;
                break;
            }
            case KeyS: {
                if (stage.floor[stage.ents[stage.player].y+1][stage.ents[stage.player].x] == '.') 
                    stage.ents[stage.player].y++;           
                break;
            }
            default: {
                mvprintw(VPAD + stage.floor.size() + VPAD, HPAD, "Nah Fam: %d", input);
            }
        }
        refresh();
        int ret = stage.simulate();
        if (ret == Encounter) {
            mvprintw(VPAD + stage.floor.size() + VPAD, HPAD, "You have encountered a Monkey!");
			encounter(stage);
        }

        usleep(15);
    }
    clear();


    endwin();
    return 0;
}
