#include <stdio.h>
#include <string.h>

int set_num_arr(int num[])
{
    int size;
    int i;

    scanf("%d", &size);
    i = 0;
    while (i < size)
        scanf("%d", &(num[i++]));
    return (size);
}

void    print(int num[], int size)
{
    while (size-- > 0)
        printf("%d\n", *num++);
}

int tmp[1000000] = {0,};

int *merge(int *tmp1, int *tmp2, int t1_size, int t2_size)
{
    
    int i;
    int j;
    int k;

    i = j = k = 0;
    while (j < t1_size && k < t2_size)
    {
        if (tmp1[j] <= tmp2[k])
            tmp[i++] = tmp1[j++];
        else
            tmp[i++] = tmp2[k++];        
    }
    while (j < t1_size)
        tmp[i++] = tmp1[j++];
    while (k < t2_size)
        tmp[i++] = tmp2[k++];
    i = 0;
    while (i < t1_size + t2_size)
    {
        tmp1[i] = tmp[i];
        i++;
    }
    return (tmp1);
}

int *merge_sort(int *num, int size)
{
    int mid;
    int *tmp1;
    int *tmp2;

    if (size > 1)
    {
        mid = size / 2;
        tmp1 = merge_sort(num, mid);
        tmp2 = merge_sort(num + mid, size - mid);
        num = merge(tmp1, tmp2, mid, size - mid);
    }
    return (num);
}


/*
    copilot 가 순수하게 만든 quick sort

    2751 백준 타임 아웃.

    코 파일럿이 만사 능통은 아님.

    내가 짠 퀵 소트도 통과 못하긴 했음.
*/
int *quick_sort(int *num, int size)
{
    int i;
    int j;
    int pivot;
    int tmp;

    if (size > 1)
    {
        i = -1;
        j = size;
        pivot = num[size / 2];
        while (1)
        {
            while (num[++i] < pivot);
            while (num[--j] > pivot);
            if (i >= j)
                break ;
            tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
        }
        quick_sort(num, i);
        quick_sort(num + i, size - i);
    }
    return (num);
}

/*

아래는 내가 짠  퀵 소트.


# [정렬] 퀵 소트

# 퀵소트

분할 정복 방법 사용.

피봇 보다 작은 값은 왼쪽, 피봇보다 큰값은 오른쪽으로 이동시킨다.

피봇의 위치를 작은 값들과 큰 값들 사이에 위치해준다.  

피봇을 기준으로 왼쪽과 오른쪽으로 나눈다.

각각 위의 방법을 반복해준다.

피봇이 하나가되면 정렬된것.

```c
#include <stdio.h>

int	partition(int *arr, int low, int high)
{
	int pivot = low++;
	int	tmp;
	while (low < high)
	{
		while (low < high && arr[low] <= arr[pivot])
			low++;
		while (low < high && arr[high] >= arr[pivot])
			high--;
		if (low < high)
		{
			tmp = arr[low];
			arr[low] = arr[high];
			arr[high] = tmp;
		}
	}
	if (arr[pivot] > arr[high])
	{
		tmp = arr[pivot];
		arr[pivot] = arr[high];
		arr[high] = tmp;
		pivot = high;
	}
	return (pivot);
}

void	quick_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort(arr, 0, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int	arr[n];
	int i = 0;
	while (i < n)
	{
		scanf("%d", arr + i);
		i++;	
	}
	quick_sort(arr, 0, n - 1);
	i = 0;
	while (i < n)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}
*/

int main(int argc, char *argv[])
{
    int size;
    int num[1000000] = {0,};

    //get num
    size = set_num_arr(num);
    //sort num
    quick_sort(num, size);
    //print num
    print(num, size);
    return (0); 
}