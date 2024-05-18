#pragma once
namespace 设计模式 
{
	//观察者模式/发布订阅模式/事件模式
	class 观察者模式 
	{
	private:
		class 观察者
		{
		public:
			virtual void handlnotify() = 0;
		};
		class 被观察者
		{
		protected:
			vector<观察者*> 观察者list;
		public:
			void add观察者(观察者* new观察者)
			{
				观察者list.push_back(new观察者);
			}
			void move观察者(观察者* new观察者)
			{
				size_t i = 0;
				for (观察者* it : 观察者list) 
				{
					if (it == new观察者) 
					{
						观察者list.erase(观察者list.begin() + i);		
					}
					i++;
				}
			}
			virtual void notify() = 0;
		
		};
	public:
		class a :public 被观察者
		{
		public:
			void notify() override 
			{
				if (观察者list.empty()) 
				{
					cout << "没有观察者\n";
				}
				for (auto e : 观察者list) 
				{
					e->handlnotify();
				}
			}
		};
		
		class b :public 观察者
		{
		private:
			size_t id;
			static size_t total;
		public:
			
			b() { id = ++total; }
			b(size_t _id) { id = _id; }
			void handlnotify() override 
			{
				cout << "id "<<id << "知道了\n";
			}
		};
		
		static void main() 
		{
		a a;
		b b1;
		b b2;
		a.add观察者(&b1);
		a.add观察者(&b2);
		a.notify();
		a.move观察者(&b1);
		a.notify();
		a.move观察者(&b2);
		a.notify();
		}
	};
	//静态成员要定义一下
	size_t 观察者模式::b::total = 0;
}