//建造者模式强调建造
//指挥者        指挥那个具体的建造者(F)什么时候去构造
//抽象建造者    多态
//具体建造者    具体的构造者 F
//产品          当然你也可以加一个接口这里省略掉了

//比抽象工厂多了一个指挥者，还把构造步骤也给规定好了
//具体工厂是一步到位是抽象工厂的升级版
//-----
//auto Fptr=new concreteFactory
//
//----
//
//

#include <cstdio>
class ClassA
{
public:
    void print()
    {
        printf("num: %d , size: %d\n",num,size);
    }
//正常情况下这里要写成字段
    int num;
    int size;
};

class AbstractBuider
{
public:
    virtual void BuildPartA()=0;
    virtual void BuildPartB()=0;
    virtual ClassA* GetProduct()=0;
};

class concreteBuider1:public AbstractBuider
{
    ClassA * product;
public:   
    void BuildPartA() override
    {
       product = new ClassA;
    }
    void BuildPartB() override
    {
       product->num=1;
       product->size=2;
    }
    ClassA* GetProduct() override
    {
        printf("build success\n");
        return product;
    }
    ~concreteBuider1()
    {
        delete product;
    }
};
class concreteBuider2:public AbstractBuider
{
    ClassA * product;
public:   
    void BuildPartA() override
    {
       product = new ClassA;
    }
    void BuildPartB() override
    {
       product->num=1;
       product->size=1000;
    }
    ClassA* GetProduct() override
    {
        printf("build success\n");
        return product;
    }

    ~concreteBuider2()
    {
        delete product;
    }
};

class Director
{
public:
    void construct(AbstractBuider* builder)
    {
        printf("start to build\n");
        builder->BuildPartA();
        builder->BuildPartB();
    }
};

int main()
{
    Director Drt;
    concreteBuider1 Cbd1;
    concreteBuider2 Cbd2;

    Drt.construct(&Cbd1);
    Drt.construct(&Cbd2);
    
    Cbd1.GetProduct()->print();
    Cbd2.GetProduct()->print();
}
