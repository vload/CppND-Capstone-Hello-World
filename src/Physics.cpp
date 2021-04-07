#include "Physics.h"

Physics::Physics(PongData& data) : data(data) {}

void Physics::mirror_ball_velocity(Axis axis) {
    if(axis == Axis::X)
        data.ball_v_x = -data.ball_v_x;
    else
        data.ball_v_y = -data.ball_v_y;
}

void Physics::compute_physics() {
    bool a_scored = false;
    bool b_scored = false;

    // compute collisions for ball
    SDL_Rect next_ball = data.ball;
    next_ball.x += data.ball_v_x;
    next_ball.y += data.ball_v_y;

    if(SDL_HasIntersection(&next_ball, &data.bar_a))
        mirror_ball_velocity(Axis::X);
    if(SDL_HasIntersection(&next_ball, &data.bar_b))
        mirror_ball_velocity(Axis::X);
    if(SDL_HasIntersection(&next_ball, &top))
        mirror_ball_velocity(Axis::Y);
    if(SDL_HasIntersection(&next_ball, &bottom))
        mirror_ball_velocity(Axis::Y);
    if(SDL_HasIntersection(&next_ball, &a_wall))
        b_scored = true;
    if(SDL_HasIntersection(&next_ball, &b_wall))
        a_scored = true;

    // compute collisions for bars
    if(SDL_HasIntersection(&top, &data.bar_a))
        data.bar_a.y += 2;
    if(SDL_HasIntersection(&top, &data.bar_b))
        data.bar_b.y += 2;
    if(SDL_HasIntersection(&bottom, &data.bar_a))
        data.bar_a.y -= 2;
    if(SDL_HasIntersection(&bottom, &data.bar_b))
        data.bar_b.y -= 2;

    // see who scored
    if(a_scored or b_scored)
        data.ball = ball_reset;
    if(a_scored)
        data.score_a++;
    if(b_scored)
        data.score_b++;

    data.ball.x += data.ball_v_x;
    data.ball.y += data.ball_v_y;
}
