#include"StevenH_AI.hpp"
#include <iostream>
#include <ics46/factory/DynamicFactory.hpp>

ICS46_DYNAMIC_FACTORY_REGISTER(OthelloAI,tianzhh::StevenAI,"KAWHI-WONT-GO-ANYWHERE (Required)");


std::vector<std::pair<int,int>> tianzhh::StevenAI::copy_avaliable_moves(std::unique_ptr<OthelloGameState>& state)
{
    int width = state->board().width();
    int height = state->board().height();

    std::vector<std::pair<int,int>> aval_moves;

    for(int i = 0; i < width;i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(state->isValidMove(i,j))
            {
                aval_moves.push_back(std::pair<int,int>(i,j));
            }
        }
    }
    return aval_moves;
}

std::vector<std::pair<int,int>> tianzhh::StevenAI::curr_avaliable_moves(const OthelloGameState& state)
{
    int width = state.board().width();
    int height = state.board().height();

    std::vector<std::pair<int,int>> aval_moves;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(state.isValidMove(i,j))
            {
                aval_moves.push_back(std::pair<int,int>(i,j));
            }
        }
    }
    return aval_moves;
}

int tianzhh::StevenAI::eval(std::unique_ptr<OthelloGameState>& state,int turn)
{
//    if (turn == 1)
//    {
//        return state->blackScore() - state->whiteScore();
//    }
//    else
//    {
//        return state->whiteScore() - state->blackScore();
//    }

    int score = 0;
    if(turn == 1)
    {
        std::vector<std::pair<int,int>> moves = copy_avaliable_moves(state);
        score += moves.size()*10;
        score += state->blackScore();
        
        int width = state->board().width();
        int height = state->board().height();

        if(state->board().cellAt(0,0) == OthelloCell::black)
        {score += 1000;}
        if(state->board().cellAt(width-1,0) == OthelloCell::black)
        {score += 1000;}
        if(state->board().cellAt(0,height-1) == OthelloCell::black)
        {score += 1000;}
        if(state->board().cellAt(width-1,height-1) == OthelloCell::black)
        {score += 1000;}

        if(state->board().cellAt(0,0) == OthelloCell::empty)
        {
            if(state->board().cellAt(0,1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(0,1) == OthelloCell::white) score += 333;
            if(state->board().cellAt(1,0) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(1,0) == OthelloCell::white) score += 333;
            if(state->board().cellAt(1,1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(1,1) == OthelloCell::white) score += 333;
        }
        if(state->board().cellAt(width-1,0) == OthelloCell::empty)
        {
            if(state->board().cellAt(width-1,1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-1,1) == OthelloCell::white) score += 333;
            if(state->board().cellAt(width-2,0) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-2,0) == OthelloCell::white) score += 333;
            if(state->board().cellAt(width-2,1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-2,1) == OthelloCell::white) score += 333;
        }
        if(state->board().cellAt(width-1,height-1) == OthelloCell::empty)
        {
            if(state->board().cellAt(width-2,height-1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-2,height-1) == OthelloCell::white) score += 333;
            if(state->board().cellAt(width-1,height-2) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-1,height-2) == OthelloCell::white) score += 333;
            if(state->board().cellAt(width-2,height-2) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(width-2,height-2) == OthelloCell::white) score += 333;
        }
        if(state->board().cellAt(0,height-1) == OthelloCell::empty)
        {
            if(state->board().cellAt(1,height-1) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(1,height-1) == OthelloCell::white) score += 333;
            if(state->board().cellAt(0,height-2) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(0,height-2) == OthelloCell::white) score += 333;
            if(state->board().cellAt(1,height-2) == OthelloCell::black) score -= 333;
            else if(state->board().cellAt(1,height-2) == OthelloCell::white) score += 333;
        }
    }
    else
    {
        std::vector<std::pair<int,int>> moves = copy_avaliable_moves(state);
        score += moves.size()*10;
        score += state->whiteScore();

        int width = state->board().width();
        int height = state->board().height();

        if(state->board().cellAt(0,0) == OthelloCell::white)
        {score += 1000;}
        if(state->board().cellAt(width-1,0) == OthelloCell::white)
        {score += 1000;}
        if(state->board().cellAt(0,height-1) == OthelloCell::white)
        {score += 1000;}
        if(state->board().cellAt(width-1,height-1) == OthelloCell::white)
        {score += 1000;}

        if(state->board().cellAt(0,0) == OthelloCell::empty)
        {
            if(state->board().cellAt(0,1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(0,1) == OthelloCell::black) score += 333;
            if(state->board().cellAt(1,0) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(1,0) == OthelloCell::black) score += 333;
            if(state->board().cellAt(1,1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(1,1) == OthelloCell::black) score += 333;
        }
        if(state->board().cellAt(width-1,0) == OthelloCell::empty)
        {
            if(state->board().cellAt(width-1,1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-1,1) == OthelloCell::black) score += 333;
            if(state->board().cellAt(width-2,0) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-2,0) == OthelloCell::black) score += 333;
            if(state->board().cellAt(width-2,1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-2,1) == OthelloCell::black) score += 333;
        }
        if(state->board().cellAt(width-1,height-1) == OthelloCell::empty)
        {
            if(state->board().cellAt(width-2,height-1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-2,height-1) == OthelloCell::black) score += 333;
            if(state->board().cellAt(width-1,height-2) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-1,height-2) == OthelloCell::black) score += 333;
            if(state->board().cellAt(width-2,height-2) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(width-2,height-2) == OthelloCell::black) score += 333;
        }
        if(state->board().cellAt(0,height-1) == OthelloCell::empty)
        {
            if(state->board().cellAt(1,height-1) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(1,height-1) == OthelloCell::black) score += 333;
            if(state->board().cellAt(0,height-2) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(0,height-2) == OthelloCell::black) score += 333;
            if(state->board().cellAt(1,height-2) == OthelloCell::white) score -= 333;
            else if(state->board().cellAt(1,height-2) == OthelloCell::black) score += 333;
        }

    }
    return score;
} 


int tianzhh::StevenAI::search(std::unique_ptr<OthelloGameState>& state,int depth,int turn)
{
    int my_s = -999999;
    int op_s = 999999;

    std::vector<std::pair<int,int>> moves = copy_avaliable_moves(state);
    int ava_sz = moves.size();
    int temp_score;

    if(depth == 0 || state->isGameOver())
    {
        return eval(state,turn);
    }
    else
    {
        if((state->isBlackTurn()&& turn == 1)||(state->isWhiteTurn()&&turn == 0))
        {
             for(int i = 0; i < ava_sz; i++)
             {
                std::unique_ptr<OthelloGameState> state_copy = state->clone();
                state_copy->makeMove(moves[i].first,moves[i].second);
                temp_score = search(state_copy,depth-1,turn);
                if(temp_score > my_s)
                {
                    my_s = temp_score;
                }
             }
             return my_s;
        }
        else
        {
            for(int i = 0; i < ava_sz; i++)
            {
                std::unique_ptr<OthelloGameState> state_copy = state->clone();
                state_copy->makeMove(moves[i].first,moves[i].second);
                temp_score = search(state_copy,depth-1,turn);
                if(temp_score < op_s)
                {
                    op_s = temp_score;
                }
            }
            return op_s;
        }
    }
}


std::pair<int,int> tianzhh::StevenAI::chooseMove(const OthelloGameState& state)
{
    int turn;
    if(state.isBlackTurn())
    {
        turn = 1;
    }
    else
    {
        turn = 0;
    }

    int max_s = -1000;
    int temp_s;
    std::pair<int,int> chosen_move;
    std::vector<std::pair<int,int>> moves = curr_avaliable_moves(state);
    int move_sz = moves.size();

    for(int i = 0; i < move_sz; i++)
    {
        std::unique_ptr<OthelloGameState> state_copy = state.clone();
        state_copy->makeMove(moves[i].first,moves[i].second);
        temp_s = search(state_copy,3,turn);
        if(temp_s > max_s)
        {
            chosen_move.first = moves[i].first;
            chosen_move.second = moves[i].second;
            max_s = temp_s;
        }
    }
    return chosen_move;
}
