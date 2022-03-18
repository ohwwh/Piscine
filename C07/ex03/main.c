#include <stdio.h>
#include <stdlib.h>

extern char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *str[] = {"lol", "pouic", "1234", "youpiiiiiii"};
	char sep[4] = "1234";
	char *ret;
	// 만약 str 과 sep를 계속 쓰고 싶다면 위에서 연산할때 포인터 증가 말고 인덱스 변수를 지정해서 따로 증가시킬 것
	ret = ft_strjoin(1, str, sep);
	if (ret == 0)
		printf("오류");
	else		
		printf("%s", ret);
	free(ret);

	
	 /* 예외사항
	 size가 음수인 경우 - 널포인터 반환. 근데 왜 free가 먹히는지는 의문
	 size가 0인 경우 - freeable한 빈 배열을 할당해줌.
	 size가 원래보다 작은 경우- 그냥 그 사이즈만큼만 출력됨
	 size가 원래보다 큰 경우 - 고려 안해도 될 듯*/
	 
}
