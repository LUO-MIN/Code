//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//�ҳ����������֣����ʵ��
#include <stdio.h>
void Diff_num(int *arr, int sz, int *px, int *py)
{
	//�����������
	int num = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//�ҵ�num�Ķ�����λ��1��λ��
	for (i = 0; i < 32; i++)
	{
		if (((num >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	//����posλΪ1����0����
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			*px ^= arr[i];
		}
		else
		{
			*py ^= arr[i];
		}
	}
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	int n1 = 0;
	int n2 = 0;
	Diff_num(arr, sz, &n1, &n2);
	printf("%d  %d\n", n1, n2);
	return 0;
}

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
#include <stdio.h>

int main()
{
	int money = 0;
	scanf("%d", &money);
	int empty = 0;
	int drink = 0;
	empty = money;
	drink = money;

	while (empty >= 2)
	{
		drink = drink + empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("drink = %d\n", drink);
}

//ģ��ʵ��strcpy
#include <stdio.h>
#include <string.h>
#include <assert.h>

void my_strcpy(char *dest, const char *src)
{
	
	assert(*dest != NULL);//����
	assert(*src != NULL);
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
}
int main()
{
	char arr[20] = { 'x', 'x', 'x', 'x', 'x', 'x' };
	char arr1[] = { 'a', 'b', 'c', '\0' };
	my_strcpy(arr, arr1);
	printf("%s\n", arr);
	return 0;
}

//ģ��strcat
#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
   char *ret = dest;
   assert(dest!= NULL);
   assert(src != NULL);
   while (*dest)
   {
        dest++;
   }
   while ((*dest++ = *src++))
   {
        ;
   }
   return ret;
}
int main()
{
   char a[] = "hello ";
   char b[] = "girl";
   printf("%s\n", my_strcat(a,b));
   return 0;
}


//ģ��ʵ��strcpy����
#include <stdio.h>
#include <string.h>
#include <assert.h>

void my_strcpy(char *dest, const char *src)
{
	
	assert(*dest != NULL);//����
	assert(*src != NULL);
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
}
int main()
{
	char arr[20] = { 'x', 'x', 'x', 'x', 'x', 'x' };
	char arr1[] = { 'a', 'b', 'c', '\0' };
	my_strcpy(arr, arr1);
	printf("%s\n", arr);
	return 0;
}


//ģ��strcat
#include <stdio.h>
#include <assert.h>
char* my_strcat(char* dest, const char* src)
{
   char *ret = dest;
   assert(dest!= NULL);
   assert(src != NULL);
   while (*dest)
   {
        dest++;
   }
   while ((*dest++ = *src++))
   {
        ;
   }
   return ret;
}
int main()
{
   char a[] = "hello ";
   char b[] = "girl";
   printf("%s\n", my_strcat(a,b));
   return 0;
}




//ģ��strstr
#include <stdio.h>
#include <assert.h>
char* my_strstr(const char* str1, const char* str2)
{
   assert(str1);
   assert(str2);
   char *p = (char*)str1;
   char *substr = (char*)str2;
   char *s1 = NULL;

   if (*str2 == '\0')
        return NULL;

   while (*p)
   {
        s1 = p;
        substr = str2;
        while (*s1 &&  *substr && (*s1 == *substr))
        {
            s1++;
            substr++;
        }
        if (*substr == '\0')
            return p;
        p++;
   }
}

int main()
{
   char a[] = "i like apple and orange";
   char b[] = "apple";
   printf("%s\n", my_strstr(a, b));
   return 0;
}



//ģ��strcmp
#include <stdio.h>

int my_strcmp(const char* src, const char* dest)
{
   int ret = 0;
   while (!(ret = *(unsigned char *)src - *(unsigned char *)dest)&& *dest)//ǿ������ת��
   
        ++src,
        ++dest;
        if (ret < 0)
        {
            ret = -1;
        }
        else if (ret > 0)
        {
            ret = 1;
        }
        return (ret);
   
}
int main()
{
   char a[] = "ilikeapple";
   char b[] = "ilike";

   printf("%d\n", my_strcmp(a, b));
   return 0;
}


//ģ��memcpy
#include <stdio.h>

void* my_memcpy(void * dst, const void *src, size_t count)
{
   void *ret = dst;
   while (count--)
   {
        *(char *)dst = *(char *)src;
        dst = (char *)dst + 1;
        src = (char *)src + 1;
   }
   return (ret);
}
int main()
{
   char a[] = "xxxxxxxxxx";
   char b[] = "girl";
   int count = 2;
   printf("%s\n", my_memcpy(a, b,count));
}


//ģ��memmove
#include <stdio.h>
#include <assert.h>
void* my_memmove(void* dst, const void* src, size_t count)
{
   void *ret = dst;
   if (dst <= src || (char*)dst >= ((char*)src + count))
   {
        while (count--)
        {
            *(char*)dst = *(char*)src;
            dst = (char*)dst + 1;
            src = (char*)src + 1;
        }
   }
   else
   {
        dst = (char*)dst +count+ 1;
        src = (char*)src +count+ 1;

        while (count--)
        {
            *(char*)dst = *(char*)src;
            dst = (char*)dst - 1;
            src = (char*)src - 1;
        }
   }
   return (ret);
}
int main()
{
   char a[] = "abcdefgh";
   char b[] = "like";
   int count = 3;
   printf("%s\n", my_memmove(a, b,count));
   return 0;
}

//ģ��strchr
#include <stdio.h>
#include <assert.h>
int my_strchr(const char* str, char k)
{
	assert(str != NULL);
	while (*str)
	{
		if (*str == k)
		{
			return str;
		}
		else
		{
			str++;
		}
	}
	return NULL;
}
int main()
{
	char arr[] = "i like orange";
	char ch = 'k';
    my_strchr(arr, ch);
	printf("%s\n", my_strchr(arr, ch));
	return 0;
	
}