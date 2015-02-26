#pragma once

class PlayerModel
{
public:
    std::string name;
    int age;

    std::string current_state;
};

class PlayerState
{
public: // Operation
    void Move()
    {
        printf("(%s)move but do nothing\n", state_name().c_str());
    }

    void Attack()
    {
        printf("(%s)attack but do nothing\n", state_name().c_str());
    };

    void Check()
    {
        printf("(%s)check current state\n", state_name().c_str());
    };

public: // state
    void Active()
    {
    };

    void Update()
    {
    };

    void Disactive()
    {
    };

    std::string state_name() = 0;
};


class Player : public PlayerState // state proxy
{
public:
    Player();
    ~Player();

public:
    void Move()
    {
        current_state->Move();
    }

    void Attack()
    {
        current_state->Attack();
    };

    void Check()
    {
        current_state->Check();
    };

public:
    /*
     * state transition diagram
     * one switch method one switch map.
     *
     * Or, two dimensional map
     */
    void NormalSwitch();
    void TimeoutSwitch();

    std::map<PlayerState*, PlayerState*> normal_switch;
    std::map<PlayerState*, PlayerState*> timeout_switch;

    std::map<std::string, PlayerState*> all_state;
    PlayerState* current_state;

    PlayerModel* model;
};


// state implement
class PlayerMoving : public PlayerState
{
public:
    std::string state_name()
    {
        return "moving";
    }
};

class PlayerIdle : public PlayerState
{
public:
    std::string state_name()
    {
        return "idle";
    }
};


class PlayerAttacking : public PlayerState
{
public:
    std::string state_name()
    {
        return "attacking";
    }
};
