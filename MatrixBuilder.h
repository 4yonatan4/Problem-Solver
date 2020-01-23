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
    int rows, columns;
    State<Point*>* firstState;
    State<Point*>* goalState;
    State<Point*>* getInitialState() override;
    bool isGoalState(State<Point*>* state) override;
    vector<State<Point*>*>* getAllPossibleStates(State<Point*>* state) override;
    string toString() override;
    MatrixBuilder(vector<string>* matrix)
    {
        this->theMatrix = new vector<vector<State<Point>*>>*;
        this->rows = matrix.size() - 2;
        int i,j, count = 0;
        string line = matrix[0];
        while (line[count] != '\n')
        {
            if (line[count] == ',')
            {
                count++;
            }
        }
        this->columns = count + 2;
        for (i = 0; i < rows; i++) {
            count = 0;
            line = matrix[i];
            theMatrix->push_back(new vector<State<Point*>*>());
            for (j = 0; j < columns; j++)
            {
                string temp;
                while (line[count] != ',')
                {
                    temp+=line[count];
                    count++;
                }
                Point* point = new Point(i, j);
                auto* state = new State<Point>(point);
                state->value = stoi(temp);
                theMatrix->at(i)->push_back(state);
                count++;
            }
        }
    }

};

#endif //EX4_MATRIXBUILDER_H
