#ifndef LEVEL4_H
#define LEVEL4_H
#include "level.h"

class Level4: public Level {
    private:
        std::vector<char> blockSequence;
        int currentBlock;
        bool isRandom;
    public:
        Level4(std::string &seqfile);
        void readSeqFile(std::string &seqfile);
        std::shared_ptr<Block> createBlock() override;
        //getter
        std::vector<char> getSequence() const { return blockSequence; }
        int getCurrent() const { return currentBlock; }
        bool getRandom() const { return isRandom; }
        //setter
        void setSequence(std::vector<char> seq) { blockSequence = seq; }
        void setCurrent(int i) { currentBlock = i; }
        void makeRandom() override { isRandom = true; }
        void removeRandom(std::string file) override { isRandom = false, readSeqFile(file), currentBlock = 0;}
};

#endif
