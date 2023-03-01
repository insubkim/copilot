#include <stdio.h>



/*
    코파일럿 사용법

    Extentions  copilot 검색

    깃 허브로 코파일럿 연동 

    vscode 하단 코파일럿 로고 클릭으로 (비)활성화 선택

    ctrl + enter 로 코드 만들기

    accept solution 클릭 클락

*/

void    print_copilot(void)
{
    printf("copilot\n");
}


void    print_hello_world(void)
{
    printf("Hello World\n");
}


int add_arr(int *arr, int size)
{
    int i;
    int sum;

    i = 0;
    sum = 0;
    while (i < size)
    {
        sum += arr[i];
        i++;
    }
    return (sum);
}

typedef struct  s_list
{
    int             data;
    struct s_list   *next;
}               t_list;

int add_list(t_list *list)
{
    int sum;

    sum = 0;
    while (list)
    {
        sum += list->data;
        list = list->next;
    }
    return (sum);
}



int main()
{
    print_hello_world();
    return (0);
}
