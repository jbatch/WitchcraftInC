#include <ncurses.h>

int main()
{
        int ch;

        initscr();
        raw(); /* disable line buffering */
        keypad(stdscr, TRUE); /* Can use F1, F2 etc */
        noecho();

        printw("Type any character to see it in bold\n");
        ch = getch();
        if(ch == KEY_F(1))
        {
                printw("F1 Key Pressed");
        }
        else
        {
                printw("The letter pressed is ");
                attron(A_BOLD);
                printw("%c", ch);
                attroff(A_BOLD);
        }

        refresh();
        getch();
        endwin();

        return 0;
}
