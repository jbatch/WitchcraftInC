WitchcraftInC
=============

A little ncurses tutorial I'm doing as practice for a larger project later on ;)

#Usage#
If for some reason you want to see what any of the files do you can do so like

```shell
cd keys
gcc keys.c -lncurses
./a.out
```

All ncurses apps need to be linked with the ncurses header with `-lncurses`

Also any apps in the panel folder require `-lpanel -lncurses` and any apps in the menu folder require `-lmenu -lncurses`
