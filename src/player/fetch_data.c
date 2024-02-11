#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <linux/limits.h>
#include <player/fetch_data.h>

#define p_fetch_command "playerctl metadata"

Player get_player_value(unsigned short metadata_type)
{

    FILE *p_fetch;

    /**
     * -1: Error
     */
    int status;
    char value[1024];
    char buffer[100], *p_fetch_command_formatted = (char*)malloc(50 * sizeof(char));;

    /**
     * |----------------------------------------------
     * | Option Parser
     * |----------------------------------------------
     * |
     */

    char *metadata_string[11] = {
        "mpris:trackid",
        "mpris:length",
        "mpris:artUrl",
        "xesam:album",
        "xesam:albumArtist",
        "xesam:artist",
        "xesam:autoRating",
        "xesam:discNumber",
        "xesam:title",
        "xesam:trackNumber",
        "xesam:url",
    };

    char *metadata;
    metadata = metadata_string[metadata_type >= 0 && metadata_type <= 10 ? metadata_type : 0];
    sprintf(p_fetch_command_formatted, "%s %s", p_fetch_command, metadata);

    char p_fetch_command_converted_and_formatted[sizeof(p_fetch_command_formatted)];
    strcpy(p_fetch_command_converted_and_formatted, p_fetch_command_formatted);
    p_fetch = popen(p_fetch_command_converted_and_formatted, "r");

    fgets(value, sizeof(buffer), p_fetch);

    Player player;

    player.status = status;
    strcpy(player.value, value); 
    

    /**
     * |----------------------------------------------
     * | Error Parser
     * |----------------------------------------------
     + |
    */
    status = pclose(p_fetch);


    return player;
}