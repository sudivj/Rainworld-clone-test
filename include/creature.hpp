#include "body/bodypart.hpp"

enum CreatureStatus
{
    IDLING = 0,
    HUNTING,
    SEARCHING,
    SLEEPING
};

struct Creature
{
    std::string creatureName;
    CreatureStatus status = CreatureStatus::IDLING;
    bool alive = true;
};
typedef struct Creature Creature;
