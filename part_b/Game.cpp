
#include "Game.h"
#include "Exceptions.h"
#include <iostream>


namespace mtm {
    Game::Game(int height, int width): height(height), width(width) {
        board.resize( height , std::vector<std::shared_ptr<Character>>(width, nullptr));
        team_players_count[CROSSFITTERS] = 0;
        team_players_count[POWERLIFTERS]=0;
        //todo: ADD EXCEPTION HANDLING
    }
    void Game::isLegalCell(const GridPoint& coordinates){
        if(coordinates.col>=width || coordinates.row >=height) {
            throw IllegalCell();
        }
    }

    void Game::isCellOccupied(const GridPoint& coordinates){
        if(board.at(coordinates.row).at(coordinates.col)){
           throw CellOccupied();
        }
    }

    void Game::isCellEmpty(const GridPoint& coordinates){
        if(!board.at(coordinates.row).at(coordinates.col)){
            throw CellEmpty();
        }
    }
    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character) {
        isLegalCell(coordinates);
        isCellOccupied(coordinates);
        board[coordinates.row][coordinates.col]=character;
        team_players_count[character->getTeam()]++;
    }

     std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                                                    units_t health, units_t ammo, units_t range, units_t power){
        if(health<=0 || ammo <0 || power <0 || range<0){
            throw IllegalArgument();
        }
        switch (type){
            case SOLDIER:return std::shared_ptr<Soldier>(new Soldier(health,ammo,range,power,team));
            case SNIPER:return std::shared_ptr<Sniper>(new Sniper(health,ammo,range,power,team));
            case MEDIC:return std::shared_ptr<Medic>(new Medic(health,ammo,range,power,team));
            default:break;
        }
    }

    void Game::move(const GridPoint & src_coordinates, const GridPoint & dst_coordinates){
        isLegalCell(src_coordinates);
        isLegalCell(dst_coordinates);
        isCellEmpty(src_coordinates);
        std::shared_ptr<Character> character_to_move = board.at(src_coordinates.row).at(src_coordinates.col);
        if(!character_to_move->isValidMove(GridPoint::distance(src_coordinates,dst_coordinates))){
            throw MoveTooFar();
        }
        isCellOccupied(dst_coordinates);
        board[src_coordinates.row][src_coordinates.col] = nullptr;
        board[dst_coordinates.row][dst_coordinates.col] = character_to_move;
    }

    void Game::reload(const GridPoint & coordinates){
        isLegalCell(coordinates);
        isCellEmpty(coordinates);
        std::shared_ptr<Character> character_to_reload = board.at(coordinates.row).at(coordinates.col);
        character_to_reload->reloadAmmo();
    }

    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates){
        isLegalCell(src_coordinates);
        isLegalCell(dst_coordinates);
        isCellEmpty(src_coordinates);
        std::shared_ptr<Character> attacker = board.at(src_coordinates.row).at(src_coordinates.col);
        if(attacker->isAttackInRange(src_coordinates,dst_coordinates)){
            throw OutOfRange();
        }
    }
    //todo:consider changing the for loops
    bool Game::isOver(Team* winningTeam) const{
        int power_lifters_count =team_players_count.at(POWERLIFTERS);
        int crossfitters_count =team_players_count.at(CROSSFITTERS);
        if((crossfitters_count>0 && power_lifters_count>0) || (power_lifters_count==0 && crossfitters_count==0)){
            return false;
        }
        if(winningTeam){
            *winningTeam= power_lifters_count > crossfitters_count ? POWERLIFTERS: CROSSFITTERS;
        }
        return true;
    }

    std::ostream &operator<<(std::ostream &os, const Game &game) {
        //todo can we use a vector and not an array here?
        std::vector<std::vector<char>> char_board(game.height, std::vector<char>(game.width, ' '));
        for (int row = 0; row < game.height; ++row){
            for(int column=0; column<game.width; ++column){
                std::shared_ptr<Character> character_at_cell = game.board.at(row).at(column);
                if(character_at_cell){
                    char_board[row][column] = character_at_cell->getCharacterSign();
                }
            }
        }
        printGameBoard(os, &char_board[0][0], &char_board[game.width-1][game.height-1], game.width);
        }
}
