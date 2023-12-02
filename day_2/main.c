#include "libft.h"

/*

	POSSIBLE GAMES IF THE BAG HAS:
	12 red
	13 green
	14 blue


	After ":" and before ";" the sum of numbers followed by: 
	red <= 12
	green <= 13
	blue <= 14

*/

int search_string_1(char *str, int ID){

	int n = 0;
	int counter = 1;
	int red = 0;
	int green = 0;
	int blue = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ';')
			counter++;
	}
	while (*str){
		if (*str == ':'){
			break;
		}
		str++;
	}
	//printf("Sections %i, ", counter);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			n = *str - 48;
			str++;
			if (*str != ' '){
				n = (n * 10) + (*str - 48);
			}
			str++;
			if (strnstr(str, "red", 6))
				red += n;
			if (strnstr(str, "green", 6))
				green += n;
			if (strnstr(str, "blue", 6))
				blue += n;
		}
		if (*str == ';' || counter == 1)
		{
			if ((red > 12 || green > 13 || blue > 14)){
				// printf("Invalid ");
				return (0);
			}
			else
			{
				red = 0;
				green = 0;
				blue = 0;
				counter--;
			}
		}
		str++;
	}
	if (counter == 0 && (red > 12 || green > 13 || blue > 14)) {
		// printf("Invalid ");
		return (0);
	}
	//printf("Game %i was valid\n", ID);
	return (ID);
}

int search_string_2(char *str, int ID){

	int n = 0;
	int counter = 1;
	int red = 0;
	int green = 0;
	int blue = 0;

	int cur_red = 1;
	int cur_green = 1;
	int cur_blue = 1;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ';')
			counter++;
	}
	while (*str){
		if (*str == ':'){
			break;
		}
		str++;
	}
	//printf("Sections %i, ", counter);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			n = *str - 48;
			str++;
			if (*str != ' '){
				n = (n * 10) + (*str - 48);
			}
			str++;
			if (strnstr(str, "red", 6))
				red += n;
			if (strnstr(str, "green", 6))
				green += n;
			if (strnstr(str, "blue", 6))
				blue += n;
		}
		if (*str == ';' || counter == 1)
		{
			if (cur_red < red)
				cur_red = red;
			if (cur_green < green)
				cur_green = green;
			if (cur_blue < blue)
				cur_blue = blue;
			red = 0;
			green = 0;
			blue = 0;
			counter--;
		}
		str++;
	}
	if (cur_red < red)
		cur_red = red;
	if (cur_green < green)
		cur_green = green;
	if (cur_blue < blue)
		cur_blue = blue;
	// printf("Red: %i\nGreen: %i\nBlue: %i\n", cur_red, cur_green, cur_blue);
	// printf("Result: %i\n", cur_red * cur_green * cur_blue);
	return(cur_red * cur_green * cur_blue);
}

int main(int ac, char **av){
	static int ID = 0;
	int fd = open("input.txt", O_RDONLY);
	char *str;
	int sum_1 = 0;
	int sum_2 = 0;
	for (int i = 0; i < 100; i++)
	{
		str = get_next_line(fd);
		ID++;
		sum_1 += search_string_1(str, ID);
		sum_2 += search_string_2(str, ID);
		// printf("Game %i, sum: %i\n\n", ID, sum);
	}
	close(fd);
	printf("First half result -> %i\nSecond half result -> %i\n", sum_1, sum_2);
}