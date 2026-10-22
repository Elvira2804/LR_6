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

	/*
	* Контрольный пример для проверки:
	* input: 2018 output: "год 2018 не високосный"
	*/

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
	double res_1;
	double res_2;

	/*
	* Контрольный пример для проверки:
	* 1) При x = 5 (x <= 7): F(5) = 3 * 5 - 9 = 6.000000
	* 2) При x = 8 (x > 7):  F(8) = 1 / (8^2 - 4) = 1 / 60 = 0.016667
	*/

	printf("Введите x: ");
	if (scanf("%lf", &x) != 1) {
		printf("Ошибка: введено некорректное значение x!\n");
		return 1;
	}

	res_1 = z_2_1(x);
	res_2 = z_2_2(x);

	//Если x <= 7, тернарный оператор выбирает результат первой ветки (res_1), иначе — второй (res_2)
	printf("F(x) = %lf\n", (x <= 7) ? res_1 : res_2);

	//Задание 3
	printf("\nЗАДАНИЕ 3\n");

	int d3, m3, y3, user_choice;

	/*
	* Контрольный пример для проверки:
	* До конца года (високосный): Дата 30.12.2024 (всего 366 дней). Осталось: 1 день.
	* До конца года (обычный): Дата 30.12.2026 (всего 365 дней). Осталось: 1 день.
	*/

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

	//Количество дней в текущем месяце
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

	//Количество дней до конца месяца
	int days_till_month_end = month_days - day;

	if (user_choice == 1) {
		return days_till_month_end;
	}

	//Количество дней до конца года
	int future_months_days = 0;
	int is_leap = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)); //Определяем исокосный год или нет

	//Проверяем, сколько дней нужно добавить в зависимости от текущего месяца
	if (month == 1)  future_months_days = is_leap ? 335 : 334; //Если сейчас январь
	else if (month == 2)  future_months_days = 306; //Если сейчас февраль
	else if (month == 3)  future_months_days = 275; //Если сейчас март
	else if (month == 4)  future_months_days = 245; //Если сейчас апрель
	else if (month == 5)  future_months_days = 214; //Если сейчас май
	else if (month == 6)  future_months_days = 184; //Если сейчас июнь
	else if (month == 7)  future_months_days = 153; //Если сейчас июль
	else if (month == 8)  future_months_days = 122; //Если сейчас август
	else if (month == 9)  future_months_days = 92;  //Если сейчас сентябрь
	else if (month == 10) future_months_days = 61;  //Если сейчас октябрь
	else if (month == 11) future_months_days = 31;  //Если сейчас ноябрь
	else if (month == 12) future_months_days = 0;   //Если сейчас декабрь

	return days_till_month_end + future_months_days;
}