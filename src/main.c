#include <stdio.h>
#include <window/window.h>
#include <player/fetch_data.h>


int main(int argc, char **argv) {


    Player p = get_player_value((unsigned short)argc);

    printf("%s", p.value);
     
    //window(argc, argv);
    return 0;
}