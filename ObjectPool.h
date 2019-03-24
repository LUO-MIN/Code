//�����
#pragma once

template<class T,size_t N_OBJ = 20>
class ObjectPool
{
public:
	ObjectPool() = default;//��ȱʡ�ĳ�ʼ��
	ObjectPool(const ObjectPool<T>&) = delete;//�������������ͬһ���ڴ������⣬����Ҫ������
	ObjectPool<T>& operator=(const ObjectPool<T>&) = delete;//��ֵ����ҲҪ����
	//�ڴ��ʵ�����ڴ��Ĺ���
	template<class INIT_T>//��ģ��ĳ�Ա����   Ҳ����д�ɺ���ģ��
	T* New(const INIT_T& x)
	{
		T* obj = nullptr;
		if (_freelist != nullptr)//ͷ��
		{
			//void* next = (void*)(*((int*)_freelist));
			//����64λƽ̨8���ֽ�ָ������Ӧд��
			void* next=*((void**)_freelist);
			obj = (T*)_freelist;
			_freelist = next;
		}
		else
		{
			if (_start == _finish)//˵�����ڴ�
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

	void Delete(T* ptr)//ͷɾ
	{
		ptr->~T();//��ʾ���ù���    T��string���������������������ڴ�й¶

		*(void**)ptr = _freelist;
		_freelist = ptr;
	}
	
private:
	char* _start = nullptr;//��char* +1����һ���ֽ�
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

	std::string* p3 = pool.New("3333");//��ʱp3,p4ʹ�õ��ڴ���p1,p2�ջ�������
	std::string* p4 = pool.New("4444");
	std::string* p5 = pool.New("5555");
	



}