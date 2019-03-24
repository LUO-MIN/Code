//对象池
#pragma once

template<class T,size_t N_OBJ = 20>
class ObjectPool
{
public:
	ObjectPool() = default;//调缺省的初始化
	ObjectPool(const ObjectPool<T>&) = delete;//两个对象池申请同一块内存会出问题，所以要防拷贝
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//赋值函数也要限制
	//内存池实际是内存块的管理
	template<class INIT_T>//类模板的成员函数   也可以写成函数模板
	T* New(const INIT_T& x)
	{
		T* obj = nullptr;
		if (_freelist != nullptr)//头插
		{
			//void* next = (void*)(*((int*)_freelist));
			//兼容64位平台8个字节指针自适应写法
			void* next=*((void**)_freelist);
			obj = (T*)_freelist;
			_freelist = next;
		}
		else
		{
			if (_start == _finish)//说明有内存
			{
				_start = (char*)malloc(sizeof(T)*N_OBJ);
				_finish = _start + sizeof(T)*N_OBJ;
			}

			obj = (T*)_start;
			_start += sizeof(T);
		}
		new(obj)T(x);
		return obj;
	}

	void Delete(T* ptr)//头删
	{
		ptr->~T();//显示调用构造    T是string，不调析构函数，会有内存泄露

		*(void**)ptr = _freelist;
		_freelist = ptr;
	}
	
private:
	char* _start = nullptr;//用char* +1正好一个字节
	char* _finish = nullptr;

	void* _freelist = nullptr;

};

void TestObjectPool()
{
	ObjectPool<std::string> pool;
	std::string* p1 = pool.New("1111");
	std::string* p2 = pool.New("2222");

	pool.Delete(p1);
	pool.Delete(p2);

	std::string* p3 = pool.New("3333");//这时p3,p4使用的内存是p1,p2刚还回来的
	std::string* p4 = pool.New("4444");
	std::string* p5 = pool.New("5555");
	



}