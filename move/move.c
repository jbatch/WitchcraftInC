#include <ncurses.h>
#include <string.h>

int main()
{
        char msg[] = "This is my sTrInG";
        int row, col;

        initscr();
        getmaxyx(stdscr, row, col);
        mvprintw(row/2, (col-strlen(msg))/2, "%s", msg);

        mvprintw(row-2,0, "This screen has %d rows and %d columns\n", row, col);
        printw("Try resizing your window and running this again!");
        refresh();
        getch();
        endwin();

        return 0;
}
