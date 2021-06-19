#ifndef CHARACTER_H
#define CHARACTER_H

#include "Auxiliaries.h"
#include <vector>
#include <memory>

namespace mtm {
    class Character {
    protected:
        int health;
        int ammo;
        int range;
        int power;
        Team team;
        const int movement_range;
        const int ammo_on_reload;
        const int ammo_attack_cost;
        const char sign;

    public:
        //C'TORS & D'TORS
        /**
         * Constructor of Character class
         * @param health points
         * @param ammo points
         * @param range attack
         * @param power points
         * @param team - POWERLIFTERS or CROSSFITTERS
         * @param movement_range in board
         * @param ammo_on_reload - ammo points character get on reload
         * @param ammo_attack_cost - ammo points character lose when attack
         * @param sign of character
         */
        Character(int health, int ammo, int range, int power, Team team, int movement_range, int ammo_on_reload,
                  int ammo_attack_cost, char sign) : health(health), ammo(ammo),
                                                                                          range(range),
                                                                                          power(power), team(team),
                                                                                          movement_range(
                                                                                                  movement_range),
                                                                                          ammo_on_reload(
                                                                                                  ammo_on_reload),
                                                                                          ammo_attack_cost(
                                                                                                  ammo_attack_cost),
                                                                                          sign(sign) {};
        /**
         * Copy constructor
         * @param character to copy
         */
        Character(const Character &character) : health(character.health), ammo(character.ammo), range(character.range),
                                                power(character.power), team(character.team),
                                                movement_range(character.movement_range),
                                                ammo_on_reload(character.ammo_on_reload),
                                                ammo_attack_cost(character.ammo_attack_cost), sign(character.sign) {};

        /**
         * Destructor of character
         */
        virtual ~Character(){};

        //GENERIC FUNCTIONS OF CHARACTER
        /**
         * @return  if character has enough ammo to attack
         */
        bool checkEnoughAmmo();

        /**
         * @return character's team
         */
        Team getTeam();

        /**
         * @return character's sign
         */
        char getCharacterSign();

        /**
         * Reload ammo to character
         */
        void reloadAmmo();

        /**
         * Attack character
         * @param attack_damage - health points character loses when get attacked
         */
        void getAttacked(int attack_damage) ;

        /**
         * Check if move is valid for character
         * @param distance
         * @return if distance is within character's movement range
         */
        bool isValidMove(int distance);

        /**
         * check if character died after getting attacked
         * @return if character has no health points left
         */
        bool isDead();

        //VIRTUAL FUNCTIONS

        /**
         * Clone character
         * @return new instance of character
         */
        virtual Character* clone() const = 0;

        /**
         * Return vector contains possible attack targets in board according to destination coordinates
         * @param dst_coordinates - attack destination coordinates
         * @return Vector of shared pointers to GridPoint objects
         */
        virtual std::vector<std::shared_ptr<GridPoint>> getAttackTargets(const GridPoint &dst_coordinates);

        /**
         * check if character can attack target
         * @param src_coordinates of attacker
         * @param dst_coordinates of potential character to attack
         * @param target - potential character to attack
         * @return if target legal
         */
        virtual bool isLegalTarget(const GridPoint &src_coordinates, const GridPoint &dst_coordinates,
                                   std::shared_ptr<Character> target) = 0;

        /**
         * Check if target is in attack's range of character
         * @param distance between attacker's cell to target's cell
         * @return if character can attack target
         */
        virtual bool isAttackInRange(int distance);

        /**
         * Attack target
         * @param target to attack
         * @param is_main_target - if target is placed in destination coordinates
         */
        virtual void attack(std::shared_ptr<Character> target, bool is_main_target) =0;

    };
}

#endif //CHARACTER_H
