/*工厂生产产品*/

//工厂
//接口 多态
//产品 分离点 是什么

/*abstract*/
/* i interface */
/* f Factory */
/* f DestroyInstance */
/*concrete*/
/* c classA */
/* c classB */


#include<stdio.h>

class interface
{
public:
    virtual void print()=0;
    //基类必须是虚的   
    virtual ~interface()
    {
        printf("this is interface's instance %p\n",this);
    }
};

class ClassA :public interface
{
public:
    virtual void print()
    {
        printf("this is ClassA's instance %p\n",this);
    }

    virtual ~ClassA()
    {
        printf("this is ClassA's ~ClassA %p\n",this);
    }
};

class classB :public interface
{
public:
    virtual void print()
    {
        printf("this is ClassB's instance %p\n",this);
    }
    
    virtual ~classB()
    {
        printf("this is ClassB's ~ClassA %p\n",this);
    }
};

interface*  Factory(int Typeid)
{
    interface * ptr=nullptr;
    switch(Typeid)
    {
    case 0:
        ptr = new ClassA;
        break;
    case 1:
        ptr = new classB;
        break;
    defualt:
        ptr = nullptr;        
        break;
    }
    return ptr;
}

void DestroyInstance(interface * ptr)
{
    delete ptr;
}

int main()
{
    auto ptr0 = Factory(0);
    auto ptr1 = Factory(1);
    
    ptr0->print();
    ptr1->print();

    DestroyInstance(ptr0);
    DestroyInstance(ptr1);
    return 0;
}
