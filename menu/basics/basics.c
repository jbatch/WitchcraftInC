#include <curses.h>
#include <menu.h>
#include <stdlib.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CTRLD 4

char *choices[] = {
        "Choice 1",
        "Choice 2",
        "Choice 3",
        "Choice 4",
        "Exit"
};

int main()
{
        ITEM **items;
        int c;
        MENU *menu;
        int n_choices, i;
        ITEM *cur_item;

        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);

        n_choices = ARRAY_SIZE(choices);
        items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));

        for(i = 0; i < n_choices; i++)
                items[i] = new_item(choices[i], "");
        items[n_choices] = (ITEM *)NULL;

        menu = new_menu(items);
        mvprintw(LINES -2, 0, "F12 to EXIT");
        post_menu(menu);
        refresh();

        while((c = getch()) != KEY_F(12)) {
                switch(c) {
                case KEY_DOWN:
                        menu_driver(menu, REQ_DOWN_ITEM);
                        break;
                case KEY_UP:
                        menu_driver(menu, REQ_UP_ITEM);
                        break;
                }
        }

        for(i = 0; i < n_choices - 1; i++) {
                free_item(items[i]);
        }
        free_menu(menu);
        endwin();
        return 0;
}
