#include "Line.hpp"
#include <vector>

class Lines {
  public:
    Lines();

    ~Lines();

    Line* getLine(int index);
    void putLine(Line* line);
  private:
    std::vector<Line*>* lines;    
};