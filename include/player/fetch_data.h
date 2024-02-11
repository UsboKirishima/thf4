
enum
{
    trackid,
    length,
    artUrl,
    album,
    albumArtist,
    artist,
    autoRating,
    discNumber,
    title,
    trackNumber,
    url,
};


typedef struct {
    unsigned short status;
    char value[100];
} Player;

Player get_player_value(unsigned short metadata_type);