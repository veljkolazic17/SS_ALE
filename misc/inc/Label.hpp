#include <string>

class Label{

  public:
    Label(std::string label);
    Label();
    std::string getLabel();

  private:
    std::string label;
};