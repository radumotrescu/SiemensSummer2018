#include <iostream>

class StrategyAttack {
    public:
    virtual auto Attack() -> void = 0;
};

class StrategyDefense {
    public:
    virtual auto Defend() -> void = 0;
};

class Player {
    public:
    Player(StrategyAttack* attack, StrategyDefense* defense)
        : m_attack(attack), m_defense(defense) { }

    auto Play() -> void {
        m_attack->Attack();
        m_defense->Defend();
    }

    private:
    StrategyAttack* m_attack;
    StrategyDefense* m_defense;
};

class MageAttack : public StrategyAttack {
    public:
    virtual auto Attack() -> void {
        std::cout << "I Mage I Attack" << std::endl;
    }
};

class WarriorAttack : public StrategyAttack {
    public:
    virtual auto Attack() -> void {
        std::cout << "I Warrior I Attack" << std::endl;
    }
};

class MageDefense : public StrategyDefense {
    public:
    virtual auto Defend() -> void {
        std::cout << "I Mage I Defend" << std::endl;
    }
};

class WarriorDefense : public StrategyDefense {
    public:
    virtual auto Defend() -> void {
        std::cout << "I Warrior I Defend" << std::endl;
    }
};

template<typename Attack, typename Defense> 
class CoolPlayer : private Attack, private Defense {
    public:
    auto Play() -> void {
        this->Attack();
        this->Defend();
    }
};

auto main() -> int {
    auto coolMage = new CoolPlayer<MageAttack, MageDefense>();
    auto coolWarrior = new CoolPlayer<WarriorAttack, WarriorDefense>();

    coolMage->Play();
    coolWarrior->Play();

    auto mage = new Player(new MageAttack(), new MageDefense());
    auto warrior = new Player(new WarriorAttack(), new WarriorDefense());

    mage->Play();
    warrior->Play();

    return 0;
}
