#ifndef LEVEL_H
#define LEVEL_H


class level{

    protected:
        struct obstacle{
            char c;
            int score;
        };

        char** track;
        
        // this->prev->next = this;
        level *prev;
        level *next;

    public:
        level(int, int, level*);
        char get_Pos(int, int);

};

#endif                                       