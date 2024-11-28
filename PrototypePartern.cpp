//当直接创建对象的代价比较大时，则采用这种模式
//eg unity 对象 不用重复模拟直接可以克隆

#include <cstdio>
class CloneInterface
{
public:
    virtual CloneInterface* clone()=0;
};

class ClassA : public CloneInterface
{
    int number;
public: 
    ClassA(int num):number(num) 
    {
    
    }
    CloneInterface * clone() override
    {
        return new ClassA(this->number);
    }  
    void print()
    {
        printf("this is ClassA's instance %d %p\n",number ,this);
    }

};


int main()
{
    ClassA a(1);
    ClassA *b=dynamic_cast<ClassA *>(a.clone());
    a.print();
    b->print();
    return 0;
}
