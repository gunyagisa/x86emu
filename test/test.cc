#include <iostream>

class Test {
    private:
        int list[10];

    public:
        Test() : list{0}
        {}

        void show()
        {
            for (int i = 0;i < 10;++i) {
                std::cout << list[i] << std::endl;
            }
        }
};

int main()
{
    Test test;

    test.show();
}
