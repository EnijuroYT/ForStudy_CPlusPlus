/*Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
	-состоять из символов таблицы ASCII с кодами от 33 до 126;
	-быть не короче 8 символов и не длиннее 14;
	-из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.*/

#include <iostream>
#include <string>

int main()
{
	int big = 0, small = 0, num = 0, other = 0;
	std::string pas;
	std::cin >> pas;
	bool flag = 0, badflag = 0;
	int pasSize = pas.size();
	if (pasSize > 7 && pasSize < 15) {
		for (auto sym : pas) {
			if (sym < 33 || sym >126)
			{
				badflag = 1;
				break;
			}
			if (sym > 64 && sym < 91) { big = 1; }
			else if (sym > 96 && sym < 123) { small = 1; }
			else if (sym > 47 && sym < 58) { num = 1; }
			else { other = 1; }

			if ((big + small + num + other) > 2) {
				flag = 1;
				break;
			}
		}
		if (badflag == 0 && flag == 1) {
			std::cout << "YES";
		}
		else { std::cout << "NO"; }

	}
	else {
		std::cout << "NO";
	}
}