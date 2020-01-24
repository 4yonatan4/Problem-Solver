//
// Created by Efraim Paley on 1/23/20.
//

#ifndef EX4_MATRIXBUILDER_H
#define EX4_MATRIXBUILDER_H

#include <vector>
#include "Searchable.h"
#include "State.h"
using namespace std;
template <class T>
class MatrixBuilder : public Searchable<Point*>
{
public:
    vector<vector<State<Point*>*>*>* theMatrix;
    int rows, columns ,enter,exit,enterI, enterJ, exitI, exitJ;
    State<Point*>* firstState;
    State<Point*>* goalState;


    string toString() override;
    MatrixBuilder(vector<string>* matrix)
    {

        this->theMatrix = new vector<vector<State<Point> *>> *;
        this->enter = matrix->size() - 1;
        this->exit = matrix->size();
        this->rows = matrix->size() - 2;
        int i, j, count = 0;
        string line = matrix->at(0);
        while (line[count] != '\n')
        {
            if (line[count] == ',')
            {
                count++;
            }
        }
        this->columns = count + 2;
        for (i = 0; i < rows; i++)
        {
            count = 0;
            line = matrix->at(i);
            theMatrix->push_back(new vector<State<Point *> *>());
            for (j = 0; j < columns; j++)
            {
                string temp;
                while (line[count] != ',')
                {
                    temp += line[count];
                    count++;
                }
                Point *point = new Point(i, j);
                auto *state = new State<Point *>(*point);
                state->value = stoi(temp);
                theMatrix->at(i)->push_back(state);
                count++;
            }
        }
        count = 0;
        string enterLine = matrix->at(enter);
        string temp;
        bool foundComma = false;
        for (int i = 0; i < exit.length(); i++)
        {
            while (!foundComma)
            {
                while (enterLine[count] != ',')
                {
                    temp += enterLine[count];
                    count++;
                }
                enterI = stoi(temp);
                foundComma = true;
            }
            count++;
            temp = "";
            temp += enterLine[count];
        }
        enterJ = stoi(temp);
        Point *entrancePoint = new Point(enterI, enterJ);
        this->firstState = new State<Point *>(*entrancePoint);

        count = 0;
        string exitLine = matrix->at(exit);
        string temp2;
        foundComma = false;
        for (int i = 0; i < exitLine.length(); i++)
        {
            while (!foundComma)
            {
                while (exitLine[count] != ',')
                {
                    temp2 += exitLine[count];
                    count++;
                }
                exitI = stoi(temp2);
                foundComma = true;
            }
            count++;
            temp2 = "";
            temp2 += exitLine[count];
        }
        exitJ = stoi(temp2);
        auto *exitPoint = new Point(exitI, exitJ);
        this->goalState = new State<Point*>(*exitPoint);
    }


    State<Point*>* getInitialState() override
    {
        return this->firstState;
    }

//    State<Point*>* getGoalState()
//    {
//        return this->goalState;
//    }
    bool isGoalState(State<Point*>* state) override
    {
        return state->equals(goalState);
    }
    vector<State<Point*>>* getAllPossibleStates(State<Point*>* state) override
    {
        vector<State<Point*>>* possibleStatesVector = new vector<State<Point*>>;
        //x(j)= columns
        int x = state->state->getX();
        //y(i) = rows
        int y = state->state->getY();
        //up
        if(y != 0)
        {
            if (this->theMatrix->at(y-1)->at(x)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(y-1)->at(x));
        }
        if(y != this->rows)
        {
            if (this->theMatrix->at(y+1)->at(x)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(y+1)->at(x));
        }
        if(x != 0)
        {
            if (this->theMatrix->at(y)->at(x-1)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(y)->at(x-1));
        }
        if(x != this->columns)
        {
            if (this->theMatrix->at(y)->at(x+1)->value != -1)
                possibleStatesVector->push_back(this->theMatrix->at(y)->at(x+1));
        }
        return possibleStatesVector;
    }
};

#endif //EX4_MATRIXBUILDER_H
