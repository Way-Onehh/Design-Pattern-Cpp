//单列模式（构造线程安全，调用还是不安全的）
//隐藏构造函数


#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <memory>
#include <mutex>

class SingletonPattern
{
private:
    SingletonPattern(){}
    ~SingletonPattern() {} // 私有析构函数，防止外部删除
public:
    //检查是否是同一个
    void _print()
    {
        printf("The instance address is %p\n",this);
    }
    //正常接口
    static void print()
    {
        printf("hello world\n");
    }
    friend SingletonPattern* GetInstance();
    friend class std::default_delete<SingletonPattern>;
};

SingletonPattern* GetInstance()
{
    static std::unique_ptr<SingletonPattern> ptr;
   
    static std::once_flag OnceFlag;
    std::call_once
    (
        OnceFlag,
        [](std::unique_ptr<SingletonPattern> &_ptr)
        { 
        _ptr.reset(new SingletonPattern());
        },
        std::ref(ptr)
    );

    return &(*ptr);
}

int main()
{
    /* auto ptr=GetInstance(); */
    /* ptr->_print(); */
    /* ptr=GetInstance(); */
    /* ptr->_print(); */
    GetInstance()->print();
    return 0;
}


