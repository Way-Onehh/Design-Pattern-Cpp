#pragma once
namespace 设计模式
{
	class 策略模式
	{
	private:

	public:
		class Strategy 
		{
		public:
			virtual void fun() = 0;
		};
		class StrategyA : public Strategy
		{
		public:
			virtual void fun() override { cout << "StrategyA\n"; }
		};
		class StrategyB : public Strategy
		{
		public:
			virtual void fun() override { cout << "StrategyB\n"; }
		};
		class context 
		{ 
		public:
			void usefun(Strategy * _st)
			{
				cout << "使用了";
				(*_st).fun();
			}
		};
		
	public: 
		static int main() 
		{
			context a;
			StrategyA b;
			StrategyB c;
			a.usefun(&b);
			a.usefun(&c);
			return 0;
		}
	};
}

