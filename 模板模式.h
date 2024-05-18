#pragma once
namespace 设计模式
{
class 模板模式 
{
private:
	class 模板 
	{
	private:
		void 步骤1() 
		{
			cout << "模板:步骤1()  \n";
		}
		void 步骤3()
		{
			cout << "模板:步骤3()  \n";
		}
		void 步骤5()
		{
			cout << "模板:步骤4()  \n";
		}
		virtual void 步骤2() = 0;
		virtual void 步骤4() = 0;
	public:
		void run() 
		{
			步骤1();
			步骤2();
			步骤3();
			步骤4();
			步骤5();
		}
	};
public:	

 	class 具体流程1 :public 模板
	{
		void 步骤2() final 
		{
			cout<< "具体流程1:步骤2() \n";
		}

		void 步骤4() final
		{
			cout << "具体流程1:步骤4()  \n";
		}
	};
};
}