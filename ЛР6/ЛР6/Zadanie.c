#include <stdio.h>
#include <locale.h>

int z_1(int year);
double z_2_1(double x);
double z_2_2(double x);
int z_3(int day, int month, int year, int user_choice);

int main() {

	setlocale(LC_CTYPE, "ru_RU.UTF-8");

	//Задание 1
	printf("ЗАДАНИЕ 1\n");

	int year;
	int result_1;

	printf("Введите год: ");
	if (scanf("%d", &year) != 1) {
		printf("Ошибка: введено не число!\n");
		return 1;
	}

	result_1 = z_1(year);

	if (result_1 == 0) {
		printf("Год %d високосный\n", year);
	}
	else
	{
		printf("Год %d не високосный\n", year);
	}

	//Задание 2
	printf("\nЗАДАНИЕ 2\n");

	double x;
	double final_res; 

	printf("Введите x: ");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка: введено некорректное значение x!\n");
		return 1;
	}

	if (x <= 7) {
		final_res = z_2_1(x); 
	}
	else {
		if (x * x - 4 == 0.0) {
			printf("Ошибка: Деление на ноль в функции F(x)!\n");
			return 1;
		}
		final_res = z_2_2(x);
	}

	printf("F(x) = %lf\n", final_res);

	//Задание 3
	printf("\nЗАДАНИЕ 3\n");

	int d3, m3, y3, user_choice;

	printf("Введите дату в формате ДД ММ ГГГГ (через пробел): ");
	scanf("%d %d %d", &d3, &m3, &y3);

	printf("Что вычислить? (1 - до конца месяца, 2 - до конца года): ");
	scanf("%d", &user_choice);

	int days_left = z_3(d3, m3, y3, user_choice);

	if (user_choice == 1) {
		printf("До конца месяца осталось дней: %d\n", days_left);
	}
	else {
		printf("До конца года осталось дней: %d\n", days_left);
	}

	return 0;
}

int z_1(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return 0;
	}
	else {
		return 1;
	}
}

double z_2_1(double x) {
	return 3 * x - 9;
}

double z_2_2(double x) {
	return 1.0 / (x * x - 4);
}

int z_3(int day, int month, int year, int user_choice) {
	int month_days;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		month_days = 30;
	}
	else if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			month_days = 29;
		}
		else {
			month_days = 28;
		}
	}
	else {
		month_days = 31;
	}

	int days_till_month_end = month_days - day;

	if (user_choice == 1) {
		return days_till_month_end;
	}

	int future_months_days = 0;
	int is_leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));

	if (month == 1)  future_months_days = is_leap ? 335 : 334;
	else if (month == 2)  future_months_days = 306;
	else if (month == 3)  future_months_days = 275;
	else if (month == 4)  future_months_days = 245;
	else if (month == 5)  future_months_days = 214;
	else if (month == 6)  future_months_days = 184;
	else if (month == 7)  future_months_days = 153;
	else if (month == 8)  future_months_days = 122;
	else if (month == 9)  future_months_days = 92;
	else if (month == 10) future_months_days = 61;
	else if (month == 11) future_months_days = 31;
	else if (month == 12) future_months_days = 0;

	return days_till_month_end + future_months_days;
}
