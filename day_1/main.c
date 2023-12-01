#include "libft.h"

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int read_number(char *str){
	char *number = "0123456789";
	int len = strlen(str);
	int	first_number;
	int	last_number;
	int result;
	
	for (int i = 0; i < len; i++){
		if (ft_strnstr(str, "one", i)){
			first_number = 1;
			break;
		}
		if (ft_strnstr(str, "two", i)){
			first_number = 2;
			break;
		}
		if (ft_strnstr(str, "three", i)){
			first_number = 3;
			break;
		}
		if (ft_strnstr(str, "four", i)){
			first_number = 4;
			break;
		}
		if (ft_strnstr(str, "five", i)){
			first_number = 5;
			break;
		}
		if (ft_strnstr(str, "six", i)){
			first_number = 6;
			break;
		}
		if (ft_strnstr(str, "seven", i)){
			first_number = 7;
			break;
		}
		if (ft_strnstr(str, "eight", i)){
			first_number = 8;
			break;
		}
		if (ft_strnstr(str, "nine", i)){
			first_number = 9;
			break;
		}
		if (str[i] >= '0' && str[i] <= '9'){
			first_number = str[i] - 48;
			break;
		}
	}
	strrev(str);
	if (str[0] == '\n')
		str++;
	for (int i = 0; i < len; i++){
		if (ft_strnstr(str, "eno", i)){
			last_number = 1;
			break;
		}
		if (ft_strnstr(str, "owt", i)){
			last_number = 2;
			break;
		}
		if (ft_strnstr(str, "eerht", i)){
			last_number = 3;
			break;
		}
		if (ft_strnstr(str, "ruof", i)){
			last_number = 4;
			break;
		}
		if (ft_strnstr(str, "evif", i)){
			last_number = 5;
			break;
		}
		if (ft_strnstr(str, "xis", i)){
			last_number = 6;
			break;
		}
		if (ft_strnstr(str, "neves", i)){
			last_number = 7;
			break;
		}
		if (ft_strnstr(str, "thgie", i)){
			last_number = 8;
			break;
		}
		if (ft_strnstr(str, "enin", i)){
			last_number = 9;
			break;
		}
		if (str[i] >= '0' && str[i] <= '9'){
			last_number = str[i] - 48;
			break;
		}
	}
	result = (first_number * 10) + last_number;
	return (result);
}

int main(int ac, char **av){
	int fd = open("input.txt", O_RDONLY);
	char *str;
	unsigned long long n = 0;
	unsigned long long sum = 0;
	for (int i = 0; i < 1000; i++){
		str = get_next_line(fd);
		n = read_number(str);
		sum += n;
		printf("%lli\n", n);
	}
	printf("The sum is: %lli\n", sum);
	close (fd);
}