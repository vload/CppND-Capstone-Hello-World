#ifndef INPUT_H
#define INPUT_H

#include "PongData.h"
#include "constants.h"
#include <SDL2/SDL.h>

class Input {
private:
    PongData& data;

public:
    Input(PongData& data);

    void handle_input();
};

#endif // INPUT_H