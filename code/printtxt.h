void printo(SDL_Renderer *rend, int x, int y, char* txt,TTF_Font *font,SDL_Texture **texture, SDL_Rect *rect)
{

	int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, txt, textColor);
    *texture = SDL_CreateTextureFromSurface(rend, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;

}