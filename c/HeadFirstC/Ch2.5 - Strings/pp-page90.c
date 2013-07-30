void find_track(char search_for[])
{
    int i;

    for (i = 0; i < 5; ++i) {
        if (strstr(tracks[i], search_for))
            printf("Track %i: '%s'\n", i, tracks[i]);
    }
}
