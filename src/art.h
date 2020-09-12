#pragma once

#include <ncurses.h>
#include "stage.h"


void printToilet(Stage stage) {
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+0,  HPAD,   " .----------------.         ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+1,  HPAD, " ;----------------;         ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+2,  HPAD, " | ~~ .------.    |         ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+3,  HPAD, " |   /        \\   |         ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+4,  HPAD, " |  /          \\  |         ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+5,  HPAD, " |  |          |  |  ,----. ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+6,  HPAD, " |   \\ ,    , /   | =|____|="); 
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+7,  HPAD, " '---,########,---'  (---(  ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+8,  HPAD, "    /##'    '##\\      )---) ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+9,  HPAD, "    |##,    ,##|     (---(  ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+10, HPAD, "     \\'######'/       '---` ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+11, HPAD, "      \\`\"\"\"\"`/              ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+12, HPAD, "       |`\"\"`|               ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+13, HPAD, "     .-|    |-.             ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+14, HPAD, "    /  '    '  \\            ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+15, HPAD, "    '----------'            ");
}

void printMonkey(Stage stage) {
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+8,  (HPAD*30), "          __       ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+9,  (HPAD*30), "     w  c(..)o   ( ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+10, (HPAD*30), "      \\__(-)    __)");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+11, (HPAD*30), "          /\\   (   ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+12, (HPAD*30), "         /(_)___)  ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+13, (HPAD*30), "         w /|      ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+14, (HPAD*30), "          | \\      ");
	mvprintw(VPAD + stage.floor.size() + (VPAD*2)+15, (HPAD*30), "         m  m      ");
}
