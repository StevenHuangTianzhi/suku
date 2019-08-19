#ifndef STEVENH_AI
#define STEVENH_AI
#include "OthelloCell.hpp"
#include "OthelloAI.hpp"
#include <vector>
#include <utility>


namespace tianzhh
{
    class StevenAI:public OthelloAI
    {
    public:
        virtual std::pair<int,int> chooseMove(const OthelloGameState& state);
        int eval(std::unique_ptr<OthelloGameState>& state,int turn);
        std::vector<std::pair<int,int>> copy_avaliable_moves(std::unique_ptr<OthelloGameState>& state);
        std::vector<std::pair<int,int>> curr_avaliable_moves(const OthelloGameState& state);
        int search(std::unique_ptr<OthelloGameState>& state, int depth, int turn);
    };
}










#endif
