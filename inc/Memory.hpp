#define MMAPREG 0xFF00

class Memory{

    public:
        Memory();
        char& operator[](short);

    private:
        char* memory;


};
